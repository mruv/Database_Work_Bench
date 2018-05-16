
#include "databaseresourcepicker.h"


#include <QSqlDatabase>
#include <QStringList>





DatabaseResourcePicker::DatabaseResourcePicker(QWidget *p) 
	: QDialog(p), mainLy(new QFormLayout()), addBtn(new QPushButton("Add")),
		drivers(new QComboBox()), user(new QLineEdit()), pwd(new QLineEdit()), host(new QLineEdit()),
			port(new QSpinBox()) {

}


void DatabaseResourcePicker::setupUi() {

	createInputFields();
	createLayouts();

	setWindowTitle("Database Resource");
	setFixedSize(400, 300);
}


void DatabaseResourcePicker::createLayouts() {

	vbox = new QVBoxLayout(this);
	hbox = new QHBoxLayout();

	mainLy->addRow(tr("Database Driver"), drivers);
	mainLy->addRow(tr("Host"), host);
	mainLy->addRow(tr("Port"), port);
	mainLy->addRow(tr("User"), user);
	mainLy->addRow(tr("Password"), pwd);
	mainLy->addRow(tr(""), addBtn);

	//mainLy->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);

	hbox->addStretch();
	hbox->addLayout(mainLy);
	hbox->addStretch();

	vbox->addStretch();
	vbox->addLayout(hbox);
	vbox->addStretch();
}

void DatabaseResourcePicker::createInputFields() {

	pwd->setEchoMode(QLineEdit::Password);
	addBtn->setDisabled(true);

	port->setRange(1, 65535);
	port->setValue(3306);

	// available
	QStringList avl;
	QMap<QString, QString> drvrsMap;

	for(QString driver : QSqlDatabase::drivers()) {

		if(driver.contains("mysql", Qt::CaseInsensitive) && !avl.contains("MySQL")){
			avl.append("MySQL");
			drvrsMap.insert(tr("MySQL"), tr( "QMYSQL"));
		}

		if(driver.contains("sqlite", Qt::CaseInsensitive) && !avl.contains("SQLite")){
			avl.append("SQLite");
			drvrsMap.insert(tr("SQLite"), tr("QSQLITE"));
		}

		if(driver.contains("psql", Qt::CaseInsensitive) && !avl.contains("PostgreSQL")){
			avl.append("PostgreSQL");
			drvrsMap.insert(tr("PostgreSQL"), tr( "QPSQL"));
		}
	}

	drivers->addItems(avl);


	QObject::connect(host, &QLineEdit::textEdited, [=](){
		if(host->text().length() > 0 && pwd->text().length() > 0 && user->text().length() > 0) {

			addBtn->setEnabled(true);
		} else {
			addBtn->setDisabled(true);
		}
	});

	QObject::connect(user, &QLineEdit::textEdited, [=](){
		if(host->text().length() > 0 && pwd->text().length() > 0 && user->text().length() > 0) {

			addBtn->setEnabled(true);
		} else {
			addBtn->setDisabled(true);
		}
	});

	QObject::connect(pwd, &QLineEdit::textEdited, [=](){
		if(host->text().length() > 0 && pwd->text().length() > 0 && user->text().length() > 0) {

			addBtn->setEnabled(true);
		} else {
			addBtn->setDisabled(true);
		}
	});

	QObject::connect(addBtn, &QPushButton::clicked, [=](){
		
		emit addDatabaseResource(
			new DatabaseResourceTreeItem(
				user->text(), pwd->text(),
				host->text(), drvrsMap.value(drivers->currentText())
				)
			);

		close();
	});
}