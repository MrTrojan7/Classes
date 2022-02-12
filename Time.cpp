#pragma warning(disable : 4996);
#include "Time.h"

Time::Time()
{
    time_t time_null = time(0);
    tm* now = localtime(&time_null);
    SetHours(now->tm_hour);
    SetMinutes(now->tm_min);
    SetSeconds(now->tm_sec);
}

Time::Time(int hours, int minutes, int seconds)
{
    IsValidTime(hours, minutes, seconds);
    SetHours(hours);
    SetMinutes(minutes);
    SetSeconds(seconds);
}

int Time::GetHours() const
{
    return _time.hour;
}

int Time::GetMinutes() const
{
    return _time.minute;
}

int Time::GetSeconds() const
{
    return _time.second;
}

void Time::SetHours(int hours)
{
    this->_time.hour = hours;
}

void Time::SetMinutes(int minutes)
{
    this->_time.minute = minutes;
}

void Time::SetSeconds(int seconds)
{
    this->_time.second = seconds;
}

const char* Time::TimeOfDay() const
{
    const char* TimeOfDay[] = { "Night", "Morning", "Day", "Evening" };
    switch (_time.hour)
    {
        case 0: case 1: case 2: case 3: case 4: case 5: return TimeOfDay[0];
        case 6: case 7: case 8: case 9: case 10: case 11: return TimeOfDay[1];
        case 12: case 13: case 14: case 15: case 16: case 17: return TimeOfDay[2];
        case 18: case 19: case 20: case 21: case 22: case 23: return TimeOfDay[3];
        default:
            break;
    }
}

void Time::IsValidTime(int hours, int minutes, int seconds) const
{
    if(hours < 0 || hours >= 24 ||
        minutes < 0 || minutes >= 60 ||
        seconds < 0 || seconds >= 60)
        throw "Invalid time!";
}

int Time::GetSecondsOfDay()
{
    int result = (3600 * _time.hour) + (60 * _time.minute) + _time.second;
    return result;
}

Time Time::operator+(int seconds)
{
    while (seconds > 0)
    {
        _time.second++;
        if (_time.second == 60)
        {
            _time.minute++;
            _time.second = 0;
        }
        if (_time.minute == 60)
        {
            _time.hour++;
            _time.minute = 0;
            _time.second = 0;
        }
        if (_time.hour == 24)
        {
            _time.hour = 0;
            _time.minute = 0;
            _time.second = 0;
        }
        seconds--;
    }
    return Time();
}

Time Time::operator-(int seconds)
{
    while (seconds > 0)
    {
        if (_time.second == 0)
        {
            _time.minute--;
            _time.second = 60;
            continue;
        }
        if (_time.minute < 0)
        {
            _time.hour--;
            _time.minute = 59;
            _time.second = 60;
            continue;
        }
        if (_time.hour < 0)
        {
            _time.hour = 23;
            _time.minute = 59;
            _time.second = 60;
            continue;
        }
        _time.second--;
        seconds--;
    }
    return Time();
}

Time Time::operator++(int seconds)
{
    operator+(1);
    return Time();
}

Time Time::operator--(int seconds)
{
    operator-(1);
    return Time();
}

bool Time::operator==(Time& right)
{
    return GetSecondsOfDay() == right.GetSecondsOfDay();
}

bool Time::operator!=(Time& right)
{
    return GetSecondsOfDay() != right.GetSecondsOfDay(); 
}

bool Time::operator>(Time& right)
{
    return GetSecondsOfDay() > right.GetSecondsOfDay();
}

bool Time::operator<(Time& right)
{
    return GetSecondsOfDay() < right.GetSecondsOfDay();
}

Time Time::operator()(int hours, int minutes, int seconds)
{
    IsValidTime(hours, minutes, seconds);
    SetHours(hours);
    SetMinutes(minutes);
    SetSeconds(seconds);
    return Time();
}

void Time::Print()
{
    cout << _time.hour << ":" << _time.minute << ":" << _time.second << "\n";
}

ostream& operator<<(ostream& out, const Time& original)
{
    out << original._time.hour << ":" << original._time.minute << ":" << original._time.second;
    return out;
}

istream& operator>>(istream& in, Time& original)
{
    in >> original._time.hour >> original._time.minute >> original._time.second;
    original.IsValidTime(original._time.hour, original._time.minute, original._time.second);
    return in;
}
