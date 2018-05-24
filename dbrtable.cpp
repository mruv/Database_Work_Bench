
#include "dbrtable.h"


DbrTable::DbrTable(const QString& schemaName, const QString& tableName, 
	const QString& connectionName, QTreeWidgetItem *parent)
		: AbstractResource(ResourceType::Table, parent), aSchemaName(schemaName), 
			aTableName(tableName), aConnectionName(connectionName) {

	setText(0, aTableName);
}

DbrTable::~DbrTable() { }

QString DbrTable::SchemaName() const {
	return aSchemaName;
}

QString DbrTable::TableName() const {
	return aTableName;
}

QString DbrTable::ConnectionName() const {
	return aConnectionName;
}