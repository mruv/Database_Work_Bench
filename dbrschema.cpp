
#include "dbrschema.h"



DbrSchema::DbrSchema(const QString& schemaName, QTreeWidgetItem *parent)
	: QTreeWidgetItem(parent, QTreeWidgetItem::UserType), schemaName(schemaName) {

	setText(0, schemaName);
}

DbrSchema::~DbrSchema() { }