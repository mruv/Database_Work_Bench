
#ifndef TREEWIDGET_H
#define TREEWIDGET_H


#include <QTreeWidget>
#include <QWidget>



class TreeWidget : public QTreeWidget {

	Q_OBJECT


public:
	TreeWidget(QWidget * = Q_NULLPTR);
};



#endif