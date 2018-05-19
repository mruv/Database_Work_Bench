
#include "center.h"



Center::Center(QWidget *p) 
	: QSplitter(p), aResourceTree(new ResourceTree()), aTabWidget(new TabWidget()) {
	
	aResourceTree->createContextMenus();
	
	addWidget(aResourceTree);
	addWidget(aTabWidget);
	setSizes({300, 1500});

	QObject::connect(this, &Center::addDatabaseResource, aResourceTree, &ResourceTree::onAddDatabaseResource);
	QObject::connect(aResourceTree, &ResourceTree::addTableDataPage, aTabWidget, &TabWidget::onAddTab);
}

Center::~Center() { }

void Center::onAddDatabaseResource(DatabaseResource *dbResource) {

	emit addDatabaseResource(dbResource);
}