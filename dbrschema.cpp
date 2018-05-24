
#include "dbrschema.h"


DbrSchema::DbrSchema(const QString& schemaName, const QString& connectionName, QTreeWidgetItem *pParent)
	: AbstractResource(ResourceType::Database, pParent), mSchemaName(schemaName), mConnectionName(connectionName) {

	setText(0, mSchemaName);
}

DbrSchema::~DbrSchema() { }

QString DbrSchema::SchemaName() const {
	return mSchemaName;
}

QString DbrSchema::ConnectionName() const {
	return mConnectionName;
}