
#include "dbrschema.h"


DbrSchema::DbrSchema(const QString& schemaName, const QString& connectionName, QTreeWidgetItem *parent)
	: AbstractResource(ResourceType::Database, parent), aSchemaName(schemaName), aConnectionName(connectionName) {

	setText(0, aSchemaName);
}

DbrSchema::~DbrSchema() { }

QString DbrSchema::SchemaName() const {
	return aSchemaName;
}

QString DbrSchema::ConnectionName() const {
	return aConnectionName;
}