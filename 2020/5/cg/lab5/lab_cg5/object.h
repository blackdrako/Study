#ifndef OBJECT_H
#define OBJECT_H


#include <QVector3D>
#include <QtMath>
#include <custompolygon.h>

class Object{
public:
    QVector <CustomPolygon> obj;
    Object() {}
    QVector<CustomPolygon> getObject();
    QVector3D getCenter();
    QVector3D getSize();
    void setPolygon(CustomPolygon p, int pos);
    void setPolygonColor(int i, QColor color);
};

class Cubes : public Object{
public:
    Cubes();
    Cubes(int range);
};


#endif // OBJECT_H
