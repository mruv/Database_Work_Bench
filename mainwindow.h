
#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include "login.h"
#include "center.h"

#include <QMainWindow>
#include <QWidget>
#include <QIcon>
#include <QMenu>
#include <QAction>
#include <QMenuBar>


class MainWindow : public QMainWindow {

	Q_OBJECT

public:
	MainWindow(QWidget * = Q_NULLPTR);

	void createMenus();
	void createMenuBar();
	void createActions();
	void setupUi();

public slots:

	void onConnect();

private:
	LoginFrame *aLoginFrame;
	Center *aCenter;

	// menus
	QMenu *file;
	QMenu *edit;

	// actions
	QAction *aNewDbAction;
	QAction *aNewFileAction;
};



#endif