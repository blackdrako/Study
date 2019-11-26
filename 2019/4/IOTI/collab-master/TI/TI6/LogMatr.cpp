#include "LogMatr.h"

/*ostream& operator << (ostream& out, LogVec& A) {
	for (int i = 0; i < A.getSize(); i++)
		out << A.vec[i] << " ";
	out << endl;
	return out;
}

istream& operator >> (istream& in, LogVec& A) {
	for (int i = 0; i < A.getSize(); i++)
		in >> A.vec[i];
	return in;
}

void LogVec::operator =(short* ar) {

}
*/



void LogMatr::resize(int m, int n) {
	this->m = m;
	this->n = n;
	matr.resize(m);
	for (int i = 0; i < m; i++)
		matr[i].resize(n);
}

ostream& operator << (ostream & out, LogMatr & A) {
	for (int i = 0; i < A.getM(); i++) {
		for (int j = 0; j < A.getN(); j++)
			out << A[i][j] << " ";
		out << endl;
	}
	return out;
}

istream& operator >> (istream & in, LogMatr & A) {
	for (int i = 0; i < A.getM(); i++)
		for (int j = 0; j < A.getN(); j++)
			in >> A[i][j];
	return in;
}

vector<short> operator *(vector<short> & A, LogMatr & M) {
	if (A.size() != M.getM()) throw LogMatrException("Ошибка! Длина вектор-строки не равна кол-ву строк матрицы!");
	vector<short> res(M.getN());
	for (int i = 0; i < M.getN(); i++) {
		for (int j = 0; j < M.getM(); j++)
			res[i] += A[j] && M[j][i];
		res[i] = res[i] % 2;
	}
	return res;
}

/********************************************************************************/

void CheckMatr::createCheckMatr(int m, int n) {
	resize(m, n);
	int k;
	for (int j = 0; j < n; j++) {
		k = j + 1;
		for (int i = m - 1; i >= 0; i--) {
			getMatr()[i][j] = k & 1;
			k >>= 1;
		}
	}
}

void CheckMatr::createCheckMatr() {
	int k;
	for (int j = 0; j < getN(); j++) {
		k = j + 1;
		for (int i = getM() - 1; i >= 0; i--) {
			getMatr()[i][j] = k & 1;
			k >>= 1;
		}
	}
}


void CheckMatr::transMatr() {
	CheckMatr tmp(getN(), getM());
	short t;
	for (int i = 0; i < getM(); i++)
		for (int j = 0; j < getN(); j++)
			tmp[j][i] = getMatr()[i][j];
	*this = tmp;
}

CheckMatr CheckMatr::getTransMatr() {
	CheckMatr tmp(getN(), getM());
	short t;
	for (int i = 0; i < getM(); i++)
		for (int j = 0; j < getN(); j++)
			tmp[j][i] = getMatr()[i][j];
	return tmp;
}

void CheckMatr::rotate() {
	CheckMatr tmp(getN(), getM());
	for (int i = 0; i < getM(); i++)
		for (int j = 0; j < getN(); j++) {
			tmp[j][tmp.getN() - 1 - i] = getMatr()[i][j];
		}
	*this = tmp;
}

CheckMatr CheckMatr::getRotate() {
	CheckMatr tmp(getN(), getM());
	for (int i = 0; i < getM(); i++)
		for (int j = 0; j < getN(); j++) {
			tmp[j][tmp.getN() - 1 - i] = getMatr()[i][j];
		}
	return tmp;
}

/**************************************************************************/

void GeneratorMatr::createGeneratorMatr(int m, int n) {
	resize(m, n);
	CheckMatr A(getN() - getM(), getN());
	CheckMatr B(getN() - getM(), getM());
	int i, j, k = 1, p = 0;
	for (j = 0; j < getN(); j++)
		if (j + 1 == k) k *= 2;
		else {
			for (i = 0; i < getN() - getM(); i++)
				B[i][p] = A[i][j];
			p++;
		}
	B.rotate();
	k = 1; p = 0;
	int a = 1, b;
	for (j = 0; j < getN(); j++)
		if (j + 1 == k) {
			for (i = 0; i < getM(); i++)
				getMatr()[i][j] = B[i][p];
			p++;
			k += 2;
		}
		else {
			b = a;
			for (i = getM() - 1; i >= 0; i--) {
				getMatr()[i][j] = b & 1;
				b >>= 1;
			}
			a++;
		}
}

void GeneratorMatr::createGeneratorMatr() {
	CheckMatr A(getN() - getM(), getN());
	CheckMatr B(getN() - getM(), getM());
	int i, j, k = 1, p = 0;
	for (j = 0; j < getN(); j++)
		if (j + 1 == k) k *= 2;
		else {
			for (i = 0; i < getN() - getM(); i++)
				B[i][p] = A[i][j];
			p++;
		}

	B.rotate();
	k = 1; p = 0;
	int q = 0;
	for (j = 0; j < getN(); j++)
		if (j + 1 == k) {
			for (i = 0; i < getM(); i++)
				getMatr()[i][j] = B[i][p];
			p++;
			k *= 2;
		}
		else {
			for (i = 0; i < getM(); i++)
				getMatr()[i][j] = i == q ? 1 : 0;
			q++;
		}
}