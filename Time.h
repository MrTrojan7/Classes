#pragma once
#pragma warning(disable : 4996);
#include "AllLibraries.h"
struct elemTime
{
	int hour;
	int minute;
	int second;
};

class Time
{
private:
	elemTime _time;
	void IsValidTime(int hours, int minutes, int seconds) const;
public:
	Time();
	Time(int hours, int minutes, int seconds);
	int GetHours() const;
	int GetMinutes() const;
	int GetSeconds() const;
	void SetHours(int hours);
	void SetMinutes(int minutes);
	void SetSeconds(int seconds);
	const char* TimeOfDay() const;
	int GetSecondsOfDay();
	Time operator + (int seconds);
	Time operator - (int seconds);
	Time operator ++ (int seconds);
	Time operator -- (int seconds);
	bool operator ==(Time& right);
	bool operator !=(Time& right);
	bool operator >(Time& right);
	bool operator <(Time& right);
	Time operator()(int hours, int minutes, int seconds);
	friend ostream& operator << (ostream& out, const Time& original);
	friend istream& operator >> (istream& in, Time& original);
	void Print();
};

