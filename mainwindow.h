
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


public:
	explicit MainWindow(QWidget * = Q_NULLPTR);
	~MainWindow();

	void    CreateMenus();
	void    CreateMenuBar();
	void    CreateActions();
	void    SetupUi();

public slots:
	
	void    ShowDatabaseResourceDialog();

private:

	Q_OBJECT


	Center  *mpCenter;
	QMenu   *mpFileMenu;
	QMenu   *mpEditMenu;
	QAction *mpNewDbAction;
	QAction *mpNewFileAction;
};



#endif