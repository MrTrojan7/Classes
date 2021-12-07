#include "Glasses.h"
#include <iostream>
#include <math.h>

using namespace std;

Glasses::Glasses() : Glasses(100, 1, 1, 0, 1)
{

}

Glasses::Glasses(int price, bool IsBeatiful, bool IsDarkened, int VisionCorrection, bool Wearing)
{
	SetPrice(price);
	SetIsBeatiful(IsBeatiful);
	SetIsDarkened(IsDarkened);
	SetVisionCorrection(VisionCorrection);
	SetWearing(Wearing);
}

int Glasses::GetPrice() const
{
	return _price;
}

bool Glasses::GetIsBeatiful() const
{
	return _IsBeatiful;
}

bool Glasses::GetIsDarkened() const
{
	return _IsDarkened;
}

int Glasses::GetVisionCorrection() const
{
	return _VisionCorrection;
}

bool Glasses::GetWearing() const
{
	return _Wearing;
}

void Glasses::SetPrice(int price)
{
	_price = fabs(price);
}

void Glasses::SetIsBeatiful(bool IsBeatiful)
{
	_IsBeatiful = IsBeatiful;
}

void Glasses::SetIsDarkened(bool IsDarkened)
{
	_IsDarkened = IsDarkened;
}

void Glasses::SetVisionCorrection(int VisionCorrection)
{
	_VisionCorrection = VisionCorrection;
}

void Glasses::SetWearing(bool Wearing)
{
	_Wearing = Wearing;
}

void Glasses::Print()
{
	cout << "Price: " << _price << "\n";
	_IsBeatiful ? cout << "Beatiful\n" : cout << "Not beatiful\n";
	_IsDarkened ? cout << "Darkened\n" : cout << "No Darkened\n";
	cout << "Vis.Corr.: " << _VisionCorrection << "\n";
	_Wearing ? cout << "Wearing\n" : cout << "No wearing\n";
}
