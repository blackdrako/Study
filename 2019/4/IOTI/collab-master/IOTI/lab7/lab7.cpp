#include <iostream>
#include "Gomory.h"
#include <Windows.h>
#include "BranchesAndBorders.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	long m, n;
	cout << "Введите m и n: ";
	cin >> m >> n;
	Gomory G(m, n);
	G.Input();
	G.GomorySolution();
	/*BranchesAndBorders B(m, n);
	B.branchesAndBordersSolution();*/
}