
#include "mainwindow.h"




MainWindow::MainWindow(QWidget *p) : QMainWindow(p){

	aLoginFrame = new LoginFrame();
	aCenter     = new Center();

	setCentralWidget(aLoginFrame);
	setWindowTitle("Data Droid");
	setWindowIcon(QIcon("rocket.png"));
	setMinimumSize(600, 400);

	QObject::connect(aLoginFrame, &LoginFrame::connected, this, &MainWindow::onConnect);
}

void MainWindow::onConnect() {

	showMaximized();
	setCentralWidget(aCenter);
}