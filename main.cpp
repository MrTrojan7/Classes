#include "AllLibraries.h"
#include "Sorter.h"
#include "Vector.h"

void Foo1(int* arr, int size);
void Foo2(int* arr, int size);

int main()
{
	srand(time(NULL));
	/*Vector<int> test(15, 5);
	cout << test.GetCapacity() << endl;
	cout << test.GetSize() << endl;
	test.Print();
	test.PushFront(2);
	test.PushBack(7);
	test.PushBack(7);
	test.PushBack(7);
	test.PushBack(7);
	test.PushBack(7);
	test.PushBack(7);
	test.PushBack(7);
	test.PushBack(7);
	test.PushBack(7);
	test.PushBack(8);
	test.Insert(9, 3);
	cout << test.GetCapacity() << endl;
	cout << test.GetSize() << endl;
	test.Print();
	test.PopBack();
	test.RemoveAt(0);
	test.Remove(9);
	cout << test.GetCapacity() << endl;
	cout << test.GetSize() << endl;
	test.Print();*/
	int size = 100;
	int* arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 30;
	}
	Vector <int> test2(size, arr);
	//Foo1(arr, size);
	cout << test2.GetCapacity() << endl;
	cout << test2.GetSize() << endl;
	test2.Print();
	test2.PushBack(777);
	test2.PushBack(777);
	test2.PushBack(700);
	test2.PushFront(666);
	cout << test2.GetCapacity() << endl;
	cout << test2.GetSize() << endl;
	test2.Print();

	/*test2.Clear();
	cout << test2.GetCapacity() << endl;
	cout << test2.GetSize() << endl;
	test2.Print();
	test2.PushBack(777);
	test2.PushFront(657);
	test2.PushFront(65);
	test2.PushFront(6);
	test2.RemoveAt(0);
	test2.Print();*/
	cout << test2.IndexOf(20) << endl;
	cout << test2.LastIndexOf(20) << endl;
	cout << test2.GetCapacity() << endl;
	cout << test2.GetSize() << endl;
	test2.Print();
	test2.SortAsc();
	test2.Print();
	test2.SortDesc();
	cout << endl;
	cout << test2.GetCapacity() << endl;
	cout << test2.GetSize() << endl;
	test2.Print();
	test2.RandomShuffle();
	test2.Print();


	delete[] arr;
	return 0;
}

void Foo1(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << ", ";
		if ((i + 1) % 5 == 0)
		{
			cout << "\n";
		}
	}
	cout << "\n\n";
	Foo2(arr, size);
}

void Foo2(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << ", ";
		if ((i + 1) % 5 == 0)
		{
			cout << "\n";
		}
	}
	cout << "\n\n";
}
