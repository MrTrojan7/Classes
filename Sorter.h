#pragma once

template <class T>

class Sorter
{
private:
	T* arr;
	T size;
public:
	bool IsEmpty();
	void SetSize(T size);
	const T GetSize() const;
	static void qsortRecursive(T* mas, T size);
};

template<class T>
inline bool Sorter<T>::IsEmpty()
{
	return size == 0;
}

template<class T>
inline void Sorter<T>::qsortRecursive(T* mas, T size)
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
