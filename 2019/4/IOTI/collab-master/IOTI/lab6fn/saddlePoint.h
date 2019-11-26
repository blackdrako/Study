#pragma once
#include "Simplex_table.h"
using namespace std;

class SaddlePoint : public Simplex_table {
public:
	long mc, nc; //размеры платежной матрицы
	Fraction lowerCost, upperCost, g;
	int lowerPos, upperPos;
	Frac_matr costs;
	int* matching; //Соответствие переменных: индекс - x, значение - у
	
	SaddlePoint(int mc, int nc) :Simplex_table(mc, mc + nc + 1), mc(mc), nc(nc), costs(mc, nc) {
		for (int i = 0; i < nc; i++) {
			Z[i] = 1;
		}
		matching = new int[mc + nc];
		g = 0;
	}
	void inputCosts();
	void getSaddlePoint();
	void solveMixedStrats();
	void getMatching();
	void printMatching();
	long Search(long* a, long n, long k, long* j);
	
};



