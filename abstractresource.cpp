
#include "abstractresource.h"



AbstractResource::AbstractResource(const ResourceType& resourceType, QTreeWidgetItem *pParent)
	: QTreeWidgetItem(pParent, QTreeWidgetItem::UserType), mResourceType(resourceType) {

}

AbstractResource::~AbstractResource() { }

ResourceType AbstractResource::Type() const {
	return mResourceType;
}