#ifndef DATE_H
#define DATE_H

#include <QString>

class DateClass {
	char day;
	char month;
	int year;

public:	
	DateClass(char day, char month, int year) : day{day}, month{month}, year{year}
	{ }
	~DateClass()
	{ }
	
	QString qstr();
};


#endif
