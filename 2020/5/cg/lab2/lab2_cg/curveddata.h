#ifndef CURVEDDATA_H
#define CURVEDDATA_H


#include <QColor>
#include <QPen>

class CurveData
{
  public:
    CurveData();
    QColor curveColor;
    QPen curvePen;
    virtual double F(double x);
    void setColor(QColor color);
};

class Function1 : public CurveData
{
  public:
    Function1();
    double F(double x);
};

class Function2 : public CurveData
{
  public:
    Function2();
    double F(double x);
};

class Function3 : public CurveData
{
  public:
    Function3();
    double F(double x);
};


#endif // CURVEDDATA_H
