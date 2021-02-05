#include "custompolygon.h"

CustomPolygon::CustomPolygon(){

}

CustomPolygon::CustomPolygon(QVector<QVector3D> newPolygon){
    polygon = newPolygon;
    depth = 0;
    for (int i = 0; i < newPolygon.size(); i++){
        depth += newPolygon[i].z();
    }
    color = Qt::red;
    color.setAlpha(150);
    isClicked = false;
}

QVector <QVector3D> CustomPolygon::getPolygon(){
    return polygon;
}

float CustomPolygon::getDepth(){
    depth = 0;
    for (int i = 0; i < polygon.size(); i++){
        depth += polygon[i].z();
    }
    return depth;
}

void CustomPolygon::setVector(QVector3D v, int pos){
    polygon[pos] = v;
}

QColor CustomPolygon::getColor(){
    return color;
}

void CustomPolygon::setColor(QColor c){
    color = c;
}

int CustomPolygon::size(){
    return polygon.size();
}

QVector3D CustomPolygon::operator [] (int i){
    return polygon[i];
}

void CustomPolygon::setClicked(){
    isClicked = true;
}

void CustomPolygon::setNumber(int n){
    number = n;
}

int CustomPolygon::getNumber(){
    return  number;
}
