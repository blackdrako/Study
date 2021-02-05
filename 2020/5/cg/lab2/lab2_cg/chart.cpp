#include "chart.h"

#include <QtDebug>

Chart::Chart(double(func)(double x), double x1, double x2, int h1, QWidget *parent)
    : QWidget(parent), f(func), x1(x1), x2(x2), h1(h1){}

void Chart::setFunc(double func(double)){
    f = func;
}

void Chart::setDomainOfDef(double x1, double x2){
    this->x1 = x1;
    this->x2 = x2;
}

void Chart::setX1(double x){
    this->x1 = x;
    update();
}

void Chart::setX2(double x){
    this->x2 = x;
    update();
}

void Chart::setH(int h){
    this->h1 = h;
    update();
}

void Chart::paintEvent(QPaintEvent *e){
    if (x1 >= x2) return;
    QPainter painter(this);
    painter.setPen(Qt::blue);
    double h = (x2 - x1) / this->width();
    double y1 = f(x1);
    double y2 = y1;
    for (double x = x1 + h; x <= x2; x += h){
        double y = f(x);
        if (y1 > y) y1 = y;
        if (y2 < y) y2 = y;
    }
    QRect scr(50, 0, this->width() - 70, this->height() - 50);
    WorldToScreenConverter converter(scr, x1, x2, y1, y2);
    QPoint p1 = converter.toScr(x1, f(x1));
    QPoint p2;
    for (double x = x1 + h; x < x2; x += h)    {
        p2 = converter.toScr(x, f(x));
        painter.drawLine(p1, p2);
        p1 = p2;
    }

    AbscissaAxis abAxis(&painter, scr, x1, x2);
    abAxis.draw(h1);
    OrdinateAxis orAxis(&painter, scr, y1, y2);
    orAxis.draw(h1);
}
