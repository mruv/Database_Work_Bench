
#ifndef DATABASERESOURCEPICKER_H
#define DATABASERESOURCEPICKER_H


#include "databaseresource.h"

#include <QDialog>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpinBox>
#include <QMap>
#include <QString>


class DatabaseResourcePicker : public QDialog {

	Q_OBJECT


public:
	DatabaseResourcePicker(QWidget * = Q_NULLPTR);

	void setupUi();
	void createLayouts();
	void createInputFields();


signals:
	void addDatabaseResource(DatabaseResource *);

private:

	QFormLayout *mainLy;
	QPushButton *addBtn;
	QComboBox   *drivers;
	QLineEdit   *user;
	QLineEdit   *pwd;
	QLineEdit   *host;
	QSpinBox    *port;
	QVBoxLayout *vbox;
	QHBoxLayout *hbox;
};



#endif