#pragma once
#include "Simplex_table.h"

class SimplexArtificial: public Simplex_table
{
public:
	Frac_arr Z_M;	//������������ ������� ������� (� ��� ����� � ��������� ����)
	Frac_matr SLU_y, T_y;	//�������� ����� ��������-�������
	long x1, y1;		//������� ��������-������� ������� �������� �������

	SimplexArtificial(long m1, long n1) : Simplex_table(m1, n1), Z_M(n1 + m1), SLU_y(m1, m1 + n1), T_y(), x1(0), y1(0) {}
	/*���� ������� �������*/
	void getSimplexArtificialTable();
	/*��� ��������-������ (������� � ��������� ��������-�������)*/
	long simplexArtificialStep();
	void replace_y();
	long simplexArtificial();
	/*����� �� ����� �������-������� � ������ ��������������� ������ ������� �������*/
	void outputArtificialTable(std::ostream&);
};