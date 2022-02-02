#pragma warning(disable : 4996);
#include "AllLibraries.h"
#include "MyDate.h"

int main()
{
	srand(time(NULL));
	MyDate t(27, 2, 2020);
	t.Print();
	MyDate f(27, 2, 2020);
	f.Print();
	//cout << t - f << "\n";
	cout << f.DayOfWeek() << "\n";
	//f++;
	//f++;
	//f++;
	////f++;
	//f.Print();
	cout << t.DayOfWeek() << "\n";
	//f - 6;
	//f.Print();
	cout << f.DayOfWeek() << "\n";
}