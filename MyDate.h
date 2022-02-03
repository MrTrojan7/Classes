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
    void IsInvalidDate(int year, int month, int day);
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
    const char* DayOfWeek();
    void Print();
};

