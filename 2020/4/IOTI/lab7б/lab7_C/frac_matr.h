#ifndef FRAC_MATR_H
#define FRAC_MATR_H
#include "Fraction.h"

class Frac_arr {
    Fraction *array;
    long n;
public:
    Frac_arr(long);
    Fraction& operator [](long);
    void create(long n);
    void operator =(Frac_arr&);
    void operator *=(Frac_arr);
    void operator *=(Fraction);
    void operator *=(long);
    void operator /=(Frac_arr);
    void operator /=(Fraction);
    void operator +=(Frac_arr);
    //~Frac_arr();
};

class Frac_matr {
    public:
    Frac_arr **A;
    long m, n;

    Frac_matr(long, long);
    //~Frac_matr();
    Frac_matr() : A(NULL) {}
    void Create(long, long);
    friend std::ostream& operator <<(std::ostream&, Frac_matr&);
    friend std::istream& operator >>(std::istream&, Frac_matr&);
    Frac_arr& operator [](long);
    void operator =(Frac_matr& M);
};
#endif // FRAC_MATR_H
