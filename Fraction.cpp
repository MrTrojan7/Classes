#include "Fraction.h"
#include <iostream>
#include <string>

using namespace std;

Fraction::Fraction() : Fraction(1, 3){}

Fraction::Fraction(int numerator, int denominator)
{
	SetNumerator(numerator);
	SetDenominator(denominator);
	SetToDecimal(numerator, denominator);
	SetInteger();
}

Fraction::Fraction(double decimal_num)
{
	SetDecimalNum(decimal_num);
	SetInteger();
	SetToFraction(decimal_num);
	SetReduction();
}

void Fraction::SetNumerator(int numerator)
{
	this->_numerator = numerator;
}

void Fraction::SetDenominator(int denominator)
{
	CheckOnZero(denominator);
	this->_denominator = denominator;
}

void Fraction::SetDecimalNum(double decimal_num)
{
	this->_decimal_num = decimal_num;
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
	int min_num = _numerator < _denominator ? _numerator : _denominator;
	for (int i = min_num; i > 2; i--)
	{
		if (_numerator % i == 0 && _denominator % i == 0)
		{
			_numerator /= i;
			_denominator /= i;
		}
	}
}

void Fraction::SetToDecimal(int numerator, int denominator)
{
	this->_decimal_num = static_cast<double>(numerator) / denominator;
}

void Fraction::SetToFraction(double decimal_num)
{
	/*int copy_decimal;
	copy_decimal = _decimal_num - static_cast<int>(_decimal_num);*/
	string decimal_str = to_string(decimal_num);
	int count = 10;
	for (size_t i = 0; i < decimal_str.size(); i++) // проблема с производительностью
	{
		count *= 10;
	}
	this->_numerator = decimal_num * count;
	this->_denominator = count;
}

bool Fraction::CheckDenominatorOnZero() const
{
	return this->_denominator;
}

bool Fraction::CheckNumeratorOnZero() const
{
	return this->_numerator;
}

void Fraction::CheckOnZero(int denominator) const
{
	if (denominator == 0)
	{
		throw "Error! Denominator can't equals zero!";
	}
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

double Fraction::Equal(Fraction& obj_1, Fraction& obj_2)
{
	return obj_1.GetDecimal() > obj_2.GetDecimal() ? obj_1.GetDecimal() : obj_2.GetDecimal();
}

double Fraction::Plus(Fraction& obj_1, Fraction& obj_2)
{
	return obj_1.GetDecimal() + obj_2.GetDecimal();
}

double Fraction::Minus(Fraction& obj_1, Fraction& obj_2)
{
	return obj_1.GetDecimal() - obj_2.GetDecimal();
}

double Fraction::Product(Fraction& obj_1, Fraction& obj_2)
{
	return obj_1.GetDecimal() * obj_2.GetDecimal();
}

double Fraction::Divided(Fraction& obj_1, Fraction& obj_2)
{
	obj_2.CheckOnZero(obj_2._denominator);
	return obj_1.GetDecimal() / obj_2.GetDecimal();
}

void Fraction::Print() const
{
	cout << /*"\tNumerator->\t" <<*/ GetNumerator() << "\n-\n";
	cout << /*"\tDenominator->\t" <<*/ GetDenominator() << "\n\n";
	cout << /*"\tDecimal fraction->" <<*/ GetDecimal() << "\n";
	cout << /*"Integer part of fraction->" <<*/ GetInteger() << "\n\n";
}
