
#include "dbrtable.h"


DbrTable::DbrTable(const QString& schemaName, const QString& tableName, 
	const QString& connectionName, QTreeWidgetItem *pParent)
		: AbstractResource(ResourceType::Table, pParent), mSchemaName(schemaName), 
			mTableName(tableName), mConnectionName(connectionName) {

	setText(0, mTableName);
}

DbrTable::~DbrTable() { }

QString DbrTable::SchemaName() const {
	return mSchemaName;
}

QString DbrTable::TableName() const {
	return mTableName;
}

QString DbrTable::ConnectionName() const {
	return mConnectionName;
}