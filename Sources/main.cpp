#include <QDate>
#include <QApplication>
#include <QThread>
#include "PageWidget.h"

int main(int argc, char** argv)
{
	QApplication app(argc, argv);

	QString styleStr = "								 \
		QPushButton#delbtn:enabled { background-color: #cccccc; }		 \
		QPushButton#editbtn:enabled { background-color: #cccccc; }		 \
		QPushButton#addbtn:enabled { background-color: #cccccc; }		 \
		QLabel { font-size: 14pt; font-weight: 100; }				 \
		QLabel#Labellabel { font-size: 13pr; font-weight: 200; }		 \
		QLabel#inputLabel { font-size: 15pt; font-weight: 200; }		 \
		QLabel#DateLabel { font-size: 25pt; font-weight: 50; }			 \
		QLineEdit { font-size: 14pt; font-weight: 100; }			 \
		QPushButton { font-size: 14pt; font-weight: 100; }			 \
	";			 
	
	app.setStyleSheet(styleStr);

	QDate Date(QDate::currentDate());
	PageWidget PW(Date.day(), Date.month(), Date.year(), nullptr);

	PW.show();

	app.exec();

	return 0;
}
