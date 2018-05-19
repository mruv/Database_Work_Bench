
#ifndef RESOURCETREE_H
#define RESOURCETREE_H


#include "databaseresource.h"


#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QWidget>
#include <QMap>
#include <QString>



class ResourceTree : public QTreeWidget {

	Q_OBJECT


public:
	explicit ResourceTree(QWidget * = Q_NULLPTR);
	~ResourceTree();

public slots:
	void onAddDatabaseResource(DatabaseResource *);
	void onViewTableData();
};



#endif