
#include "treewidget.h"
#include "dbtreewidgetitem.h"



ResourceTree::ResourceTree(QWidget *p) : QTreeWidget(p) {

	setHeaderLabels({"Resource", "Status"});

	//DatabaseTreeWidgetItem *db = new DatabaseTreeWidgetItem(tr("root"), tr("mwendwa"), tr("localhost"), tr("QMYSQL"));

	//addTopLevelItem(db);
}

void ResourceTree::addResource(QTreeWidgetItem *resource) {

	addTopLevelItem(resource);
}