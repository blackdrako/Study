#ifndef CHART_H
#define CHART_H

#include "axis.h"
#include "worldtoscreenconverter.h"
#include <QPainter>
#include <QWidget>

class Chart : public QWidget{
    Q_OBJECT
private:
    double (*f)(double x);
    double x1, x2;
    int h1;
public:
    Chart(double(func)(double x), double x1, double x2, int h1, QWidget *parent = 0);
    void setFunc(double(func)(double x));
    void setDomainOfDef(double x1, double x2);
    void paintEvent(QPaintEvent *e);
public slots:
    void setX1(double x);
    void setX2(double x);
    void setH (int h);
};

#endif // CHART_H
