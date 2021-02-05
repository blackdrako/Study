#include "curveddata.h"

CurveData :: CurveData(){
    QPen curvePen(Qt::blue, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
}

double CurveData :: F(double x) { return 1; }

void CurveData :: setColor(QColor color){
    curveColor = color;
    curvePen = QPen(color, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
}

Function1 :: Function1(){}

double Function1 :: F(double x) { return x*x/3 + 5;}

Function2 :: Function2(){}

double Function2 :: F(double x) { return -50*x; }

Function3 :: Function3(){}

double Function3 :: F(double x) { return x*x*x/2 + 10  ;}
