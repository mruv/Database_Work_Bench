
#include "center.h"



Center::Center(QWidget *p) : QSplitter(p) {

	aTreeWidget = new ResourceTree();
	aTabWidget  = new TabWidget();

	addWidget(aTreeWidget);
	addWidget(aTabWidget);
	setSizes({300, 1500});

	QObject::connect(this, &Center::addDatabaseResource, aTreeWidget, &ResourceTree::onAddDatabaseResource);
}


void Center::onAddDatabaseResource(DatabaseResource *dbResource) {

	emit addDatabaseResource(dbResource);
}