#pragma once
#include <iostream>
#include <vector>
#include <exception>
using namespace std;

class LogMatrException : public exception {
	std::string err_txt;
public:
	LogMatrException(std::string s) : err_txt(s) {}
	const char* what() const noexcept {
		return err_txt.c_str();
	}
};

/*****************************************************************************************/

/*
class LogVec {
	vector<short> vec;
public:
	LogVec() : vec(0) {}
	LogVec(int n) : vec(n) {}
	void resize(int n) { vec.resize(n); }
	int getSize() { return vec.size(); }
	short& operator[](int i) {
		if (i >= vec.size()) throw LogMatrException("������! ����� �� ������� �������!");
		return vec[i];
	}
	void operator =(short*);
	friend ostream& operator << (ostream&, LogVec&);						//����� �������
	friend istream& operator >> (istream&, LogVec&);						//���� �������
};
*/


// �����! ������-������ ��� �������������� � �������� �������� ��� vector<short>
class LogMatr{
	vector<vector<short>> matr;
	int m, n;
public:
	LogMatr() : m(0), n(0), matr(0) {}
	LogMatr(int m, int n) : m(m), n(n), matr(m){
		for (int i = 0; i < m; i++)
			matr[i] = vector<short>(n);
	}
	int getM() { return m;}
	int getN() { return n;}
	vector<vector<short>>& getMatr() { return matr; }
	vector<short>& operator[](int i) {
		if (i >= m) throw LogMatrException("������! ����� �� ������� �������!");
		return matr[i];
	}
	void resize(int, int);
	friend ostream& operator << (ostream&, LogMatr&);						//����� �������
	friend istream& operator >> (istream&, LogMatr&);						//���� �������
	friend vector<short> operator *(vector<short>&, LogMatr&);				//��������� ������� �� �������
};

class CheckMatr : public LogMatr {
public:
	CheckMatr() : LogMatr() {}
	CheckMatr(int m, int n) : LogMatr(m, n) {
		createCheckMatr();
	}
	void createCheckMatr(int, int);											//�������� ����������� ������� � ��������� ���������
	void createCheckMatr();													//�������� ����������� ������� � �������� ���������
	void transMatr();														//���������������� ������� � ���������� � �������
	CheckMatr getTransMatr();												//���������� ����������������� ������� ��� ��������� � �������
	void rotate();															//������� ������� �� 90 �������� �� ������� ������� ����������� � �������
	CheckMatr getRotate();													//���������� ��������� �� 90 �������� �� ������� ������� ������� ��� ��������� � �������
};

class GeneratorMatr : public LogMatr {
public:
	GeneratorMatr() : LogMatr() {}
	GeneratorMatr(int m, int n) : LogMatr(m, n) {
		createGeneratorMatr();
	}
	void createGeneratorMatr(int, int);									//�������� ����������� ������� � ��������� ���������
	void createGeneratorMatr();											//�������� ������������ ������� � �������� ���������
};