
#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include "login.h"
#include "center.h"

#include <QMainWindow>
#include <QWidget>
#include <QIcon>



class MainWindow : public QMainWindow {

	Q_OBJECT

public:
	MainWindow(QWidget * = Q_NULLPTR);

public slots:

	void onConnect();

private:
	LoginFrame *aLoginFrame;
	Center *aCenter;
};



#endif