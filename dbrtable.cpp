
#include "dbrtable.h"

#include <QAction>


DbrTable::DbrTable(const QString& schemaName, const QString& tableName, QTreeWidgetItem *parent) 
	: AbstractResource(ResourceType::Table, parent), aSchemaName(schemaName), aTableName(tableName) {

	setText(0, tableName);
}

DbrTable::~DbrTable() { }

QString DbrTable::schemaName() const {
	return aSchemaName;
}

QString DbrTable::tableName() const {
	return aTableName;
}
