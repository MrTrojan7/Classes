#include "Fraction.h"
#include <iostream>

using namespace std;

Fraction::Fraction() : Fraction(1, 3){}

Fraction::Fraction(int numerator, int denominator)
{
	SetNumerator(numerator);
	SetDenominator(denominator);
	SetToDecimal(numerator, denominator);
	SetInteger();
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

void Fraction::SetInteger()
{
	this->_integer_num = static_cast<int>(_decimal_num);
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

void Fraction::SetToFraction()
{
	this->_decimal_num = _decimal_num - static_cast<int>(_decimal_num);
}

void Fraction::SetToDecimal(int numerator, int denominator)
{
	this->_decimal_num = static_cast<double>(numerator) / denominator;
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
	return _integer_num;
}

double Fraction::GetDecimal() const
{
	return _decimal_num;
}

void Fraction::Print() const
{
	cout << "Numerator->\t\t\t" << GetNumerator() << "\n\t\t\t\t-\n";
	cout << "Denominator->\t\t\t" << GetDenominator() << "\n\n";
	cout << "Decimal fraction->\t\t" << GetDecimal() << "\n";
	cout << "Integer part of fraction->\t" << GetInteger() << "\n\n";
}
