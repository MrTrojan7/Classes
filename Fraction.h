#pragma once
//#include "AllLibraries.h"
class Fraction
{
private:
	int _numerator;
	int _denominator;
	double _decimal_num;
	int _integer_num;

public:
	Fraction();
	Fraction(int numerator, int denominator);
	Fraction(double decimal_num);
	void SetNumerator(int numerator);
	void SetDenominator(int denominator);
	void SetDecimalNum(double decimal_num);
	void SetInteger();
	void SetReduction();
	void SetToDecimal(int numerator, int denominator);
	void SetToFraction(double decimal_num);
	bool CheckDenominatorOnZero() const;
	bool CheckNumeratorOnZero() const;
	void CheckOnZero(int denominator) const;
	int GetNumerator() const;
	int GetDenominator() const;
	int GetInteger() const;
	double GetDecimal() const;
	static double Equal(Fraction& obj_1, Fraction& obj_2);
	static double Plus(Fraction& obj_1, Fraction& obj_2);
	static double Minus(Fraction& obj_1, Fraction& obj_2);
	static double Product(Fraction& obj_1, Fraction& obj_2);
	static double Divided(Fraction& obj_1, Fraction& obj_2);
	void Print() const;
};

