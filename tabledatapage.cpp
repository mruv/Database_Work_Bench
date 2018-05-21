
#include "tabledatapage.h"

#include <QSqlQuery>


TableDataPage::TableDataPage(const QString& schemaName, const QString& tableName, 
	const QSqlDatabase& database, QWidget *parent)
		: QWidget(parent), database(database), aSchemaName(schemaName), aTableName(tableName),
			aTableView(new QTableView()), aSqlTableModel(new QSqlTableModel(this, database)) {

	
	//setFrameStyle(QFrame::Plain);
	QObject::connect(this, &TableDataPage::PopulateTableView, aSqlTableModel, &QSqlTableModel::select);
}

TableDataPage::~TableDataPage() { }

QString TableDataPage::PageLabel() {
	return aSchemaName + "/" + aTableName;
}

void TableDataPage::SetupUi() {

	CreateButtons();
	CreateTableView();
	CreateLayouts();

	// populate table
	emit PopulateTableView();
}

void TableDataPage::CreateTableView() {

	QSqlQuery q("USE " + aSchemaName, database);

	aSqlTableModel->setTable(aTableName);
	aTableView->setModel(aSqlTableModel);
	aTableView->resizeColumnsToContents();
	aTableView->setSortingEnabled(true);
}

void TableDataPage::CreateLayouts() {

	mainLy = new QVBoxLayout(this);
	topLy  = new QHBoxLayout();

	topLy->addWidget(exportBtn);
	topLy->addWidget(addRecordBtn);
	topLy->addWidget(addColumnBtn);
	topLy->addStretch();

	mainLy->addLayout(topLy);
	mainLy->addWidget(aTableView);
}

void TableDataPage::CreateButtons() {

	addRecordBtn = new QPushButton("Add Record");
	addColumnBtn = new QPushButton("Add Column");
	exportBtn    = new QPushButton("Export");
}