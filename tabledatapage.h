
#ifndef TABLEDATAPAGE_H
#define TABLEDATAPAGE_H


#include <QFrame>
#include <QSqlDatabase>
#include <QTableView>
#include <QSqlTableModel>



class TableDataPage : public QFrame {

public:
	explicit TableDataPage(QTableView *, QSqlTableModel *, QWidget * = Q_NULLPTR);
	~TableDataPage();


private:
	QSqlTableModel *model;
	QTableView     *view;
};

#endif