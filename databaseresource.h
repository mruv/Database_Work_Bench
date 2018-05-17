

#ifndef DATABASERESOURCE_H
#define DATABASERESOURCE_H


#include <QTreeWidgetItem>
#include <QSqlDatabase>



class DatabaseResource : public QTreeWidgetItem {


public:
	DatabaseResource(const QString&, const QString&, const QString&, const QString&, QTreeWidgetItem * = Q_NULLPTR);

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