
#ifndef RESOURCETREE_H
#define RESOURCETREE_H


#include "resourcetype.h"
#include "dbrtable.h"
#include "dbrschema.h"
#include "databaseresource.h"
#include "tabledatapage.h"

#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QTableView>
#include <QSqlDatabase>
#include <QWidget>
#include <QString>
#include <QAction>
#include <QMenu>
#include <QPoint>
#include <Qt>
#include <iostream>



class ResourceTree : public QTreeWidget {


public:
	explicit ResourceTree(QWidget * = Q_NULLPTR);
	~ResourceTree();

	void    CreateContextMenus();

	void    ShowConnectionContextMenu(const QPoint&);
	void    ShowDatabaseContextMenu(const QPoint&);
	void    ShowTableContextMenu(const QPoint&);
	void    Style() const;

public slots:
	void    OnAddDatabaseResource(DatabaseResource *);
	void    OnCustomContextMenuRequest(const QPoint&);

signals:
	void    AddTableDataPage(TableDataPage *);

private:

	Q_OBJECT


	// context menus
	QMenu   *mpDbConnContextMenu;
	QMenu   *mpDbrContextMenu;
	QMenu   *mpTrContextMenu;
	QAction *mpViewTableDataAction;
	QAction *mpNewTableAction;
	QAction *mpNewDbAction;
	QAction *mpDropDbAction; // drop database
	QAction *mpDeleteTableAction; // delete a table
	QAction *mpConnectAction;
	QAction *mpDisconnectAction;
};



#endif