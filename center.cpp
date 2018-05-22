
#include "center.h"



Center::Center(QWidget *p) 
	: QSplitter(p), aResourceTree(new ResourceTree()), aTabWidget(new TabWidget()) {
	
	aResourceTree->CreateContextMenus();
	aResourceTree->Style();

	aTabWidget->SetupUi();

	addWidget(aResourceTree);
	addWidget(aTabWidget);
	setSizes({300, 1500});

	QObject::connect(this, &Center::AddDatabaseResource, aResourceTree, &ResourceTree::OnAddDatabaseResource);
	QObject::connect(aResourceTree, &ResourceTree::AddTableDataPage, aTabWidget, &TabWidget::OnAddTab);
}

Center::~Center() { }

void Center::OnAddDatabaseResource(DatabaseResource *dbResource) {

	emit AddDatabaseResource(dbResource);
}