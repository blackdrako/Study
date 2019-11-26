#pragma once
#include "Simplex_table.h"

class SimplexShtraf: public Simplex_table
{
	Frac_arr Z_M;	//������������ ������� ������� (� ��� ����� � ��������� ����)
	Frac_matr SLU_y, T_y;	//�������� ����� ��������-�������
	long x1, y1;		//������� ��������-������� ������� �������� �������
public:
	SimplexShtraf(long m1, long n1): Simplex_table(m1, n1), Z_M(n1 + m1), SLU_y(m1, m1 + n1), T_y() {}
	/*���� ������� �������*/
	void getSimplexShtrafTable();
	/*��� ��������-������ (������� � ��������� ��������-�������)*/
	long simplexShtrafStep();
	long simplexShtraf();
	/*����� �� ����� �������-������� � ������ ��������������� ������ ������� �������*/
	std::ostream& outputShtrafTable(std::ostream&);
	Fraction maxKoef();
	//~Simplex_table();
};