#include "AllLibraries.h"
#include "MyDate.h"

int main()
{
	srand(time(NULL));
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	cout << "Current Datetime:" << asctime(timeinfo) << endl;


}