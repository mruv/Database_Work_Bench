
#ifndef ABSTRACTRESOURCE_H
#define ABSTRACTRESOURCE_H

#include "resourcetype.h"

#include <QTreeWidgetItem>
#include <QWidget>


class AbstractResource : public QWidget, public QTreeWidgetItem {


public:
	explicit AbstractResource(ResourceType, QTreeWidgetItem * = Q_NULLPTR);
	virtual ~AbstractResource();

	ResourceType Type() const;


protected:
	ResourceType aResourceType;
};


#endif