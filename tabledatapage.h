
#ifndef TABLEDATAPAGE_H
#define TABLEDATAPAGE_H


#include <QFrame>
#include <QSqlDatabase>
#include <QTableView>
#include <QSqlTableModel>



class TableDataPage : public QFrame {

public:
	explicit TableDataPage(const QString&, const QString&, const QSqlDatabase&, QWidget * = Q_NULLPTR);
	~TableDataPage();

	QString pageLabel();


private:
	QSqlTableModel *aSqlTableModel;
	QTableView     *aTableView;
	QString        aTableName;
	QString        aSchemaName;
};

#endif