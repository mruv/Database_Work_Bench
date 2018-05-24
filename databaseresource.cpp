
#include "dbrschema.h"
#include "dbrtable.h"
#include "databaseresource.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QAction>



DatabaseResource::DatabaseResource(
	const QString& user, const QString& pwd, const QString& host, const QString& driver, 
		const QString& dbms, QTreeWidgetItem *pParent) 
			: AbstractResource(ResourceType::DatabaseConnection, pParent), mUser(user), mPwd(pwd), 
				mHost(host), mDriver(driver), mDbms(dbms), mConnectionName(host + "_" + user) {

	setText(0, mHost + " | " + mUser + " | " + mDbms);
}

// destroy
DatabaseResource::~DatabaseResource() {
	//mDatabase.close();
}

void DatabaseResource::EstablishConnection() {


	if(!mDatabase.isOpen()){// should not be connected

		mDatabase = QSqlDatabase::addDatabase(mDriver, mConnectionName);
		mDatabase.setHostName(mHost);
		mDatabase.setUserName(mUser);
		mDatabase.setPassword(mPwd);

		if(mDatabase.open()) {
			OnConnect();

		} else {
			//std::cout << mDatabase.lastError().text().toStdString() << std::endl; 
		}
	}
}

// display all databases and tables after a successful connection
void DatabaseResource::OnConnect(){

	QSqlQuery dbsQuery("SHOW DATABASES", mDatabase);

	// all databases
	while (dbsQuery.next()) {

		QString schemaName   = dbsQuery.value(0).toString();
		DbrSchema *dbrSchema = new DbrSchema(schemaName, mConnectionName, this);

		QSqlQuery tsQuery("USE " + schemaName, mDatabase);
		tsQuery.exec("SHOW TABLES");

		// all tables in each database
		while (tsQuery.next()) {

			QString tableName = tsQuery.value(0).toString();
			dbrSchema->addChild(new DbrTable(schemaName, tableName, mConnectionName, dbrSchema));
		}
		
		setExpanded(true);
	}
}

QSqlDatabase DatabaseResource::Database() const {
	return mDatabase;
}

QString DatabaseResource::User() const {
	return mUser;
}

QString DatabaseResource::Pwd() const {
	return mPwd;
}

QString DatabaseResource::Host() const {
	return mHost;
}

QString DatabaseResource::Driver() const {
	return mDriver;
}

QString DatabaseResource::Dbms() const {
	return mDbms;
}

QString DatabaseResource::ConnectionName() const {
	return mConnectionName;
}