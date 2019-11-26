#pragma once
#include <iostream>
#include "Simplex_table.h"

class DualSimplexTable : public Simplex_table {
public:
	Frac_arr F;	//m		//������������ ������� ������� ������������ ������ (� ��� ����� � ��������� ����)
	Frac_matr F_SLU;	//������������ ������� ����������� ������������ ������ (� ��� ����� � ��������� �����)
	long* F_base;		//������ �������� ���������� ������������ ������
	long fm, fn;		//������� ������� ����������� ������������ ������
	
	int* matching;		//����������� ����������, ������� - �, �������� - �
	int basesCount;

	DualSimplexTable(long m, long n) : 
		Simplex_table(m, n), 
		fm(n - m - 1), fn(fm+m+1), F(m), F_SLU(n - m, n) {};
		//fm(n - m - 1), fn(n), F(fm), F_SLU(n - m - 1, n) {};
	                                                                                                     
	//��������� ������������ ������ �� ��������
	void getDualTask();
	void getBases();
	void printAnswer();

};