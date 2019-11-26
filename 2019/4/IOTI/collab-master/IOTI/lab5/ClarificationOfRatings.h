#pragma once
#include <iostream>
#include "Simplex_table.h"

class ClarSimplexTable : public Simplex_table {
public:
	ClarSimplexTable(long m, long n):Simplex_table(m, n) {};
	long clarification_step();  //��� ������ ��������� ������
	void clarification();		//����� ��������� ������, ���������� ��������-����� �� simplex_table
	bool is_last();				//�������� �� ������� ���������
	bool is_valid();			//�������� �� ������� ����������
};