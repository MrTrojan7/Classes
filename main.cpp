#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
	Stack stack;
	for (int i = 0; i < 5; i++)
	{
		stack.Push(i + 1);
	}
    
	while (!stack.IsEmpty())
	{
		cout << stack.Pop() << endl;
	}
}
