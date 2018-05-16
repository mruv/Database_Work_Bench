
#include "resourcetree.h"


#include <iostream>


ResourceTree::ResourceTree(QWidget *p) : QTreeWidget(p) {

	setHeaderLabels({"Resource"});

	//DatabaseTreeWidgetItem *db = new DatabaseTreeWidgetItem(tr("root"), tr("mwendwa"), tr("localhost"), tr("QMYSQL"));

	//addTopLevelItem(db);
}


void ResourceTree::onAddDatabaseResource(DatabaseResourceTreeItem *dbResource) {

	addTopLevelItem(dbResource);

	std::cout << "Made It\n";
}