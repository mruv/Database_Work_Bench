
#include "tabwidget.h"

#include <QTabBar>


TabWidget::TabWidget(QWidget *parent) : QTabWidget(parent) {
	
	QObject::connect(this, &QTabWidget::tabCloseRequested, this, &TabWidget::OnCloseTabRequest);
}

TabWidget::~TabWidget() { }

void TabWidget::OnAddTab(TableDataPage *page) {

	addTab(page, page->PageLabel());
}

void TabWidget::OnCloseTabRequest(int index) {

	removeTab(index);
}

void TabWidget::SetupUi() {

	setTabsClosable(true);
	setMovable(true);

	/*setStyleSheet(
		"QWidget {"
		"background-color: #bbb;"
		"}"
	);*/
}