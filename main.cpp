#include "AllLibraries.h"
#include "Sorter.h"

int main()
{
	srand(time(NULL));
	int size = 100;
	int* arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 200 + (-100);// / 1.1; test with <double>
	}
	Sorter<int> test;
	test.PrintArray(arr, size);
	test.qsortRecursive(arr, size);
	test.PrintArray(arr, size);
	/*for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "\t";
		if ((i + 1) % 10 == 0)
		{
			cout << endl;
		}
	}*/
	
	/*for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "\t";
		if ((i + 1) % 10 == 0)
		{
			cout << endl;
		}
	}*/
	delete[] arr;

	return 0;
}