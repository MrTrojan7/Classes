#pragma once
#include "AllLibraries.h"
struct elemDate
{
    size_t day;
    size_t month;
    size_t year;
};

enum months
{
    January, February, March, April, May, June, July, August, September, October, November, December,
};
class MyDate
{
private:
    elemDate date;
    int day_in_month[12]{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
public:
    MyDate(int y, int m, int d);
    MyDate(string str);
    MyDate();
    MyDate(const MyDate& d);
    elemDate getElemDate() const;
    int getYear()const;
    int getMonth()const;
    int getDay()const;
    void setYear(int y);
    void setMonth(int m);
    void setDay(int d);
    bool isLeapYear();
    bool operator ==(MyDate& d)const;
    bool operator !=(MyDate& d)const;
    MyDate getDiffDate(MyDate& d);
    void Print();
};

