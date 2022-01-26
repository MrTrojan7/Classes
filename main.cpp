#include "AllLibraries.h"
#include "Sorter.h"
#include "Vector.h"

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
	/*Vector <int> test2(size, arr);
	test2.PushBack(777);
	test2.PushBack(777);
	test2.PushBack(700);
	test2.PushFront(666);
	cout << test2.GetCapacity() << endl;
	cout << test2.GetSize() << endl;
	test2.Print();*/

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

	/*cout << test2.IndexOf(20) << endl;
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
	test2.Print();*/

	/*Vector <int> test3(12,2);
	Vector <int> test4(12,2);
	test3.GetSize();
	cout << test3.GetCapacity() << endl;
	cout << test3.GetSize() << endl;
	test3.Print();
	test4.Print();
	test3.Equal(test4);
	cout << test2.GetElementAt(200) << endl;*/

	Vector <int> test5(size, arr);
	Vector <int> test6(15);
	test5.Print();
	test6.Print();
	test6.Clone(test5);
	test6.PushBack(321);
	test5.Print();
	test6.Print();

	delete[] arr;
	return 0;
}