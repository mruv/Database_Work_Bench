
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

	

	setStyleSheet(
		"QScrollBar:vertical { width: 6px; border: 0; background-color: #999; }"
		"QScrollBar:horizontal { height: 6px; border: 0; background-color: #999; }"
		"QScrollBar::handle:vertical {background-color: #666; border-radius: 3px; }"
		"QScrollBar::handle:horizontal {background-color: #666; border-radius: 3px; }"
		"QScrollBar::add-line:horizontal { border: none; background: none; }"
		"QScrollBar::sub-line:horizontal { border: none; background: none; }"
		"QScrollBar::add-line:vertical { border: none; background: none; }"
		"QScrollBar::sub-line:vertical { border: none; background: none; }"
		);
}

void MainWindow::ShowDatabaseResourceDialog() {

	DatabaseResourcePicker drp;

	drp.SetupUi();

	QObject::connect(&drp, &DatabaseResourcePicker::AddDatabaseResource,
		aCenter, &Center::OnAddDatabaseResource);

	drp.exec();
}