#include "Stack.h"

int Stack::quantity = 0;

Stack::Stack()
{
	quantity++;
	this->size = 0;
	this->capacity = 20;
	this->exp_ratio = 2;
	this->buffers = new int[capacity];

}

void Stack::Push(int value)
{
	buffers[size] = value;
	++size;
	if (size == capacity)
	{
		Reload();
	}
}

int Stack::Pop()
{
	return buffers[--size];
}

bool Stack::IsEmpty()
{
	return size == 0;
}

void Stack::SetRatio(int k)
{
	exp_ratio = k;
}

int Stack::GetSize() const
{
	return size;
}

int Stack::GetRatio() const
{
	return exp_ratio;
}

int Stack::GetQuantity()
{
	return quantity;
}

Stack::~Stack()
{
	quantity--;
	delete[] this->buffers;
}

void Stack::Reload()
{
	int* newArray = new int[capacity *= exp_ratio];
	for (int i = 0; i < capacity; i++)
	{
		newArray[i] = buffers[i];
	}
	delete[] buffers;
	buffers = newArray;
}