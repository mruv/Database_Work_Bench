
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
#include <QSqlDatabase>
#include <QStringList>


class DatabaseResourcePicker : public QDialog {

	Q_OBJECT


public:
	explicit DatabaseResourcePicker(QWidget * = Q_NULLPTR);
	~DatabaseResourcePicker();

	void SetupUi();
	void CreateLayouts();
	void CreateInputFields();

	void OnChangeDbms(const QString&);


signals:
	void AddDatabaseResource(DatabaseResource *);

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