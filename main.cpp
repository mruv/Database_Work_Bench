
#include "mainwindow.h"
#include <QApplication>



int main(int argc, char **argv){
	
	QApplication *pApp = new QApplication(argc, argv);

	MainWindow window;

	window.SetupUi();
	window.show();
	
	return pApp->exec();
}