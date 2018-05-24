
#include "resourcetree.h"


ResourceTree::ResourceTree(QWidget *pParent) : QTreeWidget(pParent) {

	setHeaderLabels({"Resource"});
	setContextMenuPolicy(Qt::CustomContextMenu);

	QObject::connect(this, &ResourceTree::customContextMenuRequested,
		this, &ResourceTree::OnCustomContextMenuRequest);
}

ResourceTree::~ResourceTree() { }

void ResourceTree::OnAddDatabaseResource(DatabaseResource *pDbResource) {

	addTopLevelItem(pDbResource);
	pDbResource->EstablishConnection();
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

	DatabaseResource *p_db_resource = static_cast<DatabaseResource *>(itemAt(pos));

	if(p_db_resource) {
		QAction *p_action = mpDbConnContextMenu->exec(this->viewport()->mapToGlobal(pos));

		if(p_action == mpConnectAction) {
			
		} else if(p_action == mpDisconnectAction) {
			
		} else if(p_action == mpNewDbAction) {
			
		} else {
			// do nothing
		}
	} 
}

void ResourceTree::ShowDatabaseContextMenu(const QPoint& pos) {

	DbrSchema *p_db_schema = static_cast<DbrSchema *>(itemAt(pos));

	if(p_db_schema) {
		QAction *p_action = mpDbrContextMenu->exec(this->viewport()->mapToGlobal(pos));

		if(p_action == mpNewTableAction) {
			
		} else if(p_action == mpDropDbAction) {
			
		} else {
			// do nothing
		}
	} 
}

void ResourceTree::ShowTableContextMenu(const QPoint& pos) {

	DbrTable *p_db_table = static_cast<DbrTable *>(itemAt(pos));

	if(p_db_table) {
		QAction *p_action = mpTrContextMenu->exec(this->viewport()->mapToGlobal(pos));

		if(p_action == mpViewTableDataAction) {
			

			if(QSqlDatabase::contains(p_db_table->ConnectionName())) {

				TableDataPage *p_new_tab = new TableDataPage(p_db_table->SchemaName(), p_db_table->TableName(),
					QSqlDatabase::database(p_db_table->ConnectionName()));


				p_new_tab->SetupUi();
				emit AddTableDataPage(p_new_tab);

			} else {
				// no such connection
			}
			
		} else if(p_action == mpDeleteTableAction) {
			
		} else {
			// do nothing
		}
	} 
}

void ResourceTree::CreateContextMenus() {

	mpDbConnContextMenu   = new QMenu(this);
	mpDbrContextMenu      = new QMenu(this);
	mpTrContextMenu       = new QMenu(this);

	// add actions
	mpConnectAction       = mpDbConnContextMenu->addAction("Connect");
	mpDisconnectAction    = mpDbConnContextMenu->addAction("Disconnect");
	mpNewDbAction         = mpDbConnContextMenu->addAction("New database");

	mpNewTableAction      = mpDbrContextMenu->addAction("New table");
	mpDropDbAction        = mpDbrContextMenu->addAction("Drop");

	mpViewTableDataAction = mpTrContextMenu->addAction("View data");
	mpDeleteTableAction   = mpTrContextMenu->addAction("Delete");
}

void ResourceTree::Style() const {

	
}