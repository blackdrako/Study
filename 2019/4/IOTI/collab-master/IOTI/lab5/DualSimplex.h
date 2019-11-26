#pragma once
#include <iostream>
#include "Simplex_table.h"

class DualSimplexTable : public Simplex_table {
public:
	Frac_arr F;	//m		//коэффициенты целевой функции двойственной задачи (в том числе и свободный член)
	Frac_matr F_SLU;	//коэффициенты системы ограничений двойственной задачи (в том числе и свободные члены)
	long* F_base;		//массив базисных переменных двойственной задачи
	long fm, fn;		//размеры матрицы ограничений двойственной задачи
	
	int* matching;		//соответсвие переменных, индексы - х, значения - у
	int basesCount;

	DualSimplexTable(long m, long n) : 
		Simplex_table(m, n), 
		fm(n - m - 1), fn(fm+m+1), F(m), F_SLU(n - m, n) {};
		//fm(n - m - 1), fn(n), F(fm), F_SLU(n - m - 1, n) {};
	                                                                                                     
	//Получение двойственной задачи из исходной
	void getDualTask();
	void getBases();
	void printAnswer();

};