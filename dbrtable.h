
#ifndef DBRTABLE_H
#define DBRTABLE_H


#include "abstractresource.h"

#include <QString>



// Database Resource (Dbr) Table
class DbrTable : public AbstractResource  {

	Q_OBJECT

public:
	explicit DbrTable(const QString&, const QString&, QTreeWidgetItem * = Q_NULLPTR);
	~DbrTable();

	QString schemaName() const;
	QString tableName() const;


private:
	QString aSchemaName;
	QString aTableName;
};


#endif