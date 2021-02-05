#include "vector.h"

Vector::Vector(double x, double y){
    v[0] = x;
    v[1] = y;
    v[2] = 1;
}

Vector::Vector(QPointF &p){
    v[0] = p.x();
    v[1] = p.y();
    v[2] = 1;
}

double Vector::x(){
    return v[0];
}

double Vector::y(){
    return v[1];
}

double Vector::operator[](unsigned int i){
    return v[i];
}

QPoint Vector::getPoint(){
    return QPoint(v[0], v[1]);
}

void Vector::setPoint(QPoint x){
    v[0] = x.x();
    v[1] = x.y();
    v[2] = 1;
}
