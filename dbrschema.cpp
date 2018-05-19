
#include "dbrschema.h"



DbrSchema::DbrSchema(const QString& schemaName, QTreeWidgetItem *parent)
	: AbstractResource(ResourceType::Database, parent), aSchemaName(schemaName) {

	setText(0, aSchemaName);
}

DbrSchema::~DbrSchema() { }

QString DbrSchema::schemaName() const {
	return aSchemaName;
}
