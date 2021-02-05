#ifndef OBJECT_H
#define OBJECT_H

#include <QVector3D>
#include <QMatrix4x4>
#include <QtMath>

class Object{
protected:
    QVector<QVector<QVector3D>> obj;
public:
    Object() {};
    QVector<QVector<QVector3D>> getObject();
    QVector3D getCenter();
    QVector3D getSize();
};

class Cubes : public Object{
public:
    Cubes();
    Cubes(int range);
};

#endif // OBJECT_H
