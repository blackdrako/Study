#include "BranchesAndBorders.h"

using namespace std;

void BranchesAndBorders::Input(Frac_matr& M, Frac_arr& Z) {
	cout << "Введите коэффициенты системиы ограничений:" << endl;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> M[i][j];
	cout << "Введите коэффициенты целевой функции:" << endl;
	for (int i = 0; i < n; i++)
		cin >> Z[i];
}

bool BranchesAndBorders::check_int(long m, long n, Frac_matr& M) {
	for (int i = 0; i < m; i++)
		if (M[i][n - 1].denominator != 1) return false;
	return true;
}

bool BranchesAndBorders::isPsevdo(long m, long n, Frac_matr& M) {
	for (int i = 0; i < m; i++)
		if (M[i][n - 1].numerator < 0) return true;
	return false;
}

void BranchesAndBorders::copyToSimp(SimplexArtificial &S, Frac_matr &M, Frac_arr &Z) {
	for (int i = 0; i < S.m; i++) {
		for (int j = 0; j < S.n; j++) {
			S.SLU[i][j] = M[i][j];
		}
	}
	for (int i = 0; i < S.n; i++) {
		S.Z[i] = Z[i];
	}
}

void BranchesAndBorders::copyFromSimp(SimplexArtificial &S, Frac_matr &M, Frac_arr &Z) {
	M.Create(S.m, S.n);
	for (int i = 0; i < S.m; i++) {
		for (int j = 0; j < S.n - 1; j++) {
			M[i][j] = S.T[i][j + 1];
		}
		M[i][S.n - 1] = S.T[i][0];
	}
	for (int i = 0; i < S.n - 1; i++) {
		Z[i].numerator = -S.T[S.x - 1][i + 1].numerator;
		Z[i].denominator = S.T[S.x - 1][i + 1].denominator;
	}
	Z[S.n - 1] = S.T[S.x - 1][0];
}

void BranchesAndBorders::copyToClar(ClarSimplexTable & C, Frac_matr &M, Frac_arr &Z) {
	for (int i = 0; i < C.m; i++) {
		for (int j = 0; j < C.n; j++) {
			C.SLU[i][j] = M[i][j];
		}
	}
	for (int i = 0; i < C.n; i++) {
		C.Z[i] = Z[i];
	}
}

void BranchesAndBorders::copyFromClar(ClarSimplexTable & C, Frac_matr &M, Frac_arr &Z) {
	M.Create(C.m, C.n);
	for (int i = 0; i < C.m; i++) {
		for (int j = 0; j < C.n - 1; j++) {
			M[i][j] = C.T[i][j + 1];
		}
		M[i][C.n - 1] = C.T[i][0];
	}
	for (int i = 0; i < C.n - 1; i++) {
		Z[i].numerator = -C.T[C.x - 1][i + 1].numerator;
		Z[i].denominator = C.T[C.x - 1][i + 1].denominator;
	}
	Z[C.n - 1] = C.T[C.x - 1][0];
}

void BranchesAndBorders::addRestrictions_1(long* base, Frac_matr &M, Frac_arr &Z) {
	int k = 0;
	while (M[k][M.n - 1].denominator == 1) k++;
	Frac_matr a(M.m + 1, M.n + 1);
	for (int i = 0; i < M.m; i++) {
		for (int j = 0; j < M.n - 1; j++)
			a[i][j] = M[i][j];
		a[i][M.n - 1] = 0;
		a[i][M.n] = M[i][M.n - 1];
	}
	for (int i = 0; i < M.n - 1; i++)
		a[M.m][i] = 0;
	Fraction tmp(1, 1);
	tmp += M[k][M.n - 1]; tmp += -(M[k][M.n - 1].mod());
	a[M.m][M.n - 1] = -1; a[M.m][M.n] = tmp;
	a[M.m][base[k] - 1] = 1;
	Frac_arr b(M.n + 1);
	for (int i = 0; i < M.n - 1; i++)
		b[i] = Z[i];
	b[M.n - 1] = 0; b[M.n] = Z[M.n - 1];
	M = a;
	Z = b;
}

void BranchesAndBorders::addRestrictions_2(long* base, Frac_matr &M, Frac_arr &Z) {
	int k = 0;
	while (M[k][M.n - 1].denominator == 1) k++;
	Frac_matr a(M.m + 1, M.n + 1);
	for (int i = 0; i < M.m; i++) {
		for (int j = 0; j < M.n - 1; j++)
			a[i][j] = M[i][j];
		a[i][M.n - 1] = 0;
		a[i][M.n] = M[i][M.n - 1];
	}
	for (int i = 0; i < M.n - 1; i++)
		a[M.m][i] = 0;
	Fraction tmp = M[k][M.n - 1];
	tmp += -(M[k][M.n - 1].mod());
	a[M.m][M.n - 1] = 1; a[M.m][M.n] = tmp;
	a[M.m][base[k] - 1] = 1;
	Frac_arr b(M.n + 1);
	for (int i = 0; i < M.n - 1; i++)
		b[i] = Z[i];
	b[M.n - 1] = 0; b[M.n] = Z[M.n - 1];
	M = a;
	Z = b;
}

void BranchesAndBorders::branchesAndBordersSolution() {
	SimplexArtificial S(m, n);
	Frac_matr M(m, n);
	Frac_arr Z(n);
	Input(M, Z);
	copyToSimp(S, M, Z);
	S.simplexArtificial();
	cout << S;
	copyFromSimp(S, M, Z);
	if (!check_int(m, n, M)) {
		branchesAndBordersStep_1(m + 1, n + 1, S.base, M, Z);
		branchesAndBordersStep_2(m + 1, n + 1, S.base, M, Z);
	}
	else outputSolution(S);
}

void BranchesAndBorders::branchesAndBordersStep_1(long m, long n, long *base, Frac_matr M, Frac_arr Z) {
	int f;
	ClarSimplexTable C(m, n);
	SimplexArtificial S(m, n);
	addRestrictions_1(base, M, Z);
	if (isPsevdo(m, n, M)) {
		copyToClar(C, M, Z);
		C.clarification();
		copyFromClar(C, M, Z);
		f = 1;
	}
	else {
		copyToSimp(S, M, Z);
		S.simplexArtificial();
		cout << S << endl; ///
		copyFromSimp(S, M, Z);
		f = 2;
	}
	if (!check_int(m, n, M)) {
		if (f == 1) {
			branchesAndBordersStep_1(m + 1, n + 1, C.base, M, Z);
			branchesAndBordersStep_2(m + 1, n + 1, C.base, M, Z);
		}
		else {
			branchesAndBordersStep_1(m + 1, n + 1, S.base, M, Z);
			branchesAndBordersStep_2(m + 1, n + 1, S.base, M, Z);
		}
	}
	else
		if (f == 1) outputSolution(C);
		else outputSolution(S);
}

void BranchesAndBorders::branchesAndBordersStep_2(long m, long n, long* base, Frac_matr M, Frac_arr Z) {
	int f;
	ClarSimplexTable C(m, n);
	SimplexArtificial S(m, n);
	addRestrictions_2(base, M, Z);
	if (isPsevdo(m, n, M)) {
		copyToClar(C, M, Z);
		C.clarification();
		copyFromClar(C, M, Z);
		f = 1;
	}
	else {
		copyToSimp(S, M, Z);
		S.simplexArtificial();
		cout << S << endl; ///
		copyFromSimp(S, M, Z);
		f = 2;
	}
	if (!check_int(m, n, M)) {
		if (f == 1) {
			branchesAndBordersStep_1(m + 1, n + 1, C.base, M, Z);
			branchesAndBordersStep_2(m + 1, n + 1, C.base, M, Z);
		}
		else {
			branchesAndBordersStep_1(m + 1, n + 1, S.base, M, Z);
			branchesAndBordersStep_2(m + 1, n + 1, S.base, M, Z);
		}
	}
	else
		if (f == 1) outputSolution(C);
		else outputSolution(S);
}

void BranchesAndBorders::outputSolution(SimplexArtificial & S) {
	if (flag == 0) {
		max_ = S.T[S.x - 1][0];
		flag = 1;
	}
	if (S.T[S.x - 1][0] >= max_) {
		cout << S;
		cout << "Z_max = " << S.T[S.x - 1][0] << endl;
	}
}

void BranchesAndBorders::outputSolution(ClarSimplexTable & C) {
	if (flag == 0) {
		max_ = C.T[C.x - 1][0];	
		flag = 1;
	}
	if (C.T[C.x - 1][0] >= max_) {
		cout << C;
		cout << "Z_max = " << C.T[C.x - 1][0] << endl;
	}
}
