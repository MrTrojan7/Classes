#include "AllLibraries.h"
#include "Sorter.h"

int main()
{
	srand(time(NULL));
	int size = 100;
	int* arr = new int[size]; //stack overflow
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 200 + (-100);
	}
	Sorter<int, int> test(arr, size);
	test.Print(arr, size);
	cout << endl;
	test.qsortRecursive(arr, size);
	test.Print(arr, size);
	/*for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "\t";
		if ((i + 1) % 10 == 0)
		{
			cout << endl;
		}
	}*/
	cout << endl;
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