

#ifndef DATABASERESOURCE_H
#define DATABASERESOURCE_H

#include <QString>
#include <QObject>
#include <QTreeWidgetItem>
#include <QSqlDatabase>


/*
* Database connection info
*/
class DatabaseResource : public QObject, public QTreeWidgetItem {
	

public:
	DatabaseResource(const QString&, const QString&, const QString&, const QString&, const QString&, QTreeWidgetItem * = Q_NULLPTR);
	~DatabaseResource();

	void enumerateDatabases();
	void establishConnection();
	void onConnect();

	QSqlDatabase database() const;
	QString user() const;
	QString pwd() const;
	QString host() const;
	QString driver() const;
	QString dbms() const;


private:
	// connection
	QSqlDatabase aDatabase;

	QString aUser;
	QString aPwd;
	QString aHost;
	QString aDriver;
	QString aDbms;
};


#endif