
#include "databaseresourcepicker.h"


DatabaseResourcePicker::DatabaseResourcePicker(QWidget *p) 
	: QDialog(p), mpMainLy(new QFormLayout()), mpAddBtn(new QPushButton("Add")),
		mpDrivers(new QComboBox()), mpUser(new QLineEdit()), mpPwd(new QLineEdit()), mpHost(new QLineEdit()),
			mpPort(new QSpinBox()) {

}

DatabaseResourcePicker::~DatabaseResourcePicker() { }

void DatabaseResourcePicker::SetupUi() {

	CreateInputFields();
	CreateLayouts();

	setWindowTitle("Database Resource");
	setFixedSize(400, 300);
}


void DatabaseResourcePicker::CreateLayouts() {

	mpVbox = new QVBoxLayout(this);
	mpHbox = new QHBoxLayout();

	mpMainLy->addRow(tr("Database Driver"), mpDrivers);
	mpMainLy->addRow(tr("Host"), mpHost);
	mpMainLy->addRow(tr("Port"), mpPort);
	mpMainLy->addRow(tr("User"), mpUser);
	mpMainLy->addRow(tr("Password"), mpPwd);
	mpMainLy->addRow(tr(""), mpAddBtn);

	//mpMainLy->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);

	mpHbox->addStretch();
	mpHbox->addLayout(mpMainLy);
	mpHbox->addStretch();

	mpVbox->addStretch();
	mpVbox->addLayout(mpHbox);
	mpVbox->addStretch();
}

void DatabaseResourcePicker::OnChangeDbms(const QString& newDbms) {

	if (newDbms == "MySQL") {
		mpPort->setValue(3306);
	} else if (newDbms == "PostgreSQL") {
		mpPort->setValue(5214);
	} else if (newDbms == "SQLite") {
		mpPort->setValue(8989);
	} else {
		mpPort->setValue(1);
	}
}

void DatabaseResourcePicker::CreateInputFields() {

	mpPwd->setEchoMode(QLineEdit::Password);
	mpAddBtn->setDisabled(true);

	mpPort->setRange(1, 65535);

	// available
	QStringList            available_drivers;
	QMap<QString, QString> drivers_map;

	for(QString driver : QSqlDatabase::drivers()) {

		if(driver.contains("mysql", Qt::CaseInsensitive) && !available_drivers.contains("MySQL")){
			available_drivers.append("MySQL");
			drivers_map.insert(tr("MySQL"), tr( "QMYSQL"));
		}

		if(driver.contains("sqlite", Qt::CaseInsensitive) && !available_drivers.contains("SQLite")){
			available_drivers.append("SQLite");
			drivers_map.insert(tr("SQLite"), tr("QSQLITE"));
		}

		if(driver.contains("psql", Qt::CaseInsensitive) && !available_drivers.contains("PostgreSQL")){
			available_drivers.append("PostgreSQL");
			drivers_map.insert(tr("PostgreSQL"), tr( "QPSQL"));
		}
	}

	mpDrivers->addItems(available_drivers);

	// initial Dbms and mpPort
	OnChangeDbms(mpDrivers->currentText());


	QObject::connect(mpHost, &QLineEdit::textEdited, [=](){
		if(mpHost->text().length() > 0 && mpPwd->text().length() > 0 && mpUser->text().length() > 0) {

			mpAddBtn->setEnabled(true);
		} else {
			mpAddBtn->setDisabled(true);
		}
	});

	QObject::connect(mpUser, &QLineEdit::textEdited, [=](){
		if(mpHost->text().length() > 0 && mpPwd->text().length() > 0 && mpUser->text().length() > 0) {

			mpAddBtn->setEnabled(true);
		} else {
			mpAddBtn->setDisabled(true);
		}
	});

	QObject::connect(mpPwd, &QLineEdit::textEdited, [=](){
		if(mpHost->text().length() > 0 && mpPwd->text().length() > 0 && mpUser->text().length() > 0) {

			mpAddBtn->setEnabled(true);
		} else {
			mpAddBtn->setDisabled(true);
		}
	});

	QObject::connect(mpAddBtn, &QPushButton::clicked, [=](){
		
		emit AddDatabaseResource(
			new DatabaseResource(
				mpUser->text(), mpPwd->text(),
				mpHost->text(), drivers_map.value(mpDrivers->currentText()),
				mpDrivers->currentText()
				)
			);

		close();
	});

	QObject::connect(mpDrivers, &QComboBox::currentTextChanged, this, &DatabaseResourcePicker::OnChangeDbms);
}