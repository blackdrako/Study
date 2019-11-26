#pragma once
#include <iostream>
#include <iomanip>
#include "DualSimplex.h"
using namespace std;
void DualSimplexTable::getDualTask() {
	for (int i = 0; i < m; i++) {
		F[i] = SLU[i][n - 1];
	}
	for (int i = 0; i < fm; i++) {
		for (int j = 0; j < fn - fm - 1; j++) {
			F_SLU[i][j] = SLU[j][i];
		}
	}
	int count = 0;
	for (int i = 0; i < fm; i++) {
		for (int j = fn - fm - 1; j < fn - 1; j++) {
			F_SLU[i][j] = 0;
		}
		F_SLU[i][fn - fm - 1 + count] = 1;
		count++;
	}
	for (int i = 0; i < fm; i++) {
		F_SLU[i][fn - 1] = Z[i];
	}
	matching = new int[m + fm];
	getBases();
	int tmp = m;
	for (int i = 0; i < fm; i++) {
		matching[i] = tmp;
		tmp++;
	}
	tmp = 0;
	for (int i = fm; i < fm + m; i++) {
		matching[i] = tmp;
		tmp++;
	}

	cout << endl << "Двойственная задача:" << endl;
	cout << "Коэффициенты целевой функции двойственной задачи:" << endl;
	for (int i = 0; i < m; i++) {
		cout << F[i] << " ";
	}
	cout << endl;
	cout << "Система ограничений двойственной задачи:" << endl;
	for (int i = 0; i < fm; i++) {
		for (int j = 0; j < fn; j++) {
			cout << F_SLU[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "Соответствие переменных:" << endl;
	for (int i = 0; i < fm + m; i++) {
		cout << "x_" << i + 1 << " ";
	}
	cout << endl;
	for (int i = 0; i < fm + m; i++) {
		cout << "y_" << matching[i] + 1 << " ";
	}
	cout << endl;
};
void DualSimplexTable::getBases() {
	int res = 0;
	base = new long[n - 1];
	for (long j = 0; j < n - 1; j++) {
		base[j] = 0;
		for (long i = 0; i < m; i++)
			if (SLU[i][j] != 0)
				if (SLU[i][j] == 1 && base[j] != 1) {
					base[j] = 1;
					res++;
				}

				else {
					base[j] = 0;
					break;
				}
	}
	basesCount = res;
};

void DualSimplexTable::printAnswer() {
	
	cout << "F max = Z min = " << T[x-1][0] << endl;
	cout << "t.min: {";
	for (int i = m+1; i < m + fm + 1; i++) {
		cout << T[x-1][i];
	}
	for (int i = 1; i < m + 1; i++) {
		cout << T[x - 1][i];
	}
	cout << "}" << endl;
}