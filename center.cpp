
#include "center.h"



Center::Center(QWidget *pParent) 
	: QSplitter(pParent), mpResourceTree(new ResourceTree()), mpTabWidget(new TabWidget()) {
	
	mpResourceTree->CreateContextMenus();
	mpResourceTree->Style();

	mpTabWidget->SetupUi();

	addWidget(mpResourceTree);
	addWidget(mpTabWidget);
	setSizes({300, 1500});

	QObject::connect(this, &Center::AddDatabaseResource, mpResourceTree, &ResourceTree::OnAddDatabaseResource);
	QObject::connect(mpResourceTree, &ResourceTree::AddTableDataPage, mpTabWidget, &TabWidget::OnAddTab);
}

Center::~Center() { }

void Center::OnAddDatabaseResource(DatabaseResource *pDbResource) {

	emit AddDatabaseResource(pDbResource);
}