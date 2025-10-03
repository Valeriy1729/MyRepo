#include "DateClass.h"

QString DateClass::qstr()
{
	char str[128] {0};
	const char* format = "\t----- - -  -  %c%hhd / %c%hhd / %d  -  - - - -----";

	sprintf(str, format, (day < 10) ? '0' : ' ', day, (month < 10) ? '0' : ' ', month, year);

	return QString(str);
}	
