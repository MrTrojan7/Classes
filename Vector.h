#pragma once
#include "AllLibraries.h"

template <class T>

class Vector
{
private:
	T* _arr;
	unsigned int _size;
	unsigned int _capacity;
	void SetCapacity(unsigned int const capacity);
	void EnsureCapacity(unsigned int const size);
public:
	unsigned int GetSize() const;
	unsigned int GetCapacity() const;
	Vector(unsigned int const size = 10);
	Vector(unsigned int const size, const T& value);
	Vector(unsigned int const size, const T* arr);
	////////////////
	bool IsEmpty() const;
	void PushBack(const T& value);
	void PushFront(const T& value);
	void Insert(const T& value, unsigned int const index);
	void RemoveAt(unsigned int const index);
	void Remove(const T& value);
	void PopFront();
	void PopBack();
	void CheckIndex(unsigned int const index);
	~Vector();
	void Print();
};

template<class T>
inline unsigned int Vector<T>::GetSize() const // GetSize
{
	return _size;
}

template<class T>
inline unsigned int Vector<T>::GetCapacity() const // GetCapacity
{
	return _capacity;
}

template<class T>
inline void Vector<T>::SetCapacity(unsigned int capacity) // SetCapacity
{
	if (capacity < 10)
	{
		SetCapacity(10);
	}
	else if (capacity == 10)
	{
		this->_capacity = capacity;
	}
	else
	{
		this->_capacity = (capacity * 1.5 + 1);
	}
}

template<class T>
inline Vector<T>::Vector(unsigned int const size) //C-tor with param (capacity)
{
	SetCapacity(size);
	this->_size = size;
	this->_arr = new T[_capacity];
}

template<class T>
inline Vector<T>::Vector(unsigned int size, const T& value) : Vector<T>(size)
{
	for (unsigned int i = 0; i < GetSize(); i++)
		this->_arr[i] = value;
}

template<class T>
inline Vector<T>::Vector(unsigned int size, const T* arr) : Vector<T>(size)
{
	for (unsigned int i = 0; i < GetSize(); i++) // not good... // search solution
		this->_arr[i] = arr[i];
}

template<class T>
inline void Vector<T>::EnsureCapacity(unsigned int const size)
{
	if (size < _capacity)
	{
		return;
	}
	else if (size >= _capacity)
	{
		this->_capacity = (_capacity * 1.5 + 1);
		T* temp = new T[GetCapacity()];
		for (int i = 0; i < GetSize(); i++)
		{
			temp[i] = _arr[i];
		}
		if (_arr != nullptr) // question
		{
			delete[] _arr;
			_arr = nullptr;
		}
		_arr = temp;
	}
}

template<class T>
inline bool Vector<T>::IsEmpty() const // IsEmpty
{
	return _size == 0;
}

template<class T>
inline void Vector<T>::PushBack(const T& value) // PushBack
{
	EnsureCapacity(GetSize() + 1);
	_arr[_size++] = value;
}

template<class T>
inline void Vector<T>::PushFront(const T& value) // PushFront
{
	int index = 0;
	Insert(value, index);
}

template<class T>
inline void Vector<T>::Insert(const T& value, unsigned int const index) // Insert
{
	CheckIndex(index);
	bool flag = false;
	EnsureCapacity(++_size);
	T * temp = new T[GetCapacity()];
	temp[index] = value;
	for (int i = 0; i < GetSize(); i++)
	{
		if (i == index)
		{
			flag = true;
		}
		temp[i + flag] = _arr[i];
	}
	if (_arr != nullptr)
	{
		delete[] _arr;
		_arr = nullptr;
	}
	_arr = temp;
}

template<class T>
inline void Vector<T>::CheckIndex(unsigned int const index) // Check Index
{
	if (index >= _capacity)
	{
		throw "error! bad index!";
	}
}

template<class T>
inline void Vector<T>::RemoveAt(unsigned int const index) // Remove At Index
{
	CheckIndex(index);
	bool flag = false;
	--_size;
	T* temp = new T[GetCapacity()];
	for (int i = 0; i < GetSize(); i++)
	{
		if (i == index)
		{
			flag = true;
		}
		temp[i] = _arr[i + flag];
	}
	if (_arr != nullptr)
	{
		delete[] _arr;
		_arr = nullptr;
	}
	_arr = temp;
}

template<class T>
inline void Vector<T>::PopBack()
{
	// --size
	RemoveAt(GetSize() - 1);
}

template<class T>
inline void Vector<T>::Remove(const T& value)
{
	for (int i = GetSize(); i > 0; i--)
	{
		if (_arr[i] == value)
		{
			RemoveAt(i);
		}
	}
}

template<class T>
inline void Vector<T>::PopFront()
{
	RemoveAt(0);
}








template<class T>
inline Vector<T>::~Vector() // DEST
{
	if (_arr != nullptr)
	{
		delete[] _arr;
		_arr = nullptr;
	}
}

template<class T>
inline void Vector<T>::Print() // Print
{
	for (unsigned int i = 0; i < GetSize(); i++)
	{
		cout << _arr[i] << ", ";
		if ((i + 1) % 5 == 0)
		{
			cout << "\n";
		}
	}
	cout << "\n";
}

