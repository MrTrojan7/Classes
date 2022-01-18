#include "AllLibraries.h"
#include "Sorter.h"

int main()
{
	srand(time(NULL));
	int size = 50;
	double* arr = new double[size]; //stack overflow
	for (int i = 0; i < size; i++)
	{
		double num = (double)(rand() / 20.15);
		arr[i] = num;
	}
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "\t";
		if ((i + 1) % 5 == 0)
		{
			cout << endl;
		}
	}
	qsortRecursive<double, int>(arr, size);
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "\t";
		if ((i + 1) % 5 == 0)
		{
			cout << endl;
		}
	}
	delete[] arr;

	return 0;
}