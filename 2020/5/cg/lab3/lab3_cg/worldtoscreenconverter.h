#ifndef WORLDTOSCREENCONVERTER_H
#define WORLDTOSCREENCONVERTER_H

#include <QMainWindow>


class WorldToScreenConverter{
    QRect _screen;                  // Экранная система координат
    double _x1, _x2, _y1, _y2;      // Мировая система координат
public:
    WorldToScreenConverter(){};
    WorldToScreenConverter(const QRect& screen, double x1, double x2, double y1, double y2);
    QRectF getScreen() { return _screen; }

    //Преобразует координаты точки из мировой в экранную
    QPoint toScr(double x, double y);
    QPoint toScr(const QPointF& w);
    //Преобразует координаты точки из экранной в мировую
    QPointF toWrd(int X, int Y);
    QPointF toWrd(const QPoint& s);

    //Преобразует значение абсциссы Х из экранной системы координат в мировую
    double x(int X);
    //Преобразует значение ординаты Y из экранной системы координат в мировую
    double y(int Y);
    //Преобразует значение Х из мировой системы координат в мировую
    int X(double x);
    //Преобразует значение Y из мировой системы координат в мировую
    int Y(double y);
};

#endif // WORLDTOSCREENCONVERTER_H
