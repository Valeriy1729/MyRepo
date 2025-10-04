#include <QDate>
#include <QApplication>
#include <QPalette>
#include <QMainWindow>
#include "PageWidget.h"


int main(int argc, char** argv)
{
	int BORDER_SIZE = 6;

	QApplication app(argc, argv);

	QString styleStr = R"(						
		QPushButton#delbtn { background-color: #b6e0f3; color: #5ebae5; }
		QPushButton#delbtn:enabled { background-color: #7bc7ea; color: #000000; }
		QPushButton#editbtn { background-color: #b6e0f3; color: #5ebae5; }	
		QPushButton#editbtn:enabled { background-color: #7bc7ea; color: #000000; }
		QPushButton#addbtn { background-color: #b6e0f3; color: #5ebae5; }	
		QPushButton#addbtn:enabled { background-color: #7bc7ea; color: #000000; }
		QLabel { font-size: 14pt; font-weight: 100;}				
		QLabel#Labellabel { font-size: 13pt; font-weight: 100; }	
		QLabel#inputLabel { font-size: 14pt; font-weight: 200; }
		QLabel#LabelTask { font-size: 14pt; font-weight: 200; }
		QLabel#DateLabel { font-size: 25pt; font-weight: 50; color: #000000; }
		QLineEdit { font-size: 14pt; font-weight: 100; background-color: #f0f9fd; }
		QPushButton { font-size: 15pt; font-weight: 100; }			
		PageWidget  { font-size: 15pt; font-weight: 100; color: #000000; }
		QMainWindow { border: 4px solid #8acdec; border-radius: 5px; }
	)";			 
	
	app.setStyleSheet("");
	app.setStyleSheet(styleStr);
	QDate Date(QDate::currentDate());

	QMainWindow W;

	W.setFixedSize(700 + 2 * BORDER_SIZE, 400 + 2 * BORDER_SIZE);
	W.move(200, 200);
	W.setWindowTitle("T O D O      L I S T");

	PageWidget PW(Date.day(), Date.month(), Date.year(), &W);
	PW.move(BORDER_SIZE, BORDER_SIZE);
	PW.load();

	QPalette pal = PW.palette();
	pal.setBrush(QPalette::Window, QBrush(QPixmap("./403.jpg")));
	PW.setPalette(pal);
	PW.setAutoFillBackground(true);

	//W.setWindowFlags(Qt::FramelessWindowHint);
	W.show();

	app.exec();
	PW.save();

	return 0;
}
