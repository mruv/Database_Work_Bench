
#include "mainwindow.h"
#include "databaseresourcepicker.h"


MainWindow::MainWindow(QWidget *pParent) 
	: QMainWindow(pParent), mpCenter(new Center()) {
}

MainWindow::~MainWindow() { }

void MainWindow::CreateMenus() {

	mpFileMenu = menuBar()->addMenu(tr("&File"));
}

void MainWindow::CreateMenuBar() {

	mpFileMenu->addAction(mpNewDbAction);
}

void MainWindow::CreateActions() {

	mpNewDbAction = new QAction(tr("&New Database"));
	QObject::connect(mpNewDbAction, &QAction::triggered, this, &MainWindow::ShowDatabaseResourceDialog);
}

void MainWindow::SetupUi() {

	CreateActions();
	CreateMenus();
	CreateMenuBar();

	setCentralWidget(mpCenter);
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

	DatabaseResourcePicker db_resource_picker;

	db_resource_picker.SetupUi();

	QObject::connect(&db_resource_picker, &DatabaseResourcePicker::AddDatabaseResource,
		mpCenter, &Center::OnAddDatabaseResource);

	db_resource_picker.exec();
}