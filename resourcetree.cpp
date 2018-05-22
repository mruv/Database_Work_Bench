
#include "resourcetree.h"


ResourceTree::ResourceTree(QWidget *parent) : QTreeWidget(parent) {

	setHeaderLabels({"Resource"});
	setContextMenuPolicy(Qt::CustomContextMenu);

	QObject::connect(this, &ResourceTree::customContextMenuRequested,
		this, &ResourceTree::OnCustomContextMenuRequest);
}

ResourceTree::~ResourceTree() { }

void ResourceTree::OnAddDatabaseResource(DatabaseResource *dbResource) {

	addTopLevelItem(dbResource);
	dbResource->EstablishConnection();
}

void ResourceTree::OnCustomContextMenuRequest(const QPoint& pos) {

	AbstractResource* resource = static_cast<AbstractResource *>(itemAt(pos));

        if (resource) {

        	// display appropriate context menu
        	switch(resource->Type()) {

        		case ResourceType::DatabaseConnection:
        		ShowConnectionContextMenu(pos);
        		break;

        		case ResourceType::Database:
        		ShowDatabaseContextMenu(pos);
        		break;

        		case ResourceType::Table:
        		ShowTableContextMenu(pos);
        		break;
        		
        		default:
        		std::cout << "Default\n";

        	}
        } 
}

void ResourceTree::ShowConnectionContextMenu(const QPoint& pos) {

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

void ResourceTree::ShowDatabaseContextMenu(const QPoint& pos) {

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

void ResourceTree::ShowTableContextMenu(const QPoint& pos) {

	DbrTable *dbTbl = static_cast<DbrTable *>(itemAt(pos));

	if(dbTbl) {
		QAction *act = aTrContextMenu->exec(this->viewport()->mapToGlobal(pos));

		if(act == aViewTableDataAction) {
			

			if(QSqlDatabase::contains(dbTbl->ConnectionName())) {

				TableDataPage *newTab = new TableDataPage(dbTbl->SchemaName(), dbTbl->TableName(),
					QSqlDatabase::database(dbTbl->ConnectionName()));


				newTab->SetupUi();
				emit AddTableDataPage(newTab);

			} else {
				// no such connection
			}
			
		} else if(act == aDeleteTableAction) {
			
		} else {
			// do nothing
		}
	} 
}

void ResourceTree::CreateContextMenus() {

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

void ResourceTree::Style() const {

	
}