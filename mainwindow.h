
#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include "center.h"

#include <QMainWindow>
#include <QWidget>
#include <QIcon>
#include <QMenu>
#include <QAction>
#include <QMenuBar>
#include <QMap>


class MainWindow : public QMainWindow {

	Q_OBJECT

public:
	MainWindow(QWidget * = Q_NULLPTR);

	void createMenus();
	void createMenuBar();
	void createActions();
	void setupUi();

public slots:
	
	void showDatabaseResourceDialog();

private:
	Center *aCenter;

	// menus
	QMenu *file;
	QMenu *edit;

	// actions
	QAction *aNewDbAction;
	QAction *aNewFileAction;
};



#endif