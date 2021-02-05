#include "axis.h"
#include "worldtoscreenconverter.h"
#include <math.h>

void Axis::step(double *k, int h, int *m, int *n){
  double h_m = h/(*k);
  double n1 = log10(h_m);
  double n2 = log10(h_m/2);
  double n5 = log10(h_m/5);

  double min = pow(10, ceil(n1)) - h_m;
  *k = min + h_m;
  *m = 1;
  *n = ceil(n1);
  double current = pow(10, floor(n1));
  if (h_m - current < min){//floor - округление вниз
      min = h_m - current;
      *k = current;
      *n = floor(n1);
  }
  current = 2 * pow(10, ceil(n2));
  if (current - h_m < min){
      min = current - h_m;
      *k = current;
      *m = 2;
      *n = ceil(n2);
  }
  current = 2 * pow(10, floor(n2));
  if (h_m - current < min){
      min = h_m - current;
      *k = current;
      *m = 2;
      *n = floor(n2);
  }
  current = 5 * pow(10, ceil(n5));
  if (current - h_m < min){
      min = current - h_m;
      *k = current;
      *m = 5;
      *n = ceil(n5);
  }
  current = 5 * pow(10, floor(n5));
  if (h_m - current < min){
      min = h_m - current;
      *k = current;
      *m = 5;
      *n = floor(n5);
  }
}

void Axis::draw(QPainter *painter, int h, WorldToScreenConverter conv){
    QPen pen(Qt::black,3,Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    painter->setPen(pen);

    if (conv.get_Xmin() <= 0 && 0 <= conv.get_Xmax())
        painter->drawLine(conv.convert(0,conv.get_Ymin()), conv.convert(0, conv.get_Ymax()));
    else if (conv.get_Xmin() < conv.get_Xmax()){
        if (conv.get_Xmax() < 0)
            painter->drawLine(conv.get_BR(), conv.get_TR());
        else
            painter->drawLine(conv.get_BL(), conv.get_TL());
    }

    if (conv.get_Ymin() <= 0 && 0 <= conv.get_Ymax()) //ось Оx
        painter->drawLine(conv.convert(conv.get_Xmin(), 0), conv.convert(conv.get_Xmax(), 0));
    else if (conv.get_Ymin() < conv.get_Ymax()){
        if (conv.get_Ymax() < 0)
            painter->drawLine(conv.get_TL(), conv.get_TR());
        else
            painter->drawLine(conv.get_BL(), conv.get_BR());
    }

    painter->setPen(QPen(Qt::blue,1,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin));
}

void OrdAxis::draw(QPainter *painter, int h, WorldToScreenConverter conv){
    int m, n;
    double k = conv.get_h()/(conv.get_Ymax() - conv.get_Ymin());
    step(&k, h, &m, &n);

    double k1 = ceil(conv.get_Ymin()/k)*k;
    for (; k1 <= conv.get_Ymax(); k1 += k){
        painter->setPen(Qt::gray);
        painter->drawLine(conv.convert(conv.get_Xmin(), k1), conv.convert(conv.get_Xmax(), k1));
        painter->setPen(Qt::black);

        if (fabs(k1) - 1.e-14 < 0){
            painter->drawText(QPoint(conv.get_left()-10, conv.Yscr(k1)+5), "0");
        }
        else{
            QString str;
            if(fabs(k1) < 10)
                str = QString::number(k1, 'f', 2);
            else
                str = QString::number(k1, 'e', 2);
            painter->drawText(QPoint(conv.get_left()-60, conv.Yscr(k1)+5), str);
        }
    }
    painter->setPen(QPen(Qt::blue,1,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin));
}

void AbscAxis::draw(QPainter *painter, int h, WorldToScreenConverter conv){
    int m, n;
    double k = conv.get_w()/(conv.get_Xmax() - conv.get_Xmin());
    step(&k, h, &m, &n);

    double k1 = ceil(conv.get_Xmin()/k)*k;
    for (; k1 <= conv.get_Xmax(); k1 += k){
        painter->setPen(Qt::gray);
        painter->drawLine(conv.convert(k1, conv.get_Ymin()), conv.convert(k1, conv.get_Ymax()));
        painter->setPen(Qt::black);

        QString str;
        if(fabs(k1) < 10 && fabs(k1) > 0.1)
            str = QString::number(k1, 'f', 2);
        else
            str = QString::number(k1, 'e', 2);
        QPoint p(conv.Xscr(k1)-20, conv.get_bottom()+18);
        painter->translate(p);
        painter->rotate(30);
        painter->drawText(0, 0, str);
        painter->rotate(-30);
        painter->translate(-p);
    }
}

