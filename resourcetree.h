
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

	Q_OBJECT


public:
	explicit ResourceTree(QWidget * = Q_NULLPTR);
	~ResourceTree();

	void CreateContextMenus();

	void ShowConnectionContextMenu(const QPoint&);
	void ShowDatabaseContextMenu(const QPoint&);
	void ShowTableContextMenu(const QPoint&);
	void Style() const;

public slots:
	void OnAddDatabaseResource(DatabaseResource *);
	void OnCustomContextMenuRequest(const QPoint&);

signals:
	void AddTableDataPage(TableDataPage *);

private:
	// context menus
	QMenu   *aDbConnContextMenu; // database connection
	QMenu   *aDbrContextMenu; // database
	QMenu   *aTrContextMenu; // table

	// actions
	QAction *aViewTableDataAction;
	QAction *aNewTableAction;
	QAction *aNewDbAction;
	QAction *aDropDbAction; // drop database
	QAction *aDeleteTableAction; // delete a table
	QAction *aConnectAction;
	QAction *aDisconnectAction;
};



#endif