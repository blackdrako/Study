#pragma once
#include "Frac_matr.h"
#include "Fraction.h"  //��� �������� � Frac_matr.h, ����� ��� ������ �������������
#include <string>

class Simplex_table{
public:
	Frac_arr Z;			//������������ ������� ������� (� ��� ����� � ��������� ����)
	Frac_matr SLU;		//������������ ������� ����������� (� ��� ����� � ��������� �����)
	Frac_matr T;		//�������� ����� ��������-�������
	long *base;			//������ �������� ����������
	long m, n;			//������� ������� �����������
	long x, y;			//������� ��������-�������
//public:
	Simplex_table(long m1, long n1) : m(m1), n(n1), Z(n1), SLU(m1, n1) {}
	/*���� ������� �������*/
	void Input_Z(std::istream&);
	/*���� ������� �����������*/
	void Input_SLU(std::istream&);
	/* 1 - ������� ��� � ������� ������� ������������� ������� ���������� ��������-������, ����� - 0*/
	long Check_SLU();
	/*���������� ������ �������� ������� �� ��� � ������� �������. x � y - ������� �������-�������*/
	void GetSimplexTable();
	/*��� ��������-������ (������� � ��������� ��������-�������)*/
	long SimplexStep();
	long Simplex();
	/*����� �� ����� �������-�������*/
	friend std::ostream& operator <<(std::ostream&, Simplex_table&);
	//~Simplex_table();
};