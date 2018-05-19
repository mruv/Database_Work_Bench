
#include "tabledatapage.h"


TableDataPage::TableDataPage(QTableView *view, QSqlTableModel *model, QWidget *parent)
	: QFrame(parent), view(view), model(model) {

	setFrameStyle(QFrame::Plain);
}


TableDataPage::~TableDataPage() { }