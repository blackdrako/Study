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
    if (A != NULL) {
        /*for (long i = 0; i < m; i++)
            delete[] *(A[i]);*/
        delete[] A;
    }
    A = new Frac_arr * [m];
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

void Frac_arr::create(long n) {
    if (this->n != n) {
        this->n = n;
        if (array != NULL)
            delete[] array;
        array = new Fraction[n];
    }
}

void Frac_arr::operator =(Frac_arr& a)
{
    create(a.n);
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

void Frac_matr::operator =(Frac_matr& M) {
    Create(M.m, M.n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            (*(A[i]))[j] = M[i][j];
}
