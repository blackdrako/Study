#pragma once
#include "Frac_matr.h"
#include "Fraction.h"  //уже включена в Frac_matr.h, здесь для лучшей читабельности
#include <string>

class Simplex_table{
public:
	Frac_arr Z;			//коэффициенты целевой функции (в том числе и свободный член)
	Frac_matr SLU;		//коэффициенты системы ограничений (в том числе и свободные члены)
	Frac_matr T;		//числовая часть симплекс-таблицы
	long *base;			//массив базисных переменных
	long m, n;			//размеры матрицы ограниченйи
	long x, y;			//размеры симплекс-таблицы
//public:
	Simplex_table(long m1, long n1) : m(m1), n(n1), Z(n1), SLU(m1, n1) {}
	/*ввод целевой функции*/
	void Input_Z(std::istream&);
	/*ввод системы ограничений*/
	void Input_SLU(std::istream&);
	/* 1 - система СЛУ и целевая функция удовлетворяют условию применения симплекс-метода, иначе - 0*/
	long Check_SLU();
	/*Составляет первую симплекс таблицу по СЛУ и целевой функции. x и y - размеры сиплекс-таблицы*/
	void GetSimplexTable();
	/*Шаг симплекс-метода (переход к следующей симплекс-таблице)*/
	long SimplexStep();
	long Simplex();
	/*Вывод на экран симплкс-таблицы*/
	friend std::ostream& operator <<(std::ostream&, Simplex_table&);
	//~Simplex_table();
};