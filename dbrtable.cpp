
#include "dbrtable.h"



DbrTable::DbrTable(const QString& schemaName, const QString& tableName, QTreeWidgetItem *parent) 
	: QTreeWidgetItem(parent), schemaName(schemaName), tableName(tableName) {

	setText(0, tableName);
}