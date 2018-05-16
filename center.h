
#ifndef CENTER_H
#define CENTER_H


#include "databaseresourcetreeitem.h"
#include "tabwidget.h"
#include "resourcetree.h"


#include <QSplitter>
#include <QWidget>
#include <QSqlDatabase>
#include <Qt>
#include <QMap>
#include <QString>


class Center : public QSplitter {

	Q_OBJECT

public:
	Center(QWidget * = Q_NULLPTR);

public slots:
	void onAddDatabaseResource(DatabaseResourceTreeItem *);

signals:
	void addDatabaseResource(DatabaseResourceTreeItem *);

private:
	QSqlDatabase db;
	ResourceTree *aTreeWidget;
	TabWidget *aTabWidget;
};


#endif