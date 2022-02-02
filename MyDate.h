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
    time_t date_null = time(0);
    tm* now = localtime(&date_null);
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
    MyDate operator + (int days);
    MyDate operator - (int days);
    MyDate operator ++ (int day);
    MyDate operator -- (int day);
    bool operator ==(MyDate& right);
    bool operator !=(MyDate& right);
    bool operator >(MyDate& right);
    bool operator <(MyDate& right);
    const char* DayOfWeek();
    //bool operator ==(MyDate& d)const;
    //bool operator !=(MyDate& d)const;
    //MyDate getDiffDate(MyDate& d);
    void Print();
};

