#pragma once
#pragma warning(disable : 4996);
#include "AllLibraries.h"
struct elemDate
{
    int day;
    int month;
    int year;
};

class MyDate
{
private:
    elemDate date;
    void IsInvalidDate(int year, int month, int day);
public:
    MyDate(int day, int month, int year);
    MyDate();
    int GetYear()const;
    int GetMonth()const;
    int GetDay()const;
    void SetYear(int year);
    void SetMonth(int month);
    void SetDay(int day);
    bool IsLeapYear(int year);
    int YearsOfMonth(int year, int month);
    int GetJDN();
    int operator - (MyDate& right);
    MyDate operator + (int days);
    MyDate operator - (int days);
    MyDate operator ++ (int day);
    MyDate operator -- (int day);
    bool operator ==(MyDate& right);
    bool operator !=(MyDate& right);
    bool operator >(MyDate& right);
    bool operator <(MyDate& right);
    MyDate operator()(int day, int month, int year);
    friend ostream& operator << (ostream& out, const MyDate& original);
    friend istream& operator >> (istream& in, MyDate& original);
    const char* DayOfWeek();
    void Print();
};

