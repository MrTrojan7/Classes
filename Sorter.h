#pragma once
#include "AllLibraries.h"

template <class Arr, class Size>
class Sorter
{
private:
    Arr* arr;
    Size size;
public:
    Sorter(Arr* _arr, Size _size);
    ~Sorter();
    const Size GetSize() const;
    void SetSize(Size _size);
    void qsortRecursive(Arr* arr, Size size);
    void Print(Arr* arr, Size size);
};
    
template<class Arr, class Size>
inline Sorter<Arr, Size>::Sorter(Arr* _arr, Size _size)
{
    SetSize(_size);
    arr = nullptr;
   /* for (auto i = 0; i < GetSize(); i++)
    {
        arr[i] = _arr[i];
    }*/
}

template<class Arr, class Size>
inline Sorter<Arr, Size>::~Sorter()
{
    if (arr != nullptr)
    {
        delete[] arr;
        arr = nullptr;
    }
}

template<class Arr, class Size>
inline const Size Sorter<Arr, Size>::GetSize() const
{
    return size;
}

template<class Arr, class Size>
inline void Sorter<Arr, Size>::SetSize(Size _size)
{
    this->size = _size;
}

template<class Arr, class Size>
inline void Sorter<Arr, Size>::qsortRecursive(Arr* arr, Size size)
{
    //��������� � ������ � � ����� �������
    int i = 0;
    int j = size - 1;
    /*static int count = 0;
    ++count;
    if (count % 10 == 0)
    {
        cout << count << endl;

    }*/
    //����������� ������� �������
    int mid = arr[size / 2];

    //����� ������
    do {
        //��������� ��������, ���� ��, ������� ����� ���������� � ������ �����
        //� ����� ����� ������� ����������(��������� �� �����) ��������, ������� ������ ������������
        while (arr[i] < mid) {
            i++;
        }
        //� ������ ����� ���������� ��������, ������� ������ ������������
        while (arr[j] > mid) {
            j--;
        }

        //������ �������� �������
        if (i <= j) {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);


    //����������� ������, ���� ��������, ��� �����������
    if (j > 0) {
        //"����� �����"
        qsortRecursive((Arr*)arr, (Size)j + 1);
    }
    if (i < size) {
        //"����� �����"
        qsortRecursive((Arr*)arr[i], (Size)size - i);
    }
}

template<class Arr, class Size>
inline void Sorter<Arr, Size>::Print(Arr* arr, Size size)
{
    for (auto i = 0; i < size; i++)
    {
        cout << arr[i] << "\t";
        if ((i + 1) % 5 == 0)
        {
            cout << endl;
        }
    }
}
