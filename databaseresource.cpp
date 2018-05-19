
#include "dbrschema.h"
#include "dbrtable.h"
#include "databaseresource.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QAction>



DatabaseResource::DatabaseResource(
	const QString& user, const QString& pwd, const QString& host, const QString& driverName, 
		const QString& dbmsName, QTreeWidgetItem *parent) 
			: AbstractResource(ResourceType::DatabaseConnection, parent), aUser(user), aPwd(pwd), 
				aHost(host), aDriver(driverName), aDbms(dbmsName), aConnectionName(host + "_" + user) {

	setText(0, aHost + " | " + aUser + " | " + aDbms);
}

// destroy
DatabaseResource::~DatabaseResource() {
	aDatabase.close();
}

void DatabaseResource::establishConnection() {


	if(!aDatabase.isOpen()){// should not be connected

		aDatabase = QSqlDatabase::addDatabase(aDriver, aConnectionName);
		aDatabase.setHostName(aHost);
		aDatabase.setUserName(aUser);
		aDatabase.setPassword(aPwd);

		if(aDatabase.open()) {
			onConnect();

		} else {
			//std::cout << aDatabase.lastError().text().toStdString() << std::endl; 
		}
	}
}

// display all databases and tables after a successful connection
void DatabaseResource::onConnect(){

	QSqlQuery dbsQuery("SHOW DATABASES", aDatabase);

	// all databases
	while (dbsQuery.next()) {

		QString schemaName   = dbsQuery.value(0).toString();
		DbrSchema *dbrSchema = new DbrSchema(schemaName, aConnectionName, this);

		QSqlQuery tsQuery("USE " + schemaName, aDatabase);
		tsQuery.exec("SHOW TABLES");

		// all tables in each database
		while (tsQuery.next()) {

			QString tableName = tsQuery.value(0).toString();
			dbrSchema->addChild(new DbrTable(schemaName, tableName, aConnectionName, dbrSchema));
		}
		
		setExpanded(true);
	}
}

QSqlDatabase DatabaseResource::database() const {
	return aDatabase;
}

QString DatabaseResource::user() const {
	return aUser;
}

QString DatabaseResource::pwd() const {
	return aPwd;
}

QString DatabaseResource::host() const {
	return aHost;
}

QString DatabaseResource::driver() const {
	return aDriver;
}

QString DatabaseResource::dbms() const {
	return aDbms;
}

QString DatabaseResource::connectionName() const {
	return aConnectionName;
}