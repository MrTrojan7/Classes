#pragma once
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
	void SetNumerator(int numerator);
	void SetDenominator(int denominator);
	void SetReduction();
	void SetDecimalToFraction();
	bool CheckDenominatorOnZero() const;
	bool CheckNumeratorOnZero() const;
	int GetNumerator() const;
	int GetDenominator() const;
	int GetInteger() const;
	void Print() const;
};

