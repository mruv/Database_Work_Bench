
#include "databaseresource.h"
#include "dbrschema.h"
#include "dbrtable.h"

#include <iostream>
#include <QSqlQuery>
#include <QSqlError>



DatabaseResource::DatabaseResource(
	const QString& user, const QString& pwd, const QString& host, 
		const QString& driverName, QTreeWidgetItem *parent) 
			: QTreeWidgetItem(parent), user(user), pwd(pwd), host(host), driverName(driverName) {

	setText(0, host + " | " + user + " | " + driverName);
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


void DatabaseResource::enumerateDatabases() {

}


void DatabaseResource::onConnect(){

	QSqlQuery dbsQuery;

	// list databases
	dbsQuery.exec("SHOW DATABASES");

	while (dbsQuery.next()) {
		QString schema = dbsQuery.value(0).toString();

		addChild(new DbrSchema(schema));

		db.setDatabaseName(schema);

		std::cout << schema.toStdString() << std::endl;

		/*for(QString x : db.tables()){
			std::cout << x.toStdString() << std::endl;
		}*/
		
	}
}
