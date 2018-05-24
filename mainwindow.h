
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

	void CreateMenus();
	void CreateMenuBar();
	void CreateActions();
	void SetupUi();

public slots:
	
	void ShowDatabaseResourceDialog();

private:
	Center *aCenter;

	// menus
	QMenu *aFileMenu;
	QMenu *aEditMenu;

	// actions
	QAction *aNewDbAction;
	QAction *aNewFileAction;
};



#endif