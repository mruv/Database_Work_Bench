

#ifndef DATABASETREEWIDGET_H
#define DATABASETREEWIDGET_H


#include <QTreeWidget>
#include <QWidget>



class DatabaseTreeWidget : public QTreeWidget {


public:
	DatabaseTreeWidget(const QString&, const QString&, const QString&, QWidget * = Q_NULLPTR);



private:
	QSqlDatabase db;

	// connection
	QString user;
	QString pwd;
	QString host;
};


#endif