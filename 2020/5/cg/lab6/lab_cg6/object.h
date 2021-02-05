#ifndef OBJECT_H
#define OBJECT_H


#include <QVector>
#include <QVector3D>
#include <QtOpenGL/QtOpenGL>
#include <QtOpenGL/QGL>
#include <QtOpenGL/QGLWidget>

struct Vertex{
    Vertex(){}
    Vertex(QVector3D p, QVector2D t, QVector3D n):
        position(p), texCoord(t), normal(n){}
    Vertex(QVector3D p, QVector3D n):
        position(p), normal(n){}
    Vertex(QVector3D p, QVector2D t):
        position(p), texCoord(t){}
    Vertex(QVector3D p):
        position(p){}
    QVector3D position;
    QVector2D texCoord;
    QVector3D normal;
};

class Object{
    QVector <Vertex> v;
    QVector <uint> indicies;
    QVector3D center;
public:
    Object();
    ~Object();
    void init();
    bool read(QString filename);
    QVector <Vertex> getV(){return v;}
    QVector <uint> getIndicies(){return indicies;}
    QVector3D getCenter();
    void translate();
};



#endif // OBJECT_H
