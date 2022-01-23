#include "AllLibraries.h"
#include "Sorter.h"
#include "Vector.h"

int main()
{
	srand(time(NULL));
	Vector<int> test(15, 5);
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
	test.Print();
	return 0;
}