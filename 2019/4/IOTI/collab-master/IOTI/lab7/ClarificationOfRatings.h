#pragma once
#include <iostream>
#include "Simplex_table.h"

class ClarSimplexTable : public Simplex_table {
public:
	ClarSimplexTable(long m, long n) :Simplex_table(m, n) {};
	long clarification_step();  //шаг метода уточнения оценок
	void clarification();		//метод уточнения оценок, использует симплекс-метод из simplex_table
	bool is_last();				//Является ли таблица последней
	bool is_valid();			//Является ли таблица допустимой
};
