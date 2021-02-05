#ifndef VECTOR_H
#define VECTOR_H
#include <QPointF>
#include <iostream>

class Matrix;

class Vector{
public:
    double v[3];
    Vector(double x, double y);
    Vector (QPointF &p);
    Vector (){v[0] = 0; v[1] = 0; v[2] = 1;}
    double x();
    double y();
    double operator[](unsigned i);
    QPoint getPoint();
    void setPoint(QPoint);
    friend Vector operator * (const Matrix &m, const Vector &v);

};

#endif // VECTOR_H
