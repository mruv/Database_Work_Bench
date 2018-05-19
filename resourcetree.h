
#ifndef RESOURCETREE_H
#define RESOURCETREE_H


#include "resourcetype.h"
#include "dbrtable.h"
#include "dbrschema.h"
#include "databaseresource.h"

#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QWidget>
#include <QMap>
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

	void createContextMenus();

	void showConnectionContextMenu(const QPoint&);
	void showDatabaseContextMenu(const QPoint&);
	void showTableContextMenu(const QPoint&);

public slots:
	void onAddDatabaseResource(DatabaseResource *);
	void onViewTableData();
	void onCustomContextMenuRequest(const QPoint&);

private:
	// database connection context menu
	QMenu *aDbConnContextMenu;
	// database resource context menu
	QMenu *aDbrContextMenu;
	// database table resource context menu
	QMenu *aTrContextMenu;
};



#endif