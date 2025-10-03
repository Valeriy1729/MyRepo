#include <QApplication>
#include "PageWidget.h"

int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	
	PageWidget PW(1, 1, 2000, nullptr);
	PW.show();

	app.exec();
	return 0;
}
