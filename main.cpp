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
	a.SetStep(3);
	
	for (size_t i = 0; i < a.GetMax(); i++)
	{
		a.Print();
		/*Sleep(150);*/
		cout << endl;
		a.IncrByStep();
		system("cls");
		/*if (a.GetCurrent() >= 100)
		{
			a.Reset();
		}*/
		
	}
	return 0;
}
