#pragma once
#include "AllLibraries.h"
class Point
{
private:
	int _X;
	int _Y;

public:
	Point();
	Point(int X, int Y);
	int GetX() const;
	int GetY() const;
	void SetX(int X);
	void SetY(int Y);
	void ShiftX(int dX);
	void ShiftY(int dY);
	void Print() const;

};

