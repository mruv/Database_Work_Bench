
#include "dbrtable.h"

#include <QAction>


DbrTable::DbrTable(const QString& schemaName, const QString& tableName, QTreeWidgetItem *parent) 
	: QTreeWidgetItem(parent, QTreeWidgetItem::UserType), schemaName(schemaName), tableName(tableName) {

	setText(0, tableName);
	//addAction(new QAction("View data"));
}

DbrTable::~DbrTable() { }