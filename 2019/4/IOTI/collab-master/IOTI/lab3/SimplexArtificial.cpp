#include "pch.h"
#include "SimplexArtificial.h"

long search1(long* a, long n, long k)
{
	for (long i = 0; i < n; i++)
		if (a[i] == k) return i;
	return -1;
}

long check1(long* a, long n, long k, long* j)
{
	for (long i = 0; i < n; i++)
		if (k == a[i]) {
			*j = i;
			return 1;
		}
	return 0;
}

void SimplexArtificial::getSimplexArtificialTable() {
	long k = n, p;
	long *a = new long[m + n - 1];	//массив уединённых положительных коэффициентов (базисных столбцов)
	for (long j = 0; j < n - 1; j++) {
		a[j] = -1;
		for (long i = 0; i < m; i++) {
			if (SLU[i][j] < 0) {
				a[j] = -1;
				break;
			}
			if (SLU[i][j] > 0 && a[j] == -1)
				a[j] = i;
			else
				if (SLU[i][j] != 0 && a[j] != -1) {
					a[j] = -1;
					break;
				}
		}
	}
	for (long i = 0; i < m; i++)
	{
		for (long j = 0; j < n; j++)
			SLU_y[i][j] = SLU[i][j];
		for (long j = n; j < m + n; j++)
			SLU_y[i][j] = 0;
		if (search1(a, n, i) == -1) {
			a[k] = i;
			SLU_y[i][k++] = 1;
		}
	}
	a[n - 1] = -1;
	x1 = m + 1;
	y1 = k;
	x = x1; y = n;
	T_y.Create(x1, y1);
	base = new long[x1 - 1];
	k = 0;
	for (long i = 0; i < y1; i++) {
		if (i == n - 1)
			continue;
		if (a[i] >= 0)
		{
			p = a[i];
			base[k] = i + (i < n ? 1 : 0);
			T_y[k][0] = SLU_y[p][n - 1];
			for (long j = 0; j < n - 1; j++)
				T_y[k][j + 1] = SLU_y[a[i]][j];
			for (long j = n; j < y1; j++)
				T_y[k][j] = SLU_y[a[i]][j];
			if (SLU_y[a[i]][i] != 1)
				T_y[k] /= SLU_y[a[i]][i];
			k++;
		}
	}
	Fraction tmp;
	Frac_arr tmp_ar(m + n);
	for (long i = 0; i < n; i++)
		Z_M[i] = 0;
	for (long i = n; i < y1; i++)
		if (a[i] >= 0) Z_M[i] = -1;
		else Z_M[i] = 0;
	for (long i = 0; i < y1; i++)
		if (a[i] >= 0) {
			tmp_ar = SLU_y[a[i]];
			tmp_ar /= SLU_y[a[i]][i];
			tmp_ar[n - 1] *= -1;
			tmp = Z_M[i]; tmp *= -1;
			tmp_ar *= tmp;
			Z_M += tmp_ar;
		}
	for (long i = 0; i < n - 1; i++) {
		T_y[x1 - 1][i + 1].numerator = -Z_M[i].numerator;		//по итогу k = x - 1, т.е послежня строка
		T_y[x1 - 1][i + 1].denominator = Z_M[i].denominator;
	}
	for (long i = n; i < y; i++) {
		T_y[x1 - 1][i].numerator = -Z_M[i].numerator;
		T_y[x1 - 1][i].denominator = Z_M[i].denominator;
	}
	T_y[x1 - 1][0] = Z_M[n - 1];
}

long SimplexArtificial::simplexArtificialStep()
{
	long i, j = 1, p, q, t; //p, q - индексы разрешающего элемента
	Fraction min, max, tmp;
	Frac_arr tmp_arr(y1);
	for (j = 1; j < y1; j++)
		if (T_y[x1 - 1][j] < max) {
			max = T_y[x1 - 1][j];
			t = j;
		}
	if (max == 0) return 0;   //симплекс-таблица является последней
	j = t;
	for (i = 0; i < x1 - 1; i++)
		if (T_y[i][j] > 0) {
			min = T_y[i][0] / T_y[i][j];
			break;
		}
	p = i; q = j;
	i++;
	for (i; i < x1 - 1; i++)
		if (T_y[i][j] > 0) {
			tmp = T_y[i][0] / T_y[i][j];
			if (tmp < min) {
				min = tmp;
				p = i; q = j;
			}
		}
	base[p] = q;
	T_y[p] /= T_y[p][q];
	for (i = 0; i < x1; i++)
		if (i != p) {
			tmp_arr = T_y[p];
			tmp = T_y[i][q];
			tmp.numerator *= -1;
			tmp_arr *= tmp;
			T_y[i] += tmp_arr;
		}
	return 1;
}

void SimplexArtificial::replace_y() {
	long i, j = 1, p, q, t; //p, q - индексы разрешающего элемента
	Fraction tmp;
	Frac_arr tmp_arr(y1);
	for (i = 0; i < x1 - 1; i++) {
		if (base[i] >= y) {
			p = i; 
			q = -1;
			for (j = 1; j < y; j++)
				if (search1(base, x1 - 1, j) == -1 && T_y[i][j] > 0) {
					q = j;
					break;
				}
			if (q == -1)
				for (j = 1; j < y; j++)
					if (search1(base, x1 - 1, j) == -1) {
						q = j;
						break;
					}
			base[p] = q;
			T_y[p] /= T_y[p][q];
			for (long k = 0; k < x1; k++)
				if (k != p) {
					tmp_arr = T_y[p];
					tmp = T_y[k][q];
					tmp.numerator *= -1;
					tmp_arr *= tmp;
					T_y[k] += tmp_arr;
				}
		std::cout << "Исключение y из разряда базисных:" << std::endl;
		outputArtificialTable(std::cout);
		}
	}
}

long Search2(long* a, long n, long k, long* j)
{
	for (long i = 0; i < n; i++)
		if (k == a[i]) {
			*j = i;
			return 1;
		}
	return 0;
}

long SimplexArtificial::simplexArtificial() {
	getSimplexArtificialTable(); outputArtificialTable(std::cout);
	while (simplexArtificialStep()) outputArtificialTable(std::cout);
	replace_y();
	T.Create(x, y);
	for (long i = 0; i < x; i++)
		for (long j = 0; j < y; j++)
			T[i][j] = T_y[i][j];
	for (long i = 0; i < m; i++) {
		for (long j = 0; j < n - 1; j++)
			SLU[i][j] = T_y[i][j + 1];
		SLU[i][n - 1] = T_y[i][0];
	}
	long *a = new long[n - 1];	//массив уединённых положительных коэффициентов (базисных столбцов)
	for (long j = 0; j < n - 1; j++) {
		a[j] = -1;
		for (long i = 0; i < m; i++) {
			if (SLU[i][j] < 0) {
				a[j] = -3;
				break;
			}
			if (SLU[i][j] > 0 && a[j] == -1) {
				a[j] = i;
			}
			else
				if (SLU[i][j] != 0 && a[j] != -1) {
					a[j] = -2;
					break;
				}
		}
	}
	Fraction tmp;
	Frac_arr tmp_ar(n);
	for (long i = 0; i < y; i++)
		if (a[i] >= 0) {
			tmp_ar = SLU[a[i]];
			tmp_ar /= SLU[a[i]][i];
			tmp_ar[n - 1] *= -1;
			tmp = Z[i]; tmp *= -1;
			tmp_ar *= tmp;
			Z += tmp_ar;
		}
	for (long i = 0; i < n - 1; i++) {
		T[x - 1][i + 1].numerator = -Z[i].numerator;
		T[x - 1][i + 1].denominator = Z[i].denominator;
	}
	T[x - 1][0] = Z[n - 1];
	std::cout << *this << std::endl;
	while (SimplexStep()) std::cout << *this << std::endl;
	std::cout << "Z_max = " << T[x - 1][0] << std::endl;
	std::cout << "т.max (";
	long j;
	for (long i = 1; i < y; i++) {
		if (Search2(base, x - 1, i, &j))
			std::cout << T[j][0];
		else std::cout << "     0    ";
		if (i < y - 1) std::cout << ", ";
	}
	std::cout << ")" << std::endl;
	return 0;
}

std::ostream& SimplexArtificial::outputArtificialTable(std::ostream& out) {
	out << "| б.п. |    св.ч.   |";
	for (long i = 0; i < y1 - 1; i++)
		if (i < y - 1)
			out << "     x" << i + 1 << "     |";
		else
			out << "     y" << i + 2 - y << "     |";
	out << std::endl;
	for (long i = 0; i < x1 - 1; i++) {
		out << "+------+";
		for (long k = 0; k < y1; k++)
			out << "------------+";
		out << std::endl;
		if (base[i] < y)
			out << "|  x" << base[i] << "  |";
		else
			out << "|  y" << base[i] - y + 1 << "  |";
		for (long j = 0; j < y1; j++)
			out << T_y[i][j] << "|";
		out << std::endl;
	}
	out << "+------+";
	for (long k = 0; k < y1; k++)
		out << "------------+";
	out << std::endl;
	out << "|   f  |";
	for (long j = 0; j < y1; j++)
		out << T_y[x1 - 1][j] << "|";
	out << std::endl;
	out << "+------+";
	for (long k = 0; k < y1; k++)
		out << "------------+";
	out << std::endl << std::endl;
	return out;
}