
#include "tabledatapage.h"

#include <iostream>


TableDataPage::TableDataPage(const QString& schemaName, const QString& tableName, 
	const QSqlDatabase& database, QWidget *parent)
		: QWidget(parent), database(database), aSchemaName(schemaName), aTableName(tableName),
			aTableView(new QTableView()), aSqlTableModel(new QSqlTableModel(this, database)) {

	QObject::connect(this, &TableDataPage::PopulateTableView, aSqlTableModel, &QSqlTableModel::select);
}

TableDataPage::~TableDataPage() { }

QString TableDataPage::PageLabel() {
	return aSchemaName + "/" + aTableName;
}

void TableDataPage::SetupUi() {

	CreateTop();
	CreateCenter();
	CreateBottom();
	CreateLayouts();

	// populate table
	emit PopulateTableView();
}

void TableDataPage::CreateCenter() {

	QSqlQuery q("USE " + aSchemaName, database);

	aSqlTableModel->setTable(aTableName);
	aTableView->setModel(aSqlTableModel);
	aTableView->resizeColumnsToContents();
	aTableView->setSortingEnabled(true);
}

void TableDataPage::CreateLayouts() {

	mainLy   = new QVBoxLayout(this);
	topLy    = new QHBoxLayout();
	bottomLy = new QHBoxLayout();


	topLy->addWidget(exportBtn);
	topLy->addWidget(addRecordBtn);
	topLy->addWidget(addColumnBtn);
	topLy->addStretch();

	//bottomLy->addStretch();
	bottomLy->addWidget(aProgressBar);

	mainLy->addLayout(topLy);
	mainLy->addWidget(aTableView);
	mainLy->addLayout(bottomLy);
}

void TableDataPage::CreateTop() {

	addRecordBtn = new QPushButton("Add Record");
	addColumnBtn = new QPushButton("Add Column");
	exportBtn    = new QPushButton("Export");

	QObject::connect(exportBtn, &QPushButton::clicked, [=](){

		aProgressBar->setValue(0);
		aProgressBar->setRange(0, aSqlTableModel->rowCount());
		aProgressBar->show();


		for (int i = 0; i < aSqlTableModel->rowCount(); i++) {

			aProgressBar->setValue(i + 1);

			QSqlRecord rec = aSqlTableModel->record(i);

			for (int j = 0; j < rec.count(); j++) {

				if (j == (rec.count() - 1)) {
					std::cout << rec.field(j).value().toString().toStdString();
				} else {
					std::cout << rec.field(j).value().toString().toStdString() << ", ";
				}
			}

			std::cout << std::endl;
		}

		aProgressBar->hide();
	});
}

void TableDataPage::CreateBottom() {

	aProgressBar = new QProgressBar(this);
	aProgressBar->setMaximumHeight(8);

	aProgressBar->hide();
}

void TableDataPage::Style() {

	setStyleSheet(
		"QProgressBar {"
		"	border: 2px solid grey;"
		"	border-radius: 5px;"
		"	text-align: center;"
		"	width: 3px;}"
		"QProgressBar::chunk {"
    	"	background-color: #05B8CC;"
    	"	margin: 0.5px;"
    	"	width: auto;}"
		);
}