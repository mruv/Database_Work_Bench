
#include "databasetreewidget.h"



DatabaseTreeWidget::DatabaseTreeWidget(const QString& user, const QString& pwd, const QString& host, QWidget *p) 
	: QTreeWidget(p), user(user), pwd(user), host(host) {

	
}