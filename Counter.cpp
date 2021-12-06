#include "Counter.h"
#include <stdio.h>

Counter::Counter() : Counter(0, 9)
{
}

Counter::Counter(int min, int max) : Counter(min, max, 1)
{

}

Counter::Counter(int min, int max, int current) : Counter(min, max, current, 1)
{

}

Counter::Counter(int min, int max, int current, int step)
{
	SetStep(step);
	SetMin(min);
	SetMax(max);
	SetCurrent(current);
}

void Counter::SetCurrent(int current)
{
	if (current < _min || current > _max)
	{
		throw "Invalid value of current\n";
	}
	_current = current;
}

void Counter::SetStep(int step)
{
	_step = step;
}

void Counter::SetMin(int min)
{
	_min = min;
}

void Counter::SetMax(int max)
{
	_max = max;
}

void Counter::SetDefault()
{
	SetStep(1);
	SetMin(0);
	SetMax(9);
	SetCurrent(0);
}

void Counter::Increment()
{
	if (_current == _max)
	{
		Reset();
		return;
	}
	SetCurrent(_current + 1);
}

void Counter::IncrByStep()
{
	if (_current + _step > _max)
	{
		Reset();
		return;
	}
	SetCurrent((_current + _step) % (_max - 1));
}

void Counter::Reset()
{
	SetCurrent(_min);
}

int Counter::GetCurrent() const
{
	return _current;
}

void Counter::Print() const
{
	printf("%10d", _current);
}
