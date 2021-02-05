#ifndef CIRCLE_H
#define CIRCLE_H
#include <QRect>
#include <QPainter>
#include <vector.h>
#include <matrix.h>

class Circle{
    QRect rect;
    int direction;
    int inc;
    bool reachedReadyPos;
    bool scalingNeeded;
public:
    Circle();
    Circle(QRect r);
    ~Circle(){}
    QRect getRect();
    //0 - вдоль оси х, 1 - вдоль оси у; inc - знак приращения, для отражения -1:
    void move();
    void draw(QPainter * painter);
    void scale();

    int getDirection();
    int getInc();
    int getWidth();

    void setReadyPos(bool);
    void setDirection(int newDirection);
    void setInc(int newInc);

    bool isReady();
    bool isScalingNeeded();
};

#endif // CIRCLE_H
