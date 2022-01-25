#pragma once
#include "AllLibraries.h"
#include "Sorter.h"

template <class T>

class Vector
{
private:
	T* _arr;
	unsigned int _size;
	unsigned int _capacity;
	void SetCapacity(unsigned int const capacity);
	void EnsureCapacity(unsigned int const size);
	void ReallocationCapacity();
	void ReallocationArray(const bool flag, unsigned int const index, const T& value);
	void CheckIndex(unsigned int const index);
	void Swap(T* _arr, unsigned int index_1, unsigned int index_2);
public:
	unsigned int GetSize() const;
	unsigned int GetCapacity() const;
	Vector();
	Vector(unsigned int const capacity = 10);
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
	void Clear();
	void TrimToSize();
	void SortAsc();
	void SortDesc();
	void RandomShuffle();
	void Reverse();
	void RandomFill();
	const int const IndexOf(const T& value) const;
	const int const LastIndexOf(const T& value) const;
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
	else if (capacity >= 10)
	{
		this->_capacity = capacity;
	}
}
///////// C-TORS

template<class T>
inline Vector<T>::Vector() : Vector<T>(10)
{
}

template<class T>
inline Vector<T>::Vector(unsigned int const capacity) //C-tor with param (capacity)
{
	SetCapacity(capacity);
	this->_size = capacity;
	this->_arr = new T[_capacity];
}

template<class T>
inline Vector<T>::Vector(unsigned int const size, const T& value) : Vector<T>(size)
{
	for (unsigned int i = 0; i < GetSize(); i++)
		this->_arr[i] = value;
}

template<class T>
inline Vector<T>::Vector(unsigned int const size, const T* arr) : Vector<T>(size)
{
	for (unsigned int i = 0; i < GetSize(); i++)
		this->_arr[i] = arr[i];
}

/////////// Methods

template<class T>
inline void Vector<T>::EnsureCapacity(unsigned int const size) // EnsureCapacity
{
	if (size < _capacity)
	{
		return;
	}
	else if (size >= _capacity)
	{
		this->_capacity = (_capacity * 1.5 + 1);
		ReallocationCapacity();
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
	EnsureCapacity(++_size);
	ReallocationArray(1, index, value);
}

template<class T>
inline void Vector<T>::CheckIndex(unsigned int const index) // Check Index
{
	if (index >= _capacity || index >= _size)
	{
		throw "error! bad index!";
	}
}

template<class T>
inline void Vector<T>::RemoveAt(unsigned int const index) // Remove At Index
{
	CheckIndex(index);
	--_size;
	ReallocationArray(0, index, _arr[index]); // _arr[index] - crutch...
}

template<class T>
inline void Vector<T>::PopBack() // PopBack
{
	RemoveAt(GetSize() - 1);
}

template<class T>
inline void Vector<T>::Remove(const T& value) // Remove by value
{
	for (int i = GetSize(); i >= 0; i--)
	{
		if (_arr[i] == value)
		{
			RemoveAt(i);
		}
	}
}

template<class T>
inline void Vector<T>::PopFront() // PopFront
{
	RemoveAt(0);
}

template<class T>
inline void Vector<T>::Clear() // Clear
{
	if (!IsEmpty())
		_size = 0;
}

template<class T>
inline void Vector<T>::TrimToSize() // TrimToSize
{
	this->_capacity = _size;
	ReallocationCapacity();
}

template<class T>
inline void Vector<T>::ReallocationCapacity() // Reallocation Capacity (Private Method)
{
	T* temp = new T[GetCapacity()];
	for (int i = 0; i < GetSize(); i++)
	{
		temp[i] = _arr[i];
	}
	if (_arr != nullptr) // maybe "~Vector"?
	{
		delete[] _arr;
		_arr = nullptr;
	}
	_arr = temp;
}

template<class T>
inline void Vector<T>::ReallocationArray(const bool flag, unsigned int const index, const T& value) // Reallocation Array (Private Method)
{
	T* temp = new T[GetCapacity()];
	bool remove_flag = false;
	bool insert_flag = false;
	for (int i = 0; i < GetSize(); i++)
	{
		if (i == index)
		{
			flag == true ? insert_flag = true : remove_flag = true;
			if (insert_flag)
			{
				temp[i] = value;
			}
		}
		temp[i + insert_flag] = _arr[i + remove_flag];
	}
	if (_arr != nullptr)
	{
		delete[] _arr;
		_arr = nullptr;
	}
	_arr = temp;
}

template<class T>
inline const int const Vector<T>::IndexOf(const T& value) const // indexOf
{
	for (int i = 0; i < GetSize(); i++)
	{
		if (_arr[i] == value)
			return i;
	}
	return -1;
}

template<class T>
inline const int const Vector<T>::LastIndexOf(const T& value) const //LastIndexOf
{
	for (int i = GetSize(); i >= 0; i--)
	{
		if (_arr[i] == value)
			return i;
	}
	return -1;
}

template<class T>
inline void Vector<T>::SortAsc() // SortAsc
{
	Sorter<T> temp;
	temp.qsortRecursive(_arr, _size);
}

template<class T>
inline void Vector<T>::SortDesc() // SortDesc
{
	Sorter<T> temp;
	temp.qsortRecursive(_arr, _size);
	Reverse();
}

template<class T>
inline void Vector<T>::RandomShuffle() // RandomShuffle
{
	random_shuffle(&arr[0], &arr[_size]);
}

template<class T>
inline void Vector<T>::Reverse() // Reverse
{
	bool flag = true;
	if (_size % 2 == 0)
		bool flag = false;
	for (int i = 0, j = _size - flag; i < j; i++, j--)
	{
		Swap(this->_arr, i, j);
	}
}

template<class T>
inline void Vector<T>::Swap(T* _arr, unsigned int index_1, unsigned int index_2) // Swap (private)
{
	CheckIndex(index_1);
	CheckIndex(index_2);
	T buffer = this->_arr[index_1];
	this->_arr[index_1] = this->_arr[index_2];
	this->_arr[index_2] = buffer;
}

template<class T>
inline void Vector<T>::RandomFill()
{
	srand(time(0));
	for (unsigned int i = 0; i < _size; i++)
	{
		arr[i] = rand();
	}
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
	if (IsEmpty())
	{
		cout << "Vector is empty!\n";
		return;
	}
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

