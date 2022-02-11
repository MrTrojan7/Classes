#pragma warning(disable : 4996);
#include "MyDate.h"

MyDate::MyDate(int day, int month, int year)
{
    IsInvalidDate(year, month, day);
    date.day = day;
    date.month = month;
    date.year = year;     
}

MyDate::MyDate() 
{
    time_t date_null = time(0);
    tm* now = localtime(&date_null);
    date.day = now->tm_mday;
    date.month = (now->tm_mon + 1);
    date.year = (now->tm_year + 1900);
}

int MyDate::GetYear() const
{
    return date.year;
}

int MyDate::GetMonth() const
{
    return date.month;
}

int MyDate::GetDay() const
{
    return date.day;
}

void MyDate::SetYear(int year)
{
    date.year = year;
}

void MyDate::SetMonth(int month)
{
    date.month = month;
}

void MyDate::SetDay(int day)
{
    date.day = day;
}

bool MyDate::IsLeapYear(int year)
{
    if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
        return true;
    return false;
}

void MyDate::IsInvalidDate(int year, int month, int day)
{
    if ((year < 1) || (month < 0 || month >12) || (day < 0 || day > YearsOfMonth(year, month)))
        throw "Incorrected date";
}

int MyDate::YearsOfMonth(int year, int month)
{
    int day;
    int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    day = days[month];
    if (month == 2 && IsLeapYear(year))
        day += 1;
    return day;
}

int MyDate::GetJDN()
{
    int result;
    int a = ((14 - date.month) / 12);
    int y = date.year + 4800 - a;
    int m = date.month + (12 * a) - 3;
    result = date.day + (((153 * m) + 2) / 5) 
        + (365 * y) + (y / 4) 
        - (y / 100) + (y / 400) - 32045;
    return result;
}

int MyDate::operator-(MyDate& right)
{
    int result = GetJDN() - right.GetJDN();
    //cout << result << "\n"; //debug
    return result;
}

MyDate MyDate::operator+(int days)
{
    while (days > 0)
    {
        if (date.day == YearsOfMonth(date.year, date.month))
        {
            date.month++;
            date.day = 0;
        }
        if (date.month == 13)
        {
            date.month = 1;
            date.year++;
        }
        date.day++;
        days--;
    }
    return MyDate();
}

MyDate MyDate::operator-(int days)
{
    while (days > 0)
    {
        date.day--;
        if (date.month == 0)
        {
            date.month = 12;
            date.year--;
            date.day = YearsOfMonth(date.year, date.month);
        }
        if (date.day == 0)
        {
            date.month--;
            date.day = YearsOfMonth(date.year, date.month);
        }
        days--;
    }
    return MyDate();
}

MyDate MyDate::operator++(int day)
{
    operator+(1);
    return MyDate();
}

MyDate MyDate::operator--(int day)
{
    operator-(1);
    return MyDate();
}

bool MyDate::operator==(MyDate& right)
{
    return GetJDN() == right.GetJDN();
}

bool MyDate::operator!=(MyDate& right)
{
    return GetJDN() != right.GetJDN();
}

bool MyDate::operator>(MyDate& right)
{
    return GetJDN() > right.GetJDN();
}

bool MyDate::operator<(MyDate& right)
{
    return GetJDN() < right.GetJDN();
}

const char* MyDate::DayOfWeek() 
{
    const char* DayOfWeek[] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
    return DayOfWeek[(GetJDN() % 7)];
}


void MyDate::Print()
{
    cout << "Date: " << date.day << '-' << date.month << '-' << date.year << "\n";
}

ostream& operator<<(ostream& out, const MyDate& original)
{
    out << original.date.day << "-" << original.date.month << "-" << original.date.year;
    return out;
}

istream& operator>>(istream& in, MyDate& original)
{
    in >> original.date.day >> original.date.month >> original.date.year;
    original.IsInvalidDate(original.date.year, original.date.month, original.date.day);
    return in;
}
