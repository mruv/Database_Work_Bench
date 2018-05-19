
#include "resourcetree.h"


ResourceTree::ResourceTree(QWidget *parent) : QTreeWidget(parent) {

	setHeaderLabels({"Resource"});
	setContextMenuPolicy(Qt::CustomContextMenu);

	QObject::connect(this, &ResourceTree::customContextMenuRequested,
		this, &ResourceTree::onCustomContextMenuRequest);
}

ResourceTree::~ResourceTree() { }

void ResourceTree::onAddDatabaseResource(DatabaseResource *dbResource) {

	addTopLevelItem(dbResource);
	dbResource->establishConnection();
}

void ResourceTree::onCustomContextMenuRequest(const QPoint& pos) {

	AbstractResource* resource = static_cast<AbstractResource *>(itemAt(pos));

        if (resource) {

        	// display appropriate context menu
        	switch(resource->resourceType()) {

        		case ResourceType::DatabaseConnection:
        		showConnectionContextMenu(pos);
        		break;

        		case ResourceType::Database:
        		showDatabaseContextMenu(pos);
        		break;

        		case ResourceType::Table:
        		showTableContextMenu(pos);
        		break;
        		
        		default:
        		std::cout << "Default\n";

        	}
        } 
}

void ResourceTree::showConnectionContextMenu(const QPoint& pos) {

	DatabaseResource *dbRsc = static_cast<DatabaseResource *>(itemAt(pos));

	if(dbRsc) {
		QAction *act = aDbConnContextMenu->exec(this->viewport()->mapToGlobal(pos));

		if(act == aConnectAction) {
			
		} else if(act == aDisconnectAction) {
			
		} else if(act == aNewDbAction) {
			
		} else {
			// do nothing
		}
	} 
}

void ResourceTree::showDatabaseContextMenu(const QPoint& pos) {

	DbrSchema *dbSchm = static_cast<DbrSchema *>(itemAt(pos));

	if(dbSchm) {
		QAction *act = aDbrContextMenu->exec(this->viewport()->mapToGlobal(pos));

		if(act == aNewTableAction) {
			
		} else if(act == aDropDbAction) {
			
		} else {
			// do nothing
		}
	} 
}

void ResourceTree::showTableContextMenu(const QPoint& pos) {

	DbrTable *dbTbl = static_cast<DbrTable *>(itemAt(pos));

	if(dbTbl) {
		QAction *act = aTrContextMenu->exec(this->viewport()->mapToGlobal(pos));

		if(act == aViewTableDataAction) {
			

			if(QSqlDatabase::contains(dbTbl->connectionName())) {
				emit addTableDataPage(
					new TableDataPage(dbTbl->schemaName(), dbTbl->tableName(), 
						QSqlDatabase::database(dbTbl->connectionName()))
					);
			} else {
				// no such connection
			}
			
		} else if(act == aDeleteTableAction) {
			
		} else {
			// do nothing
		}
	} 
}

void ResourceTree::createContextMenus() {

	aDbConnContextMenu = new QMenu(this);
	aDbrContextMenu    = new QMenu(this);
	aTrContextMenu     = new QMenu(this);

	// add actions
	aConnectAction       = aDbConnContextMenu->addAction("Connect");
	aDisconnectAction    = aDbConnContextMenu->addAction("Disconnect");
	aNewDbAction         = aDbConnContextMenu->addAction("New database");

	aNewTableAction      = aDbrContextMenu->addAction("New table");
	aDropDbAction        = aDbrContextMenu->addAction("Drop");

	aViewTableDataAction = aTrContextMenu->addAction("View data");
	aDeleteTableAction   = aTrContextMenu->addAction("Delete");
}