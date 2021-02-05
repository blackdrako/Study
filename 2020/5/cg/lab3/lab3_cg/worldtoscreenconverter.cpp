#include "worldtoscreenconverter.h"

WorldToScreenConverter::WorldToScreenConverter(const QRect& screen, double x1, double x2, double y1, double y2){
    _screen = screen;
    _x1 = x1;
    _x2 = x2;
    _y1 = y1;
    _y2 = y2;
}

QPoint WorldToScreenConverter::toScr(double x, double y){
    return QPoint(X(x), Y(y));
}

QPoint WorldToScreenConverter::toScr(const QPointF &w){
    return this->toScr(w.x(), w.y());
}

QPointF WorldToScreenConverter::toWrd(int X, int Y){
   return QPointF(x(X), y(Y));
}

QPointF WorldToScreenConverter::toWrd(const QPoint &s){
    return this->toWrd(s.x(), s.y());
}

double WorldToScreenConverter::x(int X){
     return ((double)(X - _screen.left()) / _screen.width() * (_x2 - _x1)) + _x1;
}

double WorldToScreenConverter::y(int Y){
     return ((double)(_screen.bottom() - Y) / _screen.height() * (_y2 - _y1)) + _y1;
}

int WorldToScreenConverter::X(double x){
    return _screen.left() + ((x - _x1) / (_x2 - _x1) * _screen.width());
}

int WorldToScreenConverter::Y(double y){
    return _screen.bottom() - ((y - _y1) / (_y2 - _y1) * _screen.height()) + 1;
}
