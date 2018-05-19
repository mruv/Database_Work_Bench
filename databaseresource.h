

#ifndef DATABASERESOURCE_H
#define DATABASERESOURCE_H


#include "abstractresource.h"

#include <QString>
#include <QSqlDatabase>


/*
* Database connection info
*/
class DatabaseResource : public AbstractResource {

	Q_OBJECT

public:
	explicit DatabaseResource(const QString&, const QString&, const QString&, const QString&, const QString&, QTreeWidgetItem * = Q_NULLPTR);
	~DatabaseResource();

	QSqlDatabase database() const;
	QString user() const;
	QString pwd() const;
	QString host() const;
	QString driver() const;
	QString dbms() const;


public slots:
	void establishConnection();
	void onConnect();

private:
	// connection
	QSqlDatabase aDatabase;

	QString      aUser;
	QString      aPwd;
	QString      aHost;
	QString      aDriver;
	QString      aDbms;
};


#endif