
#include "treewidget.h"

#include <QTreeWidgetItem>


TreeWidget::TreeWidget(QWidget *p) : QTreeWidget(p) {

	setColumnCount(3);

	QTreeWidgetItem *x = new QTreeWidgetItem({"Hello"});

	addTopLevelItems({x, new QTreeWidgetItem({"DFGHGHJ"})});

	addTopLevelItem(new QTreeWidgetItem({"SDFGHJKJKJK"}));

	x->addChildren({new QTreeWidgetItem({"SDFGHJTY"}), new QTreeWidgetItem({"SDFGHJK"})});
}