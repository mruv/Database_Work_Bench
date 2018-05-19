
#include "tabwidget.h"


TabWidget::TabWidget(QWidget *parent) : QTabWidget(parent) {

	setTabsClosable(true);	
}

TabWidget::~TabWidget() { }

void TabWidget::onAddTab(TableDataPage *page) {

	// a new tab
	addTab(page, page->pageLabel());
}