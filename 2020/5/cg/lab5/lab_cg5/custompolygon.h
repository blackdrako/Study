#ifndef CUSTOMPOLYGON_H
#define CUSTOMPOLYGON_H


#include <QVector>
#include <QVector3D>
#include <QColor>

class CustomPolygon{
    QVector <QVector3D> polygon;
    QColor color;
    float depth;
    bool isClicked;
    int number;
public:
    CustomPolygon();
    CustomPolygon(QVector<QVector3D>);

    QVector <QVector3D> getPolygon();
    float getDepth();
    QColor getColor();

    void setVector(QVector3D v, int pos);
    void setColor(QColor);
    void setClicked();
    void setNumber(int);

    int getNumber();
    int size();

    bool isColored(){return isClicked;}

    QVector3D operator [](int i);
};

#endif // CUSTOMPOLYGON_H
