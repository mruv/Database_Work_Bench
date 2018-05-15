
#ifndef CENTER_H
#define CENTER_H


#include "treewidget.h"
#include "tabwidget.h"


#include <QSplitter>
#include <QWidget>
#include <QSqlDatabase>
#include <Qt>


class Center : public QSplitter {

	Q_OBJECT

public:
	Center(QWidget * = Q_NULLPTR);

private:
	QSqlDatabase db;
	TreeWidget *aTreeWidget;
	TabWidget *aTabWidget;
};


#endif