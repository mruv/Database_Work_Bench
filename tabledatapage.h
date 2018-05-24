
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

	Q_OBJECT


public:
	explicit TableDataPage(const QString&, const QString&, const QSqlDatabase&, QWidget * = Q_NULLPTR);
	~TableDataPage();

	QString PageLabel();
	void SetupUi();
	void CreateCenter();
	void CreateLayouts();
	void CreateTop();
	void CreateBottom();
	void Style();

signals:
	void PopulateTableView();


private:
	QSqlDatabase   database;
	QSqlTableModel *aSqlTableModel;
	QTableView     *aTableView;
	QString        aTableName;
	QString        aSchemaName;

	// layouts
	QVBoxLayout *mainLy;
	QHBoxLayout *topLy;
	QHBoxLayout *bottomLy;

	// buttons
	QPushButton *addRecordBtn;
	QPushButton *addColumnBtn;
	QPushButton *exportBtn;

	// progress
	QProgressBar *aProgressBar;
};

#endif