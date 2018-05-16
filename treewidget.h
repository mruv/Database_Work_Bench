
#ifndef TREEWIDGET_H
#define TREEWIDGET_H


#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QWidget>



class ResourceTree : public QTreeWidget {

	Q_OBJECT


public:
	ResourceTree(QWidget * = Q_NULLPTR);

public slots:
	void addResource(QTreeWidgetItem *);
};



#endif