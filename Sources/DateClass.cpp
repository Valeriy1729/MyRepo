#include "DateClass.h"

QString DateClass::qstr()
{
	char str[128] {0};
	const char* format = "\t\tDATE:   %hhd / %hhd / %d ---";

	sprintf(str, format, day, month, year);

	return QString(str);
}	
