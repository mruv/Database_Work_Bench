
#include "resourcetree.h"


#include <iostream>


ResourceTree::ResourceTree(QWidget *parent) : QTreeWidget(parent) {

	setHeaderLabels({"Resource"});
}


void ResourceTree::onAddDatabaseResource(DatabaseResource *dbResource) {

	addTopLevelItem(dbResource);

	dbResource->establishConnection();

	std::cout << "Made It\n";
}