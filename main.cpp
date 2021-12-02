#include <iostream>
#include "Stack.h"
#include "Computer.h"

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
	Computer comp;
	comp.SetModel("Dell");
	comp.SetOS("Windows");
	comp.SetProcessor("Intel");
	cout << comp.GetModel() << endl;
	cout << comp.GetOS() << endl;
	cout << comp.GetProcessor() << endl;
	cout << comp.GetGeneration() << endl;
	cout << comp.SetBenchmark() << endl;



}
