
#include "login.h"





LoginFrame::LoginFrame(QWidget *p) : QFrame(p) {

	aPwdEdit = new QLineEdit();
	aLineEdit = new QLineEdit();
	aPushBtn = new QPushButton("Connect");

	aPushBtn->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
	aLineEdit->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
	aPwdEdit->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
	aPwdEdit->setPlaceholderText("*********");
	aLineEdit->setPlaceholderText("e.g. root");
	aPushBtn->setEnabled(false);

	fLy = new QFormLayout();
	fLy->addRow(new QLabel("User:"), aLineEdit);
	fLy->addRow(new QLabel("Password:"), aPwdEdit);
	fLy->addRow(new QLabel(), aPushBtn);
		

	mainLy = new QVBoxLayout(this);
	hBox = new QHBoxLayout();

	hBox->addStretch();
	hBox->addLayout(fLy);
	hBox->addStretch();

	mainLy->addStretch();
	mainLy->addLayout(hBox);
	mainLy->addStretch();

	QObject::connect(
		aPwdEdit, &QLineEdit::textEdited, this, &LoginFrame::onPwdEdit
		);

	QObject::connect(
		aLineEdit, &QLineEdit::textEdited, this, &LoginFrame::onUserEdit
		);

	QObject::connect(aPushBtn, &QPushButton::clicked, this, &LoginFrame::connectToDb);

}

void LoginFrame::onPwdEdit(const QString& newText) {

	if(newText.length() > 0 && aLineEdit->text().length() > 0) {
		aPushBtn->setEnabled(true);
	} else {
		aPushBtn->setDisabled(true);
	}
}

void LoginFrame::onUserEdit(const QString& newText) {

	if(newText.length() > 0 && aPwdEdit->text().length() > 0) {

		aPushBtn->setEnabled(true);
	} else {
		aPushBtn->setDisabled(true);
	}
}

void LoginFrame::connectToDb() {

	emit connected();
}