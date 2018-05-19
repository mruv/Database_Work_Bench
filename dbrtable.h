
#ifndef DBRTABLE_H
#define DBRTABLE_H


#include <QTreeWidgetItem>
#include <QString>


class DbrTable : public QObject, public QTreeWidgetItem {

	Q_OBJECT

public:
	explicit DbrTable(const QString&, const QString&, QTreeWidgetItem * = Q_NULLPTR);
	~DbrTable();

private:
	QString schemaName;
	QString tableName;
};


#endif