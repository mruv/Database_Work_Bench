
#ifndef TABWIDGET_H
#define TABWIDGET_H

#include "tabledatapage.h"

#include <QTabWidget>
#include <QWidget>
#include <QString>
#include <QSqlDatabase>



class TabWidget : public QTabWidget {

	

public:
	explicit TabWidget(QWidget * = Q_NULLPTR);
	~TabWidget();


public slots:
	void onAddTab(TableDataPage *);
};



#endif