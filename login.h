
#ifndef LOGINFRAME_H
#define LOGINFRAME_H


#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QSizePolicy>
#include <QFrame>
#include <QLineEdit>
#include <QWidget>
#include <QString>



class LoginFrame : public QFrame {

	Q_OBJECT


public:
	LoginFrame(QWidget * = Q_NULLPTR);

signals:
	void connected();

public slots:
	void onPwdEdit(const QString&);
	void onUserEdit(const QString&);
	void connectToDb();


private:
	QLineEdit *aPwdEdit;
	QLineEdit *aLineEdit;
	QPushButton *aPushBtn;

	QFormLayout *fLy;

	QVBoxLayout *mainLy;
	QHBoxLayout *hBox;

};



#endif