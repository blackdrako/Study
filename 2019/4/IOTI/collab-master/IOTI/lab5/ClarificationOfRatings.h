#pragma once
#include <iostream>
#include "Simplex_table.h"

class ClarSimplexTable : public Simplex_table {
public:
	ClarSimplexTable(long m, long n):Simplex_table(m, n) {};
	long clarification_step();  //шаг метода уточнени€ оценок
	void clarification();		//метод уточнени€ оценок, использует симплекс-метод из simplex_table
	bool is_last();				//явл€етс€ ли таблица последней
	bool is_valid();			//явл€етс€ ли таблица допустимой
};