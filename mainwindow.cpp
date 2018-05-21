
#include "mainwindow.h"
#include "databaseresourcepicker.h"


MainWindow::MainWindow(QWidget *p) 
	: QMainWindow(p), aCenter(new Center()) {
}


void MainWindow::CreateMenus() {

	aFileMenu = menuBar()->addMenu(tr("&File"));
}

void MainWindow::CreateMenuBar() {

	aFileMenu->addAction(aNewDbAction);
}

void MainWindow::CreateActions() {

	aNewDbAction = new QAction(tr("&New Database"));
	QObject::connect(aNewDbAction, &QAction::triggered, this, &MainWindow::ShowDatabaseResourceDialog);
}

void MainWindow::SetupUi() {

	CreateActions();
	CreateMenus();
	CreateMenuBar();

	setCentralWidget(aCenter);
	setWindowTitle("Data Droid");
	setWindowIcon(QIcon("rocket.png"));
	setMinimumSize(600, 400);
	showMaximized();

}

void MainWindow::ShowDatabaseResourceDialog() {

	DatabaseResourcePicker drp;

	drp.SetupUi();

	QObject::connect(&drp, &DatabaseResourcePicker::AddDatabaseResource,
		aCenter, &Center::OnAddDatabaseResource);

	drp.exec();
}