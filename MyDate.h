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
    //elemDate getElemDate() const;
    int GetYear()const;
    int GetMonth()const;
    int GetDay()const;
    void SetYear(int year);
    void SetMonth(int month);
    void SetDay(int day);
    bool IsLeapYear(int year);
    bool IsInvalidDate(int year, int month, int day);
    int YearsOfMonth(int year, int month);
    int GetJDN(const elemDate date);
    int operator - (MyDate& right);
    void operator + (int days);
    const char* DayOfWeek();
    //bool operator ==(MyDate& d)const;
    //bool operator !=(MyDate& d)const;
    //MyDate getDiffDate(MyDate& d);
    void Print();
};
