

#ifndef DATABASERESOURCE_H
#define DATABASERESOURCE_H

#include <QString>
#include <QObject>
#include <QTreeWidgetItem>
#include <QSqlDatabase>



class DatabaseResource : public QObject, public QTreeWidgetItem {

	

public:
	DatabaseResource(const QString&, const QString&, const QString&, const QString&, QTreeWidgetItem * = Q_NULLPTR);
	~DatabaseResource() {}

	void enumerateDatabases();
	void establishConnection();
	void onConnect();


private:
	QSqlDatabase db;

	// connection
	QString user;
	QString pwd;
	QString host;
	QString driverName;
};


#endif