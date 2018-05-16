
#ifndef DATABASERESOURCEPICKER_H
#define DATABASERESOURCEPICKER_H


#include <QDialog>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>


class DatabaseResourcePicker : public QDialog {

	Q_OBJECT


public:
	DatabaseResourcePicker(QWidget * = Q_NULLPTR);

	void setupUi();


signals:

private:

	QFormLayout *mainLy;
	QPushButton *addBtn;
	QLineEdit   *user;
	QLineEdit   *pwd;
	QLineEdit   *host;
};



#endif