#include "saddlePoint.h"

using namespace std;


void SaddlePoint::inputCosts() {
	Fraction min;
	bool flag = false;
	Fraction mult;
	mult.denominator = 1;
	for (int i = 0; i < mc; i++) {
		for (int j = 0; j < nc; j++) {
			cin >> costs[i][j];
			if (costs[i][j] < 0) {
				if (min > costs[i][j]) {
					min = costs[i][j];
				}
				flag = true;
			}
		}
	}
	if (flag) {
		cout << "Была введена матрица стоимостей с отрицательными значениями, это может повлиять на корректность ответа." << endl << "Минимальное значение: " << min << ", выберите число больше этого, чтобы прибавить его к матрице стоимостей: ";
		cin >> mult;
		for (int i = 0; i < mc; i++){
			for (int j = 0; j < nc; j++) {
				costs[i][j] += mult;
			}
		}
	}
	
	for (int i = 0; i < mc; i++) {
		for (int j = 0; j < nc; j++) {
			SLU[i][j] = costs[i][j];
		}
	}
	int j = 0;
	for (int i = nc; i < n - 1; i++) {
		SLU[j][i] = 1;
		j++;
	}
	for (int i = 0; i < mc; i++) {
		SLU[i][n - 1] = 1;
	}
}

void SaddlePoint::getSaddlePoint() {
	Fraction tmp, max, min;
	Frac_arr mins(mc), maxs(nc);
	int a = 0, b = 0;
	max = costs[0][0];
	min = costs[0][0];
	for (int i = 0; i < mc; i++) {
		min = costs[i][0];
		for (int j = 0; j < nc; j++) {
			if (costs[i][j] < min) {
				min = costs[i][j];
			}

		}
		mins[i] = min;
	}
	upperCost = mins[0];
	upperPos = 0;
	for (int i = 0; i < mc; i++) {
		if (mins[i] > upperCost) {
			upperCost = mins[i];
			upperPos = i;
		}
	}
	for (int i = 0; i < nc; i++) {
		max = costs[0][i];
		for (int j = 0; j < mc; j++) {
			if (costs[j][i] > max) {
				max = costs[j][i];
			}

		}
		maxs[i] = max;
	}
	lowerCost = maxs[0];
	lowerPos = 0;
	for (int i = 0; i < nc; i++) {
		if (maxs[i] < lowerCost) {
			lowerCost = maxs[i];
			lowerPos = i;
		}
	}

	if (lowerCost == upperCost) {
		cout << "Седловая точка: (" << upperPos + 1 << ", " << lowerPos + 1 << ")" << endl;
		cout << "Цена игры: " << lowerCost << endl;
	}
}

long SaddlePoint::Search(long* a, long n, long k, long* j) {
	for (long i = 0; i < n; i++)
		if (k == a[i]) {
			*j = i;
			return 1;
		}
	return 0;
}

void SaddlePoint::solveMixedStrats() {
	GetSimplexTable();
	cout << *this << endl;
	while (SimplexStep()) cout << *this << endl;
	getMatching();
	//printMatching();
	Fraction zero;
	zero.numerator = 0;
	zero.denominator = 1;
	cout << "F max = Z min = " << T[x - 1][0] << endl;



	bool flag = false;
	cout << "T min: (";
	for (int i = 1; i < nc + 1; i++) {
		flag = false;
		for (int s = 0; s < x - 1 && !flag; s++) {
			if (i == base[s]) {
				cout << T[s][0];
				flag = true;
			}
		}
		if (!flag) {
			cout << zero;
		}
	}
	cout << ")" << endl;

	cout << "T max: (";
	for (int i = nc + 1; i < mc + nc + 1; i++) {
		cout << T[x - 1][i];
		g += T[x - 1][i];
	}
	cout << ")" << endl << endl;
	Fraction one;
	one.numerator = 1;
	one.denominator = 1;
	g = one / g;
	cout << "Цена игры: " << g << endl;
	cout << "Оптимальная смешанная стратегия игрока 1:";
	cout << "P = (";
	for (int i = nc + 1; i < mc + nc + 1; i++) {
		Fraction tmp;
		tmp = T[x - 1][i] * g;
		cout << tmp;
	}
	cout << ")" << endl << endl;
	cout << "Оптимальная смешанная стратегия игрока 2:";
	cout << "Q = ( ";
	for (int i = 1; i < nc + 1; i++) {
		flag = false;
		for (int s = 0; s < x - 1 && !flag; s++) {
			if (i == base[s]) {
				Fraction tmp = T[s][0] * g;
				cout << tmp;
				flag = true;
			}
		}
		if (!flag) {
			cout << zero;
		}
	}
	cout << ")" << endl;

}

void SaddlePoint::getMatching() {
	for (int i = 0; i < mc; i++) {
		matching[i] = mc + i - 1;
	}
	int j = 0;
	for (int i = mc; i < mc + nc; i++) {
		matching[i] = j;
		j++;
	}
}

void SaddlePoint::printMatching() {
	cout << "Соответствие переменных:" << endl;
	for (int i = 0; i < mc + nc; i++) {
		cout << "x_" << i + 1 << " ";
	}
	cout << endl;
	for (int i = 0; i < mc + nc; i++) {
		cout << "y_" << matching[i] + 1 << " ";
	}
	cout << endl;
	cout << endl;
}




