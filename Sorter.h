#pragma once
#include "AllLibraries.h"

template <class Arr, class Size>
class Sorter
{
private:
    Arr* arr = nullptr;
    Size size;
public:
    Sorter(Arr* _arr, Size _size);
    ~Sorter();
    const Size GetSize() const;
    void SetSize(Size _size);
    static void BubleSort(Arr* arr, Size size);
    static void InsertSort(Arr* arr, Size size);
    static void SelectSort(Arr* arr, Size size);
    static void qsortRecursive(Arr* arr, Size size);
    void Print(Arr* arr, Size size);
};
    
template<class Arr, class Size>
inline Sorter<Arr, Size>::Sorter(Arr* _arr, Size _size)
{
    SetSize(_size);
    arr = new Arr[GetSize()];
    for (auto i = 0; i < GetSize(); i++)
    {
        arr[i] = _arr[i];
    }
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
inline void Sorter<Arr, Size>::BubleSort(Arr* arr, Size size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = (size - 1); j > i; j--) // ��� ���� ��������� ����� i-���
        {
            if (arr[j - 1] > arr[j]) // ���� ������� ������� ������ �����������
            {
                int temp = arr[j - 1]; // ������ �� �������
                arr[j - 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

template<class Arr, class Size>
inline void Sorter<Arr, Size>::InsertSort(Arr* arr, Size size)
{
    for (int i = 1; i < size; i++)
        for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) // ���� j>0 � ������� j-1 > j, x-������ int
            swap(arr[j - 1], arr[j]);     // ������ ������� �������� j � j-1
}

template<class Arr, class Size>
inline void Sorter<Arr, Size>::SelectSort(Arr* arr, Size size)
{
    int min = 0;
    int buf = 0;
    for (int i = 0; i < size; i++)
    {
        min = i; // �������� ����� ������� ������, ��� ������ � ����������� ���������
        // � ����� ������ �������� ����� ������ � ����������� ���������
        for (int j = i + 1; j < size; j++)
            min = (arr[j] < arr[min]) ? j : min;
        // c������ ������������ ����� ��������, ������� ��� ������� � �������
        if (i != min)
        {
            buf = arr[i];
            arr[i] = arr[min];
            arr[min] = buf;
        }
    }
}

template<class Arr, class Size>
inline void Sorter<Arr, Size>::qsortRecursive(Arr* arr, Size size) // have a problem
{
    //��������� � ������ � � ����� �������
    int i = 0;
    int j = size - 1;
    //����������� ������� �������
    Size mid = arr[size / 2];

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
        qsortRecursive(arr, j + 1);
    }
    if (i < size) {
        //"������ �����"
        qsortRecursive(arr, size - i);
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
