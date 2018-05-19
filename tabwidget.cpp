
#include "tabwidget.h"


TabWidget::TabWidget(QWidget *p) : QTabWidget(p) {

	addTab(new QWidget(), "one");
	addTab(new QWidget(), "two");	
}