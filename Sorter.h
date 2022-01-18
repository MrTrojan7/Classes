#pragma once
#include "AllLibraries.h"
template <class Arr, class Size>
void qsortRecursive(Arr* mas, Size size);

template<class Arr, class Size>
inline void qsortRecursive(Arr* mas, Size size)
{
    //��������� � ������ � � ����� �������
    int i = 0;
    int j = size - 1;

    //����������� ������� �������
    int mid = mas[size / 2];

    //����� ������
    do {
        //��������� ��������, ���� ��, ������� ����� ���������� � ������ �����
        //� ����� ����� ������� ����������(��������� �� �����) ��������, ������� ������ ������������
        while (mas[i] < mid) {
            i++;
        }
        //� ������ ����� ���������� ��������, ������� ������ ������������
        while (mas[j] > mid) {
            j--;
        }

        //������ �������� �������
        if (i <= j) {
            int tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);


    //����������� ������, ���� ��������, ��� �����������
    if (j > 0) {
        //"����� �����"
        qsortRecursive(mas, j + 1);
    }
    if (i < size) {
        //"����� �����"
        qsortRecursive(&mas[i], size - i);
    }
}
