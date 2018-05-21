
#ifndef TABWIDGET_H
#define TABWIDGET_H

#include "tabledatapage.h"

#include <QTabWidget>
#include <QWidget>
#include <QString>
#include <QSqlDatabase>


class TabWidget : public QTabWidget {

	Q_OBJECT
	

public:
	explicit TabWidget(QWidget * = Q_NULLPTR);
	~TabWidget();

	void SetupUi();

public slots:
	void OnCloseTabRequest(int);
	void OnAddTab(TableDataPage *);
};


#endif