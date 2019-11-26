#include "Simplex_table.h"
#include <iostream>
#include <iomanip>


void Simplex_table::Input_Z(std::istream& in)
{
	for (long i = 0; i < n; i++)
		in >> Z[i];
}

void Simplex_table::Input_SLU(std::istream& in)
{
	in >> SLU;
}

void Simplex_table::GetSimplexTable()
{
	long *a = new long[n - 1];
	for (long j = 0; j < n - 1; j++) {
		a[j] = 0;
		for (long i = 0; i < m; i++)
			if (SLU[i][j] != 0)
				if (SLU[i][j] == 1 && a[j] != 1)
					a[j] = 1;
				else {
					a[j] = 0;
					break;
				}
	}
	x = 1; //обязательно есть строка целевой функции
	for (long i = 0; i < n - 1; i++)
		if (a[i] == 1) x++;
	y = n;
	T.Create(x, y);
	base = new long[x-1];
	long k = 0, p;
	for (long i = 0; i < n - 1; i++)
		if (a[i] == 1)
		{
			base[k] = i + 1;
			p = 0;
			while (SLU[p][i] == 0) p++;
			T[k][0] = SLU[p][n - 1];
			for (long j = 0; j < n - 1; j++)
				T[k][j + 1] = SLU[p][j];
			k++;
		}
	for (long i = 0; i < n - 1; i++) {
		T[k][i + 1].numerator = -Z[i].numerator;		//по итогу k = x - 1, т.е послежня строка
		T[k][i + 1].denominator = Z[i].denominator;
	}
	T[k][0] = Z[n - 1];
	delete[] a;
}


long Simplex_table::SimplexStep()
{
	long i, j = 1, p, q, t; //p, q - индексы разрешающего элемента
	Fraction min, max, tmp;
	Frac_arr tmp_arr(y);
	for (j = 1; j < y; j++)
		if (T[x - 1][j] < max) {
			max = T[x - 1][j];
			t = j;
		}
	if (max == 0) return 0;   //симплекс-таблица является последней
	j = t;
	for (i = 0; i < x - 1; i++)
		if (T[i][j] > 0) {
			min = T[i][0] / T[i][j];
			break;
		}
	p = i; q = j;
	i++;
	for (i; i < x - 1; i++)
		if (T[i][j] > 0) {
			tmp = T[i][0] / T[i][j];
			if (tmp < min) {
				min = tmp;
				p = i; q = j;
			}
		}
	base[p] = q;
	T[p] /= T[p][q];
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

long Search(long* a, long n, long k, long* j)
{
	for (long i = 0; i < n; i++)
		if (k == a[i]) {
			*j = i;
			return 1;
		}
	return 0;
}

long Simplex_table::Simplex()
{
	GetSimplexTable(); std::cout << *this << std::endl;
	while (SimplexStep()) std::cout << *this << std::endl;
	std::cout << "Z_max = " << T[x - 1][0] << std::endl;
	std::cout << "т.max (";
	long j;
	for (long i = 1; i < y; i++) {
		if (Search(base, x - 1, i, &j))
			std::cout << T[j][0];
		else std::cout << "     0    ";
		if (i < y - 1) std::cout << ", ";
	}
	std::cout << ")" << std::endl;
	return 0;
}

std::ostream& operator <<(std::ostream& out, Simplex_table& A)
{
	out << "| б.п. |    св.ч.   |";
	for (long i = 0; i < A.y - 1; i++)
		out << "     y" << i + 1 << "     |";
	out << std::endl;
	for (long i = 0; i < A.x - 1; i++) {
		out << "+------+";
		for (long k = 0; k < A.y; k++)
			out << "------------+";
		out << std::endl;
		out << "|  y" << A.base[i] << "  |";
		for (long j = 0; j < A.y; j++)
			out << A.T[i][j] << "|";
		out << std::endl;
	}
	out << "+------+";
	for (long k = 0; k < A.y; k++)
		out << "------------+";
	out << std::endl;
	out << "|   f  |";
	for (long j = 0; j < A.y; j++)
		out << A.T[A.x - 1][j] << "|";
	out << std::endl;
	out << "+------+";
	for (long k = 0; k < A.y; k++)
		out << "------------+";
	out << std::endl;
	return out;
}


//Simplex_table::~Simplex_table();
