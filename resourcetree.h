
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
	ResourceTree(QWidget * = Q_NULLPTR);

public slots:
	void onAddDatabaseResource(DatabaseResource *);
};



#endif