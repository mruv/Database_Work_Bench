
#include "center.h"



Center::Center(QWidget *p) : QSplitter(p) {

	aTreeWidget = new TreeWidget();
	aTabWidget  = new TabWidget();

	addWidget(aTreeWidget);
	addWidget(aTabWidget);
	setSizes({300, 1500});
}