#ifndef STAMP_H
#define STAMP_H
#include <QPolygon>
#include <matrix.h>

class Stamp{
    QRect s;
    int direction;
    int translation;
public:
    Stamp();
    Stamp(QRect newStamp):s(newStamp), direction(1), translation(0){}
    Stamp(QPoint tl, QPoint br);
    void move();
    void changeDirection();
    void setDirection(int newDirection);
    int getLowerPos();
    int getTranslation();
    QRect getRect();
};
#endif // STAMP_H
