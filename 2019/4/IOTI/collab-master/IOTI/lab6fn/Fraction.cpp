#include "Fraction.h"
#include <math.h>
#include <stdio.h>
#include <iomanip>

long Sign(long a)
{
	if (a >= 0) return 1;
	else return -1;
}

void Fraction::ReduceFrac()
{
	long x, y;
	if (denominator == 1 || numerator == 0 || numerator == 1 && denominator == 1) return;
	x = abs(numerator); y = abs(denominator);
	while (x != y)
		if (x > y) x -= y;
		else y -= x;
	numerator = numerator / x * Sign(denominator);
	denominator = abs(denominator) / y;
}

std::istream& operator >>(std::istream& in, Fraction& a)
{
	char c;
	in >> a.numerator;
	c = getchar();
	if (c == '/')			//после чила либо дробь, либо пробел (целое число)
		in >> a.denominator;
	else a.denominator = 1;
	a.ReduceFrac();
	return in;
}

std::ostream& operator <<(std::ostream& out, Fraction& a)
{
	out << std::setw(6) << a.numerator;
	if (a.denominator != 1 && a.numerator != 0) out << '/' << std::left << std::setw(5) << a.denominator << std::right;
	else out << "      ";
	return out;
}

Fraction operator +(Fraction& a, Fraction& b)
{
	Fraction c;
	c.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
	c.denominator = a.denominator * b.denominator;
	c.ReduceFrac();
	return c;
}

Fraction operator -(Fraction& a, Fraction& b)
{
	Fraction c;
	c.numerator = a.numerator * b.denominator - b.numerator * a.denominator;
	c.denominator = a.denominator * b.denominator;
	c.ReduceFrac();
	return c;
}

/*Fraction& Fraction::operator -()
{
	Fraction a;
	a.numerator = -numerator;
	a.denominator = denominator;
	return a;
}*/

Fraction operator *(Fraction& a, Fraction& b)
{
	Fraction c;
	c.numerator = a.numerator * b.numerator;
	c.denominator = a.denominator * b.denominator;
	c.ReduceFrac();
	return c;
}

Fraction operator /(Fraction& a, Fraction& b)
{
	Fraction c;
	c.numerator = a.numerator * b.denominator;
	c.denominator = a.denominator * b.numerator;
	c.ReduceFrac();
	return c;
}

long operator ==(Fraction& a, long b)
{
	if (a.denominator == 1 && a.numerator == b || a.numerator == 0 && b == 0) return 1;
	else return 0;
}

long operator ==(Fraction& a, Fraction& b)
{
	if (a.numerator == b.numerator && a.denominator == b.denominator || a.numerator == 0 && b.numerator == 0) return 1;
	else return 0;
}

long operator !=(Fraction& a, long b)
{
	return !(a == b);
}

long operator !=(Fraction& a, Fraction& b)
{
	return !(a == b);
}

long operator >=(Fraction& a, long b)
{
	return a.numerator >= b * a.denominator;
}

long operator >=(Fraction& a, Fraction& b)
{
	return (long)(a.numerator * b.denominator) >= (long)(b.numerator * a.denominator);
}

long operator <=(Fraction& a, long b)
{
	return (long)(a.numerator) <= (long)(b * a.denominator);
}

long operator <=(Fraction& a, Fraction& b)
{
	return (long)(a.numerator * b.denominator) <= (long)(b.numerator * a.denominator);
}

long operator >(Fraction& a, long b)
{
	return (long)(a.numerator) > (long)(b * a.denominator);
}

long operator >(Fraction& a, Fraction& b)
{
	return (long)(a.numerator * b.denominator) > (long)(b.numerator * a.denominator);
}

long operator <(Fraction& a, long b)
{
	return (long)(a.numerator) < (long)(b * a.denominator);
}

long operator <(Fraction& a, Fraction& b)
{
	return (long)(a.numerator * b.denominator) < (long)(b.numerator * a.denominator);
}

void Fraction::operator *=(Fraction a)
{
	numerator *= a.numerator;
	denominator *= a.denominator;
	ReduceFrac();
}

void Fraction::operator *=(long a)
{
	numerator *= a;
	ReduceFrac();
}

void Fraction::operator /=(Fraction a)
{
	numerator *= a.denominator;
	denominator *= a.numerator;
	ReduceFrac();
}

void Fraction::operator +=(Fraction a)
{
	numerator = a.numerator * denominator + numerator * a.denominator;
	denominator = a.denominator * denominator;
	ReduceFrac();
}

void Fraction::operator =(long b)
{
	numerator = b;
	denominator = 1;
	ReduceFrac();
}

void Fraction::operator =(Fraction b)
{
	numerator = b.numerator;
	denominator = b.denominator;
	ReduceFrac();
}
