#pragma once
class Counter
{
private:
	int _current;
	int _max;
	int _min;
	int _step;

public:
	Counter();
	Counter(int min, int max);
	Counter(int min, int max, int current);
	Counter(int min, int max, int current, int step);
	void SetCurrent(int current);
	void SetStep(int step);
	void SetMin(int min);
	void SetMax(int max);
	void SetDefault();
	void Increment();
	void IncrByStep();
	void Reset();
	int GetCurrent() const;
	int GetMax() const;
	void Print() const;
};

