#pragma warning(disable : 4996);
#include "AllLibraries.h"
#include "MyDate.h"

int main()
{
	srand(time(NULL));
	MyDate t;
	t.Print();
	MyDate f(17, 3, 1997);
	f.Print();
	cout << t - f;
}