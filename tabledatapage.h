
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


class TableDataPage : public QWidget {

	Q_OBJECT


public:
	explicit TableDataPage(const QString&, const QString&, const QSqlDatabase&, QWidget * = Q_NULLPTR);
	~TableDataPage();

	QString PageLabel();
	void SetupUi();
	void CreateTableView();
	void CreateLayouts();
	void CreateButtons();

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

	// buttons
	QPushButton *addRecordBtn;
	QPushButton *addColumnBtn;
	QPushButton *exportBtn;
};

#endif