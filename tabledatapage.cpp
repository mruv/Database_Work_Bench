
#include "tabledatapage.h"

#include <iostream>


TableDataPage::TableDataPage(const QString& schemaName, const QString& tableName, 
	const QSqlDatabase& database, QWidget *pParent)
		: QWidget(pParent), mDatabase(database), mSchemaName(schemaName), mTableName(tableName),
			mpTableView(new QTableView()), mpSqlTableModel(new QSqlTableModel(this, mDatabase)) {

	QObject::connect(this, &TableDataPage::PopulateTableView, mpSqlTableModel, &QSqlTableModel::select);
}

TableDataPage::~TableDataPage() { }

QString TableDataPage::PageLabel() {
	return mSchemaName + "/" + mTableName;
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

	QSqlQuery query("USE " + mSchemaName, mDatabase);

	mpSqlTableModel->setTable(mTableName);
	mpTableView->setModel(mpSqlTableModel);
	mpTableView->resizeColumnsToContents();
	mpTableView->setSortingEnabled(true);
}

void TableDataPage::CreateLayouts() {

	mpMainLy   = new QVBoxLayout(this);
	mpTopLy    = new QHBoxLayout();
	mpBottomLy = new QHBoxLayout();


	mpTopLy->addWidget(mpExportBtn);
	mpTopLy->addWidget(mpAddRecordBtn);
	mpTopLy->addWidget(mpAddColumnBtn);
	mpTopLy->addStretch();

	//mpBottomLy->addStretch();
	mpBottomLy->addWidget(mpProgressBar);

	mpMainLy->addLayout(mpTopLy);
	mpMainLy->addWidget(mpTableView);
	mpMainLy->addLayout(mpBottomLy);
}

void TableDataPage::CreateTop() {

	mpAddRecordBtn = new QPushButton("Add Record");
	mpAddColumnBtn = new QPushButton("Add Column");
	mpExportBtn    = new QPushButton("Export");

	QObject::connect(mpExportBtn, &QPushButton::clicked, [=](){

		mpProgressBar->setValue(0);
		mpProgressBar->setRange(0, mpSqlTableModel->rowCount());
		mpProgressBar->show();


		for (int i = 0; i < mpSqlTableModel->rowCount(); i++) {

			mpProgressBar->setValue(i + 1);

			QSqlRecord record = mpSqlTableModel->record(i);

			for (int j = 0; j < record.count(); j++) {

				if (j == (record.count() - 1)) {
					std::cout << record.field(j).value().toString().toStdString();
				} else {
					std::cout << record.field(j).value().toString().toStdString() << ", ";
				}
			}

			std::cout << std::endl;
		}

		mpProgressBar->hide();
	});
}

void TableDataPage::CreateBottom() {

	mpProgressBar = new QProgressBar(this);
	mpProgressBar->setMaximumHeight(8);

	mpProgressBar->hide();
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