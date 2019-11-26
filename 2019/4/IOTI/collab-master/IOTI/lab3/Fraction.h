#pragma once
#include <iostream>

class Fraction{
public:	
	long numerator, denominator;
	void ReduceFrac();

	Fraction() : numerator(0), denominator(1){}
	Fraction(long a, long b): numerator(a), denominator(b){}
	friend std::ostream& operator <<(std::ostream&, Fraction&);
	friend std::istream& operator >>(std::istream&, Fraction&);
	friend Fraction operator +(Fraction&, Fraction&);
	friend Fraction operator -(Fraction&, Fraction&);
	//Fraction& operator -();
	friend Fraction operator *(Fraction&, Fraction&);
	friend Fraction operator /(Fraction&, Fraction&);
	friend long operator ==(Fraction&, Fraction&);
	friend long operator ==(Fraction&, long);
	friend long operator !=(Fraction&, Fraction&);
	friend long operator !=(Fraction&, long);
	friend long operator >=(Fraction&, long);
	friend long operator >=(Fraction&, Fraction&);
	friend long operator <=(Fraction&, long);
	friend long operator <=(Fraction&, Fraction&);
	friend long operator >(Fraction&, long);
	friend long operator >(Fraction&, Fraction&);
	friend long operator <(Fraction&, long);
	friend long operator <(Fraction&, Fraction&);
	void operator *=(Fraction);
	void operator *=(long);
	void operator /=(Fraction);
	void operator +=(Fraction);
	void operator =(long);
	void operator =(Fraction);
};

