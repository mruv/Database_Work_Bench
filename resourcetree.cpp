
#include "resourcetree.h"


#include <iostream>


ResourceTree::ResourceTree(QWidget *parent) : QTreeWidget(parent) {

	setHeaderLabels({"Resource"});
}

ResourceTree::~ResourceTree() { }

void ResourceTree::onAddDatabaseResource(DatabaseResource *dbResource) {

	addTopLevelItem(dbResource);
	dbResource->establishConnection();
}

void ResourceTree::onViewTableData() {

}