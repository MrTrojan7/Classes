#pragma once
#include "AllLibraries.h"

template <class T>
class Sorter
{
public:
    static void BubleSort(T* arr, int size);
    static void InsertSort(T* arr, int size);
    static void SelectSort(T* arr, int size);
    static void qsortRecursive(T* arr, int size);
    void PrintArray(T* arr, int size);
};

template<class T>
inline void Sorter<T>::BubleSort(T* arr, int size)
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

template<class T>
inline void Sorter<T>::InsertSort(T* arr, int size)
{
    for (int i = 1; i < size; i++)
        for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) // ���� j>0 � ������� j-1 > j, x-������ int
            swap(arr[j - 1], arr[j]);     // ������ ������� �������� j � j-1
}

template<class T>
inline void Sorter<T>::SelectSort(T* arr, int size)
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

template<class T>
inline void Sorter<T>::qsortRecursive(T* arr, int size) // have a problem
{
    //��������� � ������ � � ����� �������
    int i = 0;
    int j = size - 1;
    //����������� ������� �������
    T mid = arr[size / 2];

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
            T tmp = arr[i];
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
        qsortRecursive(&arr[i], size - i);
    }
}

template<class T>
inline void Sorter<T>::PrintArray(T* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "\t";
        if ((i + 1) % 5 == 0)
        {
            cout << "\n";
        }
    }
    cout << "\n";
}
