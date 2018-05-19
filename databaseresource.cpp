
#include "databaseresource.h"
#include "dbrschema.h"
#include "dbrtable.h"

#include <iostream>
#include <QSqlQuery>
#include <QSqlError>



DatabaseResource::DatabaseResource(
	const QString& user, const QString& pwd, const QString& host, 
		const QString& driverName, const QString& dbmsName, QTreeWidgetItem *parent) 
			: QTreeWidgetItem(parent, QTreeWidgetItem::UserType), user(user), pwd(pwd), host(host), driverName(driverName), dbmsName(dbmsName) {

	setText(0, host + " | " + user + " | " + dbmsName);
}


void DatabaseResource::establishConnection() {


	if(!db.isOpen()){// should not be connected

		db = QSqlDatabase::addDatabase(driverName);
		db.setUserName(user);
		db.setHostName(host);
		db.setPassword(pwd);

		if(db.open()) {
			onConnect();

		} else {
			std::cout << db.lastError().text().toStdString() << std::endl; 
		}
	}
}


void DatabaseResource::onConnect(){

	QSqlQuery dbsQuery("SHOW DATABASES", db);

	while (dbsQuery.next()) {

		QString schemaName   = dbsQuery.value(0).toString();
		DbrSchema *dbrSchema = new DbrSchema(schemaName, this);

		QSqlQuery tsQuery("USE " + schemaName, db);
		tsQuery.exec("SHOW TABLES");

		while (tsQuery.next()) {

			QString tableName = tsQuery.value(0).toString();
			dbrSchema->addChild(new DbrTable(schemaName, tableName, dbrSchema));
		}
		
		setExpanded(true);
	}
}
