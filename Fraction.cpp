#include "Fraction.h"
#include <iostream>

using namespace std;

Fraction::Fraction() : Fraction(1, 3){}

Fraction::Fraction(int numerator, int denominator)
{
	SetNumerator(numerator);
	SetDenominator(denominator);
}

void Fraction::SetNumerator(int numerator)
{
	this->_numerator = numerator;
}

void Fraction::SetDenominator(int denominator)
{
	this->_denominator = denominator;
	if (!CheckDenominatorOnZero())
	{
		throw "Error! Denominator can't equals zero!";
	}
}

void Fraction::SetReduction()
{
	if (!CheckNumeratorOnZero() || _numerator == 1)
	{
		return;
	}
	int min_num;
	_numerator < _denominator ? min_num = _numerator : min_num = _denominator;
	for (size_t i = min_num; i >= 1; i--)
	{
		if (_numerator % i == 0 && _denominator % i == 0)
		{
			_numerator /= i;
			_denominator /= i;
		}
	}
}

void Fraction::SetDecimalToFraction()
{
	this->_integer_num = (int)_decimal_num;
	this->_decimal_num = _decimal_num - (int)_decimal_num;
}

bool Fraction::CheckDenominatorOnZero() const
{
	return this->_denominator;
}

bool Fraction::CheckNumeratorOnZero() const
{
	return this->_numerator;
}

int Fraction::GetNumerator() const
{
	return this->_numerator;
}

int Fraction::GetDenominator() const
{
	return this->_denominator;
}

int Fraction::GetInteger() const
{
	return 0;
}

void Fraction::Print() const
{
	cout << GetNumerator() << "\n-\n";
	cout << GetDenominator() << "\n";
}
