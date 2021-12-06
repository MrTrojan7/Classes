#include <iostream>
#include <Windows.h>
#include "Point.h"
#include "Counter.h"

using namespace std;

int main()
{
	/////////////////////////////
	//point:

	/*cout << "a:\n";
	Point a;
	a.Print();
	cout << "b:\n";
	Point b(3, 2);
	b.Print();
	b.ShiftX(-1);
	b.Print();*/
	/////////////////////////////
	Counter a;
	a.SetStep(2);
	
	for (size_t i = 0; i < 30; i++)
	{
		a.Print();
		Sleep(130);
		cout << endl;
		a.IncrByStep();
		
	}
	return 0;
}
