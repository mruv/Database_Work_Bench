
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

	
public:
	explicit DatabaseResourcePicker(QWidget * = Q_NULLPTR);
	~DatabaseResourcePicker();

	void        SetupUi();
	void        CreateLayouts();
	void        CreateInputFields();

public slots:
	void        OnChangeDbms(const QString&);


signals:
	void        AddDatabaseResource(DatabaseResource *);

private:

	Q_OBJECT

	
	QFormLayout *mpMainLy;
	QPushButton *mpAddBtn;
	QComboBox   *mpDrivers;
	QLineEdit   *mpUser;
	QLineEdit   *mpPwd;
	QLineEdit   *mpHost;
	QSpinBox    *mpPort;
	QVBoxLayout *mpVbox;
	QHBoxLayout *mpHbox;
};



#endif