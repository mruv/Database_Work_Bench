
#include "abstractresource.h"



AbstractResource::AbstractResource(ResourceType rType, QTreeWidgetItem *parent)
	: QTreeWidgetItem(parent, QTreeWidgetItem::UserType), aResourceType(rType) {

}

AbstractResource::~AbstractResource() { }

ResourceType AbstractResource::resourceType() const {
	return aResourceType;
}