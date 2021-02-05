#ifndef MATRIX_H
#define MATRIX_H
#include "vector.h"
#include <cmath>
#include <QTransform>

class Matrix{

public:
    double m[3][3];
    Matrix();
    Matrix(const Matrix &newMatrix);
    Matrix& operator = (const Matrix &newMatrix);

    static Matrix rotationMatrix(double angle);
    static Matrix scalingMatrix(double kx, double ky);
    //0 - ось Х, 1 - ось Y
    static Matrix reflectionMatrix(int axis);
    static Matrix translationMatrix(double dx, double dy);

    friend Matrix operator * (const Matrix &m1, const Matrix &m2);
    friend Vector operator * (const Matrix &m, const Vector &v);
};

#endif // MATRIX_H
