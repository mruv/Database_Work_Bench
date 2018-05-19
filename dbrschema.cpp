
#include "dbrschema.h"



DbrSchema::DbrSchema(const QString& schemaName, const QString& connectionName, QTreeWidgetItem *parent)
	: AbstractResource(ResourceType::Database, parent), aSchemaName(schemaName), aConnectionName(connectionName) {

	setText(0, aSchemaName);
}

DbrSchema::~DbrSchema() { }

QString DbrSchema::schemaName() const {
	return aSchemaName;
}

QString DbrSchema::connectionName() const {
	return aConnectionName;
}