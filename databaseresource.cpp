
#include "databaseresource.h"

#include <iostream>



DatabaseResource::DatabaseResource(
	const QString& user, const QString& pwd, const QString& host, 
		const QString& driverName, QTreeWidgetItem *p) 
			: QTreeWidgetItem(p), user(user), pwd(user), host(host), driverName(driverName) {

	db = QSqlDatabase::addDatabase(driverName);
	db.setUserName(user);
	db.setHostName(host);
	db.setPassword(pwd);


	if(db.open()) {
		std::cout << "Hurraaaaay\n";
	} else {
		std::cout << "Failed\n";
	}
}


void DatabaseResource::enumerateDatabases() {

}