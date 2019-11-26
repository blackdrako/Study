#pragma once
#include "Simplex_table.h"

class SimplexArtificial: public Simplex_table
{
	Frac_arr Z_M;	//������������ ������� ������� (� ��� ����� � ��������� ����)
	Frac_matr SLU_y, T_y;	//�������� ����� ��������-�������
	long x1, y1;		//������� ��������-������� ������� �������� �������
public:
	SimplexArtificial(long m1, long n1) : Simplex_table(m1, n1), Z_M(n1 + m1), SLU_y(m1, m1 + n1), T_y() {}
	/*���� ������� �������*/
	void getSimplexArtificialTable();
	/*��� ��������-������ (������� � ��������� ��������-�������)*/
	long simplexArtificialStep();
	void replace_y();
	long simplexArtificial();
	/*����� �� ����� �������-������� � ������ ��������������� ������ ������� �������*/
	std::ostream& outputArtificialTable(std::ostream&);
};

