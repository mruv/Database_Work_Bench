
#include "resourcetree.h"


ResourceTree::ResourceTree(QWidget *parent) : QTreeWidget(parent) {

	setHeaderLabels({"Resource"});
	setContextMenuPolicy(Qt::CustomContextMenu);
	aTrContextMenu = new QMenu();

	QObject::connect(this, &ResourceTree::customContextMenuRequested,
		this, &ResourceTree::onCustomContextMenuRequest);
}

ResourceTree::~ResourceTree() { }

void ResourceTree::onAddDatabaseResource(DatabaseResource *dbResource) {

	addTopLevelItem(dbResource);
	dbResource->establishConnection();
}

void ResourceTree::onViewTableData() {

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
        		std::cout << "De\n";

        	}
        } 
}

void ResourceTree::showConnectionContextMenu(const QPoint& pos) {

	DatabaseResource *dbRsc = static_cast<DatabaseResource *>(itemAt(pos));

	if(dbRsc) {
		
	} 
}

void ResourceTree::showDatabaseContextMenu(const QPoint& pos) {

	DbrSchema *dbSchm = static_cast<DbrSchema *>(itemAt(pos));

	if(dbSchm) {
		
	} 
}

void ResourceTree::showTableContextMenu(const QPoint& pos) {

	DbrTable *dbTbl = static_cast<DbrTable *>(itemAt(pos));

	if(dbTbl) {
		
	} 
}