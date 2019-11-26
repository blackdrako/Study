#include "pch.h"
#include <iostream>
#include "Simplex_shtraf.h"
#include <Windows.h>
#include "SimplexArtificial.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	long m, n, k;
	cout << "решить методом искусственного базиса (0), решить методом больших штрафов (1), решить симлекс-методом в общем виде(2): ";
	cin >> k; getchar();
	cout << "введите m и n: ";
	cin >> m >> n;
	SimplexArtificial A(m, n);
	SimplexShtraf B(m, n);
	Simplex_table C(m, n);
	switch (k){
		case 0:
			cout << "Введите коэффициенты системиы ограничений:" << endl;
			A.Input_SLU(cin);
			cout << "Введите коэффициенты целевой функции:" << endl;
			A.Input_Z(cin);
			A.simplexArtificial();
			break;
		case 1:
			cout << "Введите коэффициенты системиы ограничений:" << endl;
			B.Input_SLU(cin);
			cout << "Введите коэффициенты целевой функции:" << endl;
			B.Input_Z(cin);
			B.simplexShtraf();
			break;
		case 2:
			cout << "Введите коэффициенты системиы ограничений:" << endl;
			C.Input_SLU(cin);
			cout << "Введите коэффициенты целевой функции:" << endl;
			C.Input_Z(cin);
			C.Simplex();
	}
}
