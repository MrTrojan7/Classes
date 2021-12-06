#include "Point.h"
#include <iostream>

using namespace std;

Point::Point() : Point(0, 0)
{

}

Point::Point(int X, int Y)
{
	SetX(X);
	SetY(Y);
}

int Point::GetX() const
{
	return _X;
}

int Point::GetY() const
{
	return _Y;
}

void Point::SetX(int X)
{
	_X = X;
}

void Point::SetY(int Y)
{
	_Y = Y;
}

void Point::ShiftX(int dX)
{
	SetX(_X + dX);
}

void Point::ShiftY(int dY)
{
	SetY(_Y + dY);
}

void Point::Print() const
{
	cout << "{ " << GetX() << " " << GetY() << " }\n";
}
