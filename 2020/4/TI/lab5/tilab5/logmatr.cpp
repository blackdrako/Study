#include <vector>
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
    void resize(int m, int n){
        this->m = m;
        this->n = n;
        matr.resize(m);
        for (int i = 0; i < m; i++)
            matr[i].resize(n);
    }
    friend ostream& operator << (ostream & out, LogMatr & A) {
        for (int i = 0; i < A.getM(); i++) {
            for (int j = 0; j < A.getN(); j++)
                out << A[i][j] << " ";
            out << endl;
        }
        return out;
    }					//Вывод матрицы
    friend istream& operator >> (istream & in, LogMatr & A) {
        for (int i = 0; i < A.getM(); i++)
            for (int j = 0; j < A.getN(); j++)
                in >> A[i][j];
        return in;
    }						//Ввод матрицы
    friend vector<short> operator *(vector<short> & A, LogMatr & M) {
        if (A.size() != M.getM()) throw LogMatrException("Ошибка! Длина вектор-строки не равна кол-ву строк матрицы!");
        vector<short> res(M.getN());
        for (int i = 0; i < M.getN(); i++) {
            for (int j = 0; j < M.getM(); j++)
                res[i] += A[j] && M[j][i];
            res[i] = res[i] % 2;
        }
        return res;
    }				//Умножение вектора на матрицу
};

class CheckMatr : public LogMatr {
public:
    CheckMatr() : LogMatr() {}
    CheckMatr(int m, int n) : LogMatr(m, n) {
        createCheckMatr();
    }
    void createCheckMatr(int m, int n) {
        resize(m, n);
        int k;
        for (int j = 0; j < n; j++) {
            k = j + 1;
            for (int i = m - 1; i >= 0; i--) {
                getMatr()[i][j] = k & 1;
                k >>= 1;
            }
        }
    }								//Создание проверочной матрицы с заданными размерами
    void createCheckMatr() {
        int k;
        for (int j = 0; j < getN(); j++) {
            k = j + 1;
            for (int i = getM() - 1; i >= 0; i--) {
                getMatr()[i][j] = k & 1;
                k >>= 1;
            }
        }
    }													//Создание проверочной матрицы с текущими размерами
    void transMatr() {
        CheckMatr tmp(getN(), getM());
        short t;
        for (int i = 0; i < getM(); i++)
            for (int j = 0; j < getN(); j++)
                tmp[j][i] = getMatr()[i][j];
        *this = tmp;
    }														//Транспонирование матрицы с изменением в объекте
    CheckMatr getTransMatr() {
        CheckMatr tmp(getN(), getM());
        short t;
        for (int i = 0; i < getM(); i++)
            for (int j = 0; j < getN(); j++)
                tmp[j][i] = getMatr()[i][j];
        return tmp;
    }												//Возвращает транспонированную матрицу без изменения в объекте
    void rotate() {
        CheckMatr tmp(getN(), getM());
        for (int i = 0; i < getM(); i++)
            for (int j = 0; j < getN(); j++) {
                tmp[j][tmp.getN() - 1 - i] = getMatr()[i][j];
            }
        *this = tmp;
    }															//поворот матрицы на 90 градусов по часовой стрелке сизменением в объекте
    CheckMatr getRotate() {
        CheckMatr tmp(getN(), getM());
        for (int i = 0; i < getM(); i++)
            for (int j = 0; j < getN(); j++) {
                tmp[j][tmp.getN() - 1 - i] = getMatr()[i][j];
            }
        return tmp;
    }													//возвращает повёрнутую на 90 градусов по часовой стрелке матрицу без изменения в объекте
};

class GeneratorMatr : public LogMatr {
public:
    GeneratorMatr() : LogMatr() {}
    GeneratorMatr(int m, int n) : LogMatr(m, n) {
        createGeneratorMatr();
    }
    void createGeneratorMatr(int m, int n) {
        resize(m, n);
        CheckMatr A(getN() - getM(), getN());
        CheckMatr B(getN() - getM(), getM());
        int i, j, k = 1, p = 0;
        for (j = 0; j < getN(); j++)
            if (j + 1 == k) k *= 2;
            else {
                for (i = 0; i < getN() - getM(); i++)
                    B[i][p] = A[i][j];
                p++;
            }
        B.rotate();
        k = 1; p = 0;
        int a = 1, b;
        for (j = 0; j < getN(); j++)
            if (j + 1 == k) {
                for (i = 0; i < getM(); i++)
                    getMatr()[i][j] = B[i][p];
                p++;
                k += 2;
            }
            else {
                b = a;
                for (i = getM() - 1; i >= 0; i--) {
                    getMatr()[i][j] = b & 1;
                    b >>= 1;
                }
                a++;
            }
    }									//Создание порождающей матрицы с заданными размерами
    void createGeneratorMatr() {
        CheckMatr A(getN() - getM(), getN());
        CheckMatr B(getN() - getM(), getM());
        int i, j, k = 1, p = 0;
        for (j = 0; j < getN(); j++)
            if (j + 1 == k) k *= 2;
            else {
                for (i = 0; i < getN() - getM(); i++)
                    B[i][p] = A[i][j];
                p++;
            }

        B.rotate();
        k = 1; p = 0;
        int q = 0;
        for (j = 0; j < getN(); j++)
            if (j + 1 == k) {
                for (i = 0; i < getM(); i++)
                    getMatr()[i][j] = B[i][p];
                p++;
                k *= 2;
            }
            else {
                for (i = 0; i < getM(); i++)
                    getMatr()[i][j] = i == q ? 1 : 0;
                q++;
            }
    }										//Создание порождающщей матрицы с текущими размерами
};
