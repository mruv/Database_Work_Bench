
#ifndef DBRSCHEMA_h
#define DBRSCHEMA_h


#include <QTreeWidgetItem>
#include <QString>


// Database Resource Schema
class DbrSchema : public QObject, public QTreeWidgetItem {

	Q_OBJECT


public:
	explicit DbrSchema(const QString&, QTreeWidgetItem * = Q_NULLPTR);
	~DbrSchema() {}

private:
	QString schemaName;
};



#endif