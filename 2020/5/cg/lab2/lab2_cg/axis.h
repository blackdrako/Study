#ifndef AXIS_H
#define AXIS_H

#include "worldtoscreenconverter.h"
#include <QPainter>

class Axis
{
public:
    void step(double *k, int h, int *m, int *n);
    void draw(QPainter *painter, int h, WorldToScreenConverter conv);
};

class AbscAxis : Axis
{
  public:
    void draw(QPainter *painter, int h, WorldToScreenConverter conv);
};

class OrdAxis : Axis
{
  public:
    void draw(QPainter *painter, int h, WorldToScreenConverter conv);
};


#endif // AXIS_H
