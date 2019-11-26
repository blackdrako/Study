#pragma once
#include <iostream>
#include <iomanip>
#include "ClarificationOfRatings.h"

using namespace std;

void ClarSimplexTable::clarification() {
	GetSimplexTable();
	cout << "Решение двойственным симплекс-методом:" << endl;
	cout << *this << endl;
	while (1) {
		if (is_valid()) {
			cout << endl;
			cout << "simplex step:" << endl;
			SimplexStep();
			cout << *this << endl;
			getchar();
			//Simplex();
		}
		else {
			cout << endl;
			cout << "clarification step:" << endl;
			clarification_step();
			cout << *this << endl;
			//getchar();
		}
		if (is_valid() && is_last()) break;
	}
}

bool ClarSimplexTable::is_valid() {
	for (int i = 0; i < x - 1; i++) {
		if (T[i][0] < 0) return false;
	}
	return true;
}

bool ClarSimplexTable::is_last() {
	for (int i = 1; i < y; i++) {
		if (T[x - 1][i] < 0) return false;
	}
	return true;

}


long ClarSimplexTable::clarification_step() {
	long i, j, p, q, t; //p, q - индексы разрешающего элемента
	Fraction min, max, tmp;
	Frac_arr tmp_arr(y);
	Fraction zero;
	zero.denominator = 1;
	zero.numerator = 0;
	for (int j = 0; j < x - 1; j++) {
		if (T[j][0] < max) {
			max = T[j][0];
			t = j;
		}
	}
	//cout << "Max element is: " << max << endl;
	if (max == 0) return 0;
	j = t;
	p = j;
	/*for (int i = 1; i < y; i++) {
		tmp =  T[j][i];
		if (min > tmp && tmp < 0) {
			min = tmp;
			cout << "New min: " << min << endl;
			q = i;
		}
	}*/
	//cout << "init started" << endl;
	bool initDone = false;
	int iterations = 1;
	while (!initDone) {
		//cout << iterations << " iteration" << endl;
		if (T[j][iterations] < 0 && T[j][iterations] != 0) {
			min = T[x - 1][iterations] / T[j][iterations];
			min = min / T[j][0];
			q = iterations;
			initDone = true;
			//cout << "init with: " << min << endl;
			iterations++;
		}
		else {
			iterations++;
		}
		if (iterations == y) {
			cout << "Недопустимая задача!";
			//exit(1);
		}

	}
	for (int i = 1; i < y; i++) {
		if (T[j][i] < 0 && T[j][i] != 0) {
			tmp = T[x - 1][i] / T[j][i];
			tmp = tmp / T[j][0];
			//cout << "tmp: " << tmp;
			if (tmp < min) {
				min = tmp;
				//cout << "New min: " << min << endl;
				q = i;
			}
		}

	}
	//cout << "Last min:" << min << endl;
	//cout << "p, q: " << p << " " << q << endl;
	base[p] = q;
	T[p] /= T[p][q];
	//cout << "Starting G_ZH" << endl;
	for (i = 0; i < x; i++)
		if (i != p) {
			tmp_arr = T[p];
			tmp = T[i][q];
			tmp.numerator *= -1;
			tmp_arr *= tmp;
			T[i] += tmp_arr;
		}
	return 1;
}
