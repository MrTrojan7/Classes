#include "MyDate.h"

MyDate::MyDate()
{
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	cout << "Current Datetime:" << asctime(timeinfo) << endl;
}
