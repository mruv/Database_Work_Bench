

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

	QSqlDatabase Database() const;
	QString User() const;
	QString Pwd() const;
	QString Host() const;
	QString Driver() const;
	QString Dbms() const;
	QString ConnectionName() const;


public slots:
	void EstablishConnection();
	void OnConnect();

private:
	// connection
	QSqlDatabase aDatabase;

	QString      aUser;
	QString      aPwd;
	QString      aHost;
	QString      aDriver;
	QString      aDbms;
	QString      aConnectionName;
};


#endif