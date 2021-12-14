#include "AllLibraries.h"
#include "Point.h"
#include "Counter.h"
#include "Fraction.h"
#include "Student.h"

int main()
{
	//setlocale(LC_ALL, "Russian");
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
	/*Counter a;
	a.SetStep(3);
	
	for (size_t i = 0; i < a.GetMax(); i++)
	{
		a.Print();
		Sleep(150);
		cout << endl;
		a.IncrByStep();
		system("cls");
		if (a.GetCurrent() >= 100)
		{
			a.Reset();
		}
		
	}*/
	/////////////////////////////
	//Fraction a(1, 4);
	//a.Print();
	///*a.SetReduction();
	//a.Print();*/
	//Fraction b(1.5); //проблема с производительностью при преобразовании в обычную дробь
	//b.Print();
	//cout << Fraction::Divided(a, b) << endl;
	//cout << Fraction::Equal(a, b) << endl;
	/////////////////////////////

	/*Student student1;
	student1.Show();
	Student student2("Ivanov", "Ivan", "Ivanovich", { 11, 12, 2000 }, "Gaidara 22", { 11111111, 222222, 333 }, { 9, 9, 9 });
	student2.SetEvaluations({ 8, 8, 8 });
	student2.Show();*/


	return 0;
}
