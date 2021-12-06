#include <iostream>
#include "Stack.h"
#include "Computer.h"
#include "Book.h"

using namespace std;

int main()
{
	srand(time(0));
	/*Stack stack;
	for (int i = 0; i < 5; i++)
	{
		stack.Push(i + 1);
	}
    
	while (!stack.IsEmpty())
	{
		cout << stack.Pop() << endl;
	}*/

	/*Computer comp1;
	comp1.Show();
	Computer comp2("Dell", "Linux", "AMD", 10);
	comp2.Show();*/

	Book a;
	a.Show();


}
