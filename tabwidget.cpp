
#include "tabwidget.h"


TabWidget::TabWidget(QWidget *pParent) : QTabWidget(pParent) {
	
	QObject::connect(this, &QTabWidget::tabCloseRequested, this, &TabWidget::OnCloseTabRequest);
}

TabWidget::~TabWidget() { }

void TabWidget::OnAddTab(TableDataPage *pPage) {

	addTab(pPage, pPage->PageLabel());
}

void TabWidget::OnCloseTabRequest(int index) {

	// free memory immediately
	widget(index)->deleteLater();
	removeTab(index);
}

void TabWidget::SetupUi() {

	setTabsClosable(true);
	setMovable(true);

	//Style();
}

void TabWidget::Style() {

	setStyleSheet(
		"QWidget {"
		"background-color: #bbb;"
		"}"
	);
}