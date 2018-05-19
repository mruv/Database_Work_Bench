
#ifndef DBRSCHEMA_h
#define DBRSCHEMA_h


#include "abstractresource.h"
#include "resourcetype.h"

#include <QTreeWidgetItem>
#include <QString>


// Database Resource Schema
class DbrSchema : public AbstractResource {

	Q_OBJECT


public:
	explicit DbrSchema(const QString&, QTreeWidgetItem * = Q_NULLPTR);
	~DbrSchema();

	QString schemaName() const;

private:
	QString aSchemaName;
};



#endif