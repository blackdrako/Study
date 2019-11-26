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
		if (i >= vec.size()) throw LogMatrException("Ошибка! Выход за границы вектора!");
		return vec[i];
	}
	void operator =(short*);
	friend ostream& operator << (ostream&, LogVec&);						//Вывод вектора
	friend istream& operator >> (istream&, LogVec&);						//Ввод вектора
};
*/


// Важно! Вектор-строку для взаимодействия с матрицей задавать как vector<short>
class LogMatr {
	vector<vector<short>> matr;
	int m, n;
public:
	LogMatr() : m(0), n(0), matr(0) {}
	LogMatr(int m, int n) : m(m), n(n), matr(m) {
		for (int i = 0; i < m; i++)
			matr[i] = vector<short>(n);
	}
	int getM() { return m; }
	int getN() { return n; }
	vector<vector<short>>& getMatr() { return matr; }
	vector<short>& operator[](int i) {
		if (i >= m) throw LogMatrException("Ошибка! Выход за границы матрицы!");
		return matr[i];
	}
	void resize(int, int);
	friend ostream& operator << (ostream&, LogMatr&);						//Вывод матрицы
	friend istream& operator >> (istream&, LogMatr&);						//Ввод матрицы
	friend vector<short> operator *(vector<short>&, LogMatr&);				//Умножение вектора на матрицу
};

class CheckMatr : public LogMatr {
public:
	CheckMatr() : LogMatr() {}
	CheckMatr(int m, int n) : LogMatr(m, n) {
		createCheckMatr();
	}
	void createCheckMatr(int, int);											//Создание проверочной матрицы с заданными размерами
	void createCheckMatr();													//Создание проверочной матрицы с текущими размерами
	void transMatr();														//Транспонирование матрицы с изменением в объекте
	CheckMatr getTransMatr();												//Возвращает транспонированную матрицу без изменения в объекте
	void rotate();															//поворот матрицы на 90 градусов по часовой стрелке сизменением в объекте
	CheckMatr getRotate();													//возвращает повёрнутую на 90 градусов по часовой стрелке матрицу без изменения в объекте
};

class GeneratorMatr : public LogMatr {
public:
	GeneratorMatr() : LogMatr() {}
	GeneratorMatr(int m, int n) : LogMatr(m, n) {
		createGeneratorMatr();
	}
	void createGeneratorMatr(int, int);									//Создание порождающей матрицы с заданными размерами
	void createGeneratorMatr();											//Создание порождающщей матрицы с текущими размерами
};