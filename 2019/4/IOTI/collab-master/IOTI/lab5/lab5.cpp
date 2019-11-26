#include <iostream>
#include "DualSimplex.h"
#include "ClarificationOfRatings.h"
using namespace std;

int main(){
	setlocale(0, "RUS");
	long m, n;
	cout << "Каким методом хотите решить? 0 - двойственный СМ, 1 - метод последовательного уточнения оценок" << endl;
	if (getchar() == '0') {
		cout << "Введите m и n: ";
		cin >> m >> n;
		DualSimplexTable a(m, n);
		cout << "Введите коэффициенты системиы ограничений:" << endl;
		a.Input_SLU(cin);
		cout << "Введите коэффициенты целевой функции:" << endl;
		a.Input_Z(cin);
		a.getDualTask();
		a.Simplex();
		a.printAnswer();
	}
	else {
		cout << "Введите m и n: ";
		cin >> m >> n;
		ClarSimplexTable a(m, n);
		cout << "Введите коэффициенты системиы ограничений:" << endl;
		a.Input_SLU(cin);
		cout << "Введите коэффициенты целевой функции:" << endl;
		a.Input_Z(cin);
		a.clarification();
	}
}


/*Составить и отладить программу решения пары симметрично двойственных задач двойственным симплекс - методом.
Составить и отладить программу решения задачи ЛП методом последовательного уточнения оценок.*/