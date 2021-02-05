#include "matrix.h"
#include <QDebug>

Matrix::Matrix(): m{{0, 0, 0}, {0, 0, 0}, {0, 0, 1}}{
}

Matrix::Matrix(const Matrix &newMatrix){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            this->m[i][j] = newMatrix.m[i][j];
        }
    }
}

Matrix& Matrix::operator = (const Matrix &newMatrix){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            this->m[i][j] = newMatrix.m[i][j];
        }
    }
    return *this;
}

Matrix operator * (const Matrix &m1, const Matrix &m2){
    Matrix res = Matrix();
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            for (int k = 0; k < 3; k++){
                res.m[i][j] += m1.m[i][k] * m2.m[k][j];
            }
        }
    }
    return res;
}

Vector operator * (const Matrix &m, const Vector &v){
    Vector res = Vector(0, 0);
    res.v[0] = m.m[0][0] * v.v[0] + m.m[0][1] * v.v[1] + m.m[0][2] * v.v[2];
    res.v[1] = m.m[1][0] * v.v[0] + m.m[1][1] * v.v[1] + m.m[1][2] * v.v[2];
    res.v[2] = m.m[2][0] * v.v[0] + m.m[2][1] * v.v[1] + m.m[2][2] * v.v[2];
    return res;
}

Matrix Matrix::rotationMatrix(double angle){
    angle *= M_PI / 180;
    Matrix res;
    res.m[0][0] = cos(angle);
    res.m[0][1] = -sin(angle);
    res.m[1][0] = sin(angle);
    res.m[1][1] = cos(angle);
    res.m[2][2] = 1;
    return res;
}

Matrix Matrix::scalingMatrix(double kx, double ky){
    Matrix res;
    res.m[0][0] = kx;
    res.m[1][1] = ky;
    res.m[2][2] = 1;
    return res;
}
    //0 - ось Х, 1 - ось Y
Matrix Matrix::reflectionMatrix(int axis){
    Matrix res = Matrix();
    if (!axis){
       res.m[0][0] = -1;
       res.m[1][1] = 1;
       res.m[2][2] = 1;
    } else {
        res.m[0][0] = 1;
        res.m[1][1] = -1;
        res.m[2][2] = 1;
    return res;
    }
}

Matrix Matrix::translationMatrix(double dx, double dy){
    Matrix res = Matrix();
    res.m[0][0] = 1;
    res.m[1][1] = 1;
    res.m[2][2] = 1;
    res.m[0][2] = dx;
    res.m[1][2] = dy;
    return res;

}
