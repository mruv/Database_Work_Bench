

#ifndef DATABASETREEWIDGETITEM_H
#define DATABASETREEWIDGETITEM_H


#include <QTreeWidgetItem>
#include <QSqlDatabase>



class DatabaseResourceTreeItem : public QTreeWidgetItem {


public:
	DatabaseResourceTreeItem(const QString&, const QString&, const QString&, const QString&, QTreeWidgetItem * = Q_NULLPTR);

	void enumerateDatabases();


private:
	QSqlDatabase db;

	// connection
	QString user;
	QString pwd;
	QString host;
	QString driverName;
};


#endif