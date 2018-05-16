
#include "mainwindow.h"
#include "databaseresourcepicker.h"



MainWindow::MainWindow(QWidget *p) 
	: QMainWindow(p), aCenter(new Center()) {

}


void MainWindow::createMenus() {

	file = menuBar()->addMenu(tr("&File"));
}

void MainWindow::createMenuBar() {

	file->addAction(aNewDbAction);

}

void MainWindow::createActions() {

	aNewDbAction = new QAction(tr("&New Database"));

	QObject::connect(aNewDbAction, &QAction::triggered, this, &MainWindow::showDatabaseResourceDialog);
}

void MainWindow::setupUi() {

	createActions();
	createMenus();
	createMenuBar();

	setCentralWidget(aCenter);
	setWindowTitle("Data Droid");
	setWindowIcon(QIcon("rocket.png"));
	setMinimumSize(600, 400);
	showMaximized();

}

void MainWindow::showDatabaseResourceDialog() {

	DatabaseResourcePicker drp;

	drp.setupUi();

	QObject::connect(&drp, &DatabaseResourcePicker::addDatabaseResource,
		aCenter, &Center::onAddDatabaseResource);

	drp.exec();
}