#include "Frac_matr.h"
#include <iostream>

Frac_matr::Frac_matr(long m1, long n1)
{
	m = m1; n = n1;
	A = new Frac_arr*[m];
	for (long i = 0; i < m; i++)
		A[i] = new Frac_arr(n);
}
/*
Frac_matr::~Frac_matr()
{
	for (long i = 0; i < m; i++)
		delete[] A[i];
	delete[] A;
}*/

void Frac_matr::Create(long m1, long n1)
{
	m = m1; n = n1;
	A = new Frac_arr*[m];
	for (long i = 0; i < m; i++)
		A[i] = new Frac_arr(n);
	/*m = m1; n = n1;
	A = new Fraction*[m];
	for (long i = 0; i < m; i++)
		A[i] = new Fraction[n];*/
}

std::ostream& operator <<(std::ostream& out, Frac_matr& A)
{
	for (long i = 0; i < A.m; i++)
	{
		for (long j = 0; j < A.n; j++)
			std::cout<<A[i][j]<<"  ";
		out << std::endl;
	}
	return out;
}

std::istream& operator >>(std::istream& in, Frac_matr& A)
{
	for (long i = 0; i < A.m; i++)
		for (long j = 0; j < A.n; j++)
			in>>A[i][j];
	return in;
}

Frac_arr& Frac_matr::operator [](long i)
{
	return *(A[i]);
}

Frac_arr::Frac_arr(long n1)
{
	array = new Fraction[n1];
	n = n1;
}

Fraction& Frac_arr::operator [](long i)
{
	return array[i];
}

void Frac_arr::operator =(Frac_arr& a)
{
	for (long i = 0; i < n; i++)
		array[i] = a[i];
}

void Frac_arr::operator *=(Frac_arr a)
{
	for (long i = 0; i < n; i++)
		array[i] *= a[i];
}

void Frac_arr::operator *=(long a)
{
	for (long i = 0; i < n; i++)
		array[i] *= a;
}

void Frac_arr::operator *=(Fraction a)
{
	for (long i = 0; i < n; i++)
		array[i] *= a;
}

void Frac_arr::operator /=(Frac_arr a)
{
	for (long i = 0; i < n; i++)
		array[i] /= a[i];
}

void Frac_arr::operator /=(Fraction a)
{
	for (long i = 0; i < n; i++)
		array[i] /= a;
}

void Frac_arr::operator +=(Frac_arr a)
{
	for (long i = 0; i < n; i++)
		array[i] += a[i];
}
/*Frac_arr::~Frac_arr()
{
	delete[] array;
}*/