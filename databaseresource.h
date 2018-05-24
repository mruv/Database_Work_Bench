

#ifndef DATABASERESOURCE_H
#define DATABASERESOURCE_H


#include "abstractresource.h"

#include <QString>
#include <QSqlDatabase>


/*
* Database connection info
*/
class DatabaseResource : public AbstractResource {

	
public:
	explicit DatabaseResource(const QString&, const QString&, const QString&, const QString&, const QString&, QTreeWidgetItem * = Q_NULLPTR);
	~DatabaseResource();

	QSqlDatabase Database() const;
	QString      User() const;
	QString      Pwd() const;
	QString      Host() const;
	QString      Driver() const;
	QString      Dbms() const;
	QString      ConnectionName() const;


public slots:
	void         EstablishConnection();
	void         OnConnect();

private:

	Q_OBJECT

	
	// connection
	QSqlDatabase mDatabase;

	QString      mUser;
	QString      mPwd;
	QString      mHost;
	QString      mDriver;
	QString      mDbms;
	QString      mConnectionName;
};


#endif