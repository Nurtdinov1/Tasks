#include<iostream>
#include<cmath>
#include<string>

using namespace std;


int greatest_common_divisor(int operand_1, int operand_2)
{
	operand_1 = abs(operand_1);
	operand_2 = abs(operand_2);

	int tmp;
	while (operand_2 != 0)
	{
		tmp = operand_1 % operand_2;
		operand_1 = operand_2;
		operand_2 = tmp;
	}
	return operand_1;
}

class Fraction
{
private:
	int numerator, denominator;
public:
	Fraction()
	{
		numerator = 1;
		denominator = 1;
	}
	Fraction(int numerator, int denominator)
	{
		if (denominator == 0) {
			throw "denominator can not be zero";
		}

		if (denominator < 0)
		{
			denominator = abs(denominator);
			if (numerator > 0)
			{
				numerator = -numerator;
			}
			else
			{
				numerator = abs(numerator);
			}
		}

		this->numerator = numerator;
		this->denominator = denominator;
	}

	Fraction operator+ (const Fraction& right_operand) const
	{
		int tmp_numerator, tmp_denominator;
		tmp_numerator = this->numerator * right_operand.denominator
			+ this->denominator * right_operand.numerator;
		tmp_denominator = this->denominator * right_operand.denominator;

		int gcd = greatest_common_divisor(tmp_numerator, tmp_denominator);
		tmp_numerator /= gcd;
		tmp_denominator /= gcd;
		return Fraction(tmp_numerator, tmp_denominator);
	}

	// define overloaded - (minus) operator
	Fraction operator- (const Fraction& right_operand) const
	{
		int tmp_numerator, tmp_denominator;
		tmp_numerator = this->numerator * right_operand.denominator
			- this->denominator * right_operand.numerator;
		tmp_denominator = this->denominator * right_operand.denominator;;

		int gcd = greatest_common_divisor(tmp_numerator, tmp_denominator);
		tmp_numerator /= gcd;
		tmp_denominator /= gcd;
		return Fraction(tmp_numerator, tmp_denominator);
	}

	Fraction operator* (const Fraction& right_operand) const
	{
		int tmp_numerator, tmp_denominator;
		tmp_numerator = this->numerator * right_operand.numerator;
		tmp_denominator = this->denominator * right_operand.denominator;

		int gcd = greatest_common_divisor(tmp_numerator, tmp_denominator);
		tmp_numerator /= gcd;
		tmp_denominator /= gcd;
		return Fraction(tmp_numerator, tmp_denominator);
	}

	Fraction operator/ (const Fraction& right_operand) const
	{
		int tmp_numerator, tmp_denominator;
		tmp_numerator = this->numerator * right_operand.denominator;
		tmp_denominator = this->denominator * right_operand.numerator;

		int gcd = greatest_common_divisor(tmp_numerator, tmp_denominator);
		tmp_numerator /= gcd;
		tmp_denominator /= gcd;
		return Fraction(tmp_numerator, tmp_denominator);
	}

	string representation()
	{
		if (abs(denominator) == 1)
			return to_string(numerator);
		else
			return to_string(numerator) + "/" + to_string(denominator);
	}
};

int main()
{
	Fraction a(2, 3);
	Fraction b(1, 4);
	Fraction c;
	Fraction d(4, 6);
	Fraction f(1, 1);
	cout << a.representation() << endl;
	c = a + b;
	cout << c.representation() << endl;
	c = a - b;
	c = c * (a + b);
	c = c / (a + b);
	cout << c.representation() << endl;
	d = d / f;
	cout << d.representation() << endl;

	return 0;
}