
#include "center.h"



Center::Center(QWidget *p) 
	: QSplitter(p), aResourceTree(new ResourceTree()), aTabWidget(new TabWidget()){
	
	addWidget(aResourceTree);
	addWidget(aTabWidget);
	setSizes({300, 1500});

	QObject::connect(this, &Center::addDatabaseResource, aResourceTree, &ResourceTree::onAddDatabaseResource);
}

Center::~Center() { }

void Center::onAddDatabaseResource(DatabaseResource *dbResource) {

	emit addDatabaseResource(dbResource);
}