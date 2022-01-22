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
        for (int j = (size - 1); j > i; j--) // для всех элементов после i-ого
        {
            if (arr[j - 1] > arr[j]) // если текущий элемент меньше предыдущего
            {
                int temp = arr[j - 1]; // меняем их местами
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
        for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) // пока j>0 и элемент j-1 > j, x-массив int
            swap(arr[j - 1], arr[j]);     // меняем местами элементы j и j-1
}

template<class T>
inline void Sorter<T>::SelectSort(T* arr, int size)
{
    int min = 0;
    int buf = 0;
    for (int i = 0; i < size; i++)
    {
        min = i; // запомним номер текущей ячейки, как ячейки с минимальным значением
        // в цикле найдем реальный номер ячейки с минимальным значением
        for (int j = i + 1; j < size; j++)
            min = (arr[j] < arr[min]) ? j : min;
        // cделаем перестановку этого элемента, поменяв его местами с текущим
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
    //Указатели в начало и в конец массива
    int i = 0;
    int j = size - 1;
    //Центральный элемент массива
    T mid = arr[size / 2];

    //Делим массив
    do {
        //Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
        //В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
        while (arr[i] < mid) {
            i++;
        }
        //В правой части пропускаем элементы, которые больше центрального
        while (arr[j] > mid) {
            j--;
        }

        //Меняем элементы местами
        if (i <= j) {
            T tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);


    //Рекурсивные вызовы, если осталось, что сортировать
    if (j > 0) {
        //"Левый кусок"
        qsortRecursive(arr, j + 1);
    }
    if (i < size) {
        //"Правый кусок"
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
