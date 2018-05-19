
#include "dbrtable.h"

#include <QAction>


DbrTable::DbrTable(const QString& schemaName, const QString& tableName, 
	const QString& connectionName, QTreeWidgetItem *parent)
		: AbstractResource(ResourceType::Table, parent), aSchemaName(schemaName), 
			aTableName(tableName), aConnectionName(connectionName) {

	setText(0, tableName);
}

DbrTable::~DbrTable() { }

QString DbrTable::schemaName() const {
	return aSchemaName;
}

QString DbrTable::tableName() const {
	return aTableName;
}

QString DbrTable::connectionName() const {
	return aConnectionName;
}