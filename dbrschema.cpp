
#include "dbrschema.h"



DbrSchema::DbrSchema(const QString& schemaName, QTreeWidgetItem *parent)
	: QTreeWidgetItem(parent), schemaName(schemaName) {

	setText(0, schemaName);
}