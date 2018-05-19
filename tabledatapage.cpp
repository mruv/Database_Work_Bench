
#include "tabledatapage.h"

#include <QSqlQuery>

TableDataPage::TableDataPage(const QString& schemaName, const QString& tableName, 
	const QSqlDatabase& database, QWidget *parent)
		: QFrame(parent), aSchemaName(schemaName), aTableName(tableName),
			aTableView(new QTableView()), aSqlTableModel(new QSqlTableModel(this, database)) {

	QSqlQuery q("USE " + aSchemaName, database);
	aSqlTableModel->setTable(aTableName);
	aTableView->setModel(aSqlTableModel);
	aSqlTableModel->select();
	setFrameStyle(QFrame::Plain);

	aTableView->show();
}

TableDataPage::~TableDataPage() { }

QString TableDataPage::pageLabel() {
	return aSchemaName + "/" + aTableName;
}