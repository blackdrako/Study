#ifndef BRANCHESANDBORDERS_H
#define BRANCHESANDBORDERS_H
#include "SimplexArtificial.h"
#include "ClarificationOfRatings.h"

class BranchesAndBorders{
public:
    //Frac_matr M;
    //Frac_arr Z;
    Fraction max_;
    int flag;
    long m, n;
public:
    BranchesAndBorders(long m, long n) : m(m), n(n), max_(), flag(0) {}
    void Input(Frac_matr& M, Frac_arr& Z);
    bool check_int(long m, long n, Frac_matr& M);
    bool isPsevdo(long m, long n, Frac_matr& M);
    void branchesAndBordersStep_1(long m, long n, long*, Frac_matr M, Frac_arr Z);
    void branchesAndBordersStep_2(long m, long n, long*, Frac_matr M, Frac_arr Z);
    void addRestrictions_1(long*, Frac_matr &M, Frac_arr &Z);
    void addRestrictions_2(long*, Frac_matr &M, Frac_arr &Z);
    void copyToSimp(SimplexArtificial& S, Frac_matr &M, Frac_arr &Z);
    void copyFromSimp(SimplexArtificial& S, Frac_matr &M, Frac_arr &Z);
    void copyToClar(ClarSimplexTable& C, Frac_matr &M, Frac_arr &Z);
    void copyFromClar(ClarSimplexTable& C, Frac_matr &M, Frac_arr &Z);
    void branchesAndBordersSolution();
    void outputSolution(SimplexArtificial& S);
    void outputSolution(ClarSimplexTable& C);
};

#endif // BRANCHESANDBORDERS_H
