
#ifndef TABLEDATAPAGE_H
#define TABLEDATAPAGE_H


#include <QWidget>
#include <QSqlDatabase>
#include <QTableView>
#include <QSqlTableModel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QString>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlField>
#include <QVariant>
#include <QProgressBar>


class TableDataPage : public QWidget {


public:
	explicit TableDataPage(const QString&, const QString&, const QSqlDatabase&, QWidget * = Q_NULLPTR);
	~TableDataPage();

	QString        PageLabel();
	void           SetupUi();
	void           CreateCenter();
	void           CreateLayouts();
	void           CreateTop();
	void           CreateBottom();
	void           Style();

signals:
	void           PopulateTableView();

private:

	Q_OBJECT


	QSqlDatabase   mDatabase;
	QSqlTableModel *mpSqlTableModel;
	QTableView     *mpTableView;
	QString        mTableName;
	QString        mSchemaName;

	QVBoxLayout    *mpMainLy;
	QHBoxLayout    *mpTopLy;
	QHBoxLayout    *mpBottomLy;

	QPushButton    *mpAddRecordBtn;
	QPushButton    *mpAddColumnBtn;
	QPushButton    *mpExportBtn;

	QProgressBar   *mpProgressBar;
};

#endif