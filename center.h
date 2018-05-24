
#ifndef CENTER_H
#define CENTER_H


#include "databaseresource.h"
#include "tabwidget.h"
#include "resourcetree.h"


#include <QSplitter>
#include <QWidget>
#include <QSqlDatabase>
#include <Qt>
#include <QMap>
#include <QString>


// Application central widget
class Center : public QSplitter {


public:
	explicit Center(QWidget * = Q_NULLPTR);
	~Center();

public slots:
	void         OnAddDatabaseResource(DatabaseResource *);

signals:
	void         AddDatabaseResource(DatabaseResource *);

private:

	Q_OBJECT


	ResourceTree *mpResourceTree;
	TabWidget    *mpTabWidget;
};


#endif