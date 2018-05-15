
#ifndef TABWIDGET_H
#define TABWIDGET_H


#include <QTabWidget>
#include <QWidget>



class TabWidget : public QTabWidget {

	Q_OBJECT

public:
	TabWidget(QWidget * = Q_NULLPTR);
};



#endif