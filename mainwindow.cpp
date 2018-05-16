
#include "mainwindow.h"




MainWindow::MainWindow(QWidget *p) 
	: QMainWindow(p), aLoginFrame(new LoginFrame()), aCenter(new Center()) {

	QObject::connect(aLoginFrame, &LoginFrame::connected, this, &MainWindow::onConnect);
}

void MainWindow::onConnect() {

	showMaximized();
	setCentralWidget(aCenter);
}


void MainWindow::createMenus() {

	file = menuBar()->addMenu(tr("&File"));
}

void MainWindow::createMenuBar() {

	file->addAction(aNewDbAction);

}

void MainWindow::createActions() {

	aNewDbAction = new QAction(tr("&New Database"));

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

