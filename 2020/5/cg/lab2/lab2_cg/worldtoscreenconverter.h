#ifndef WORLDTOSCREENCONVERTER_H
#define WORLDTOSCREENCONVERTER_H

#include <QRect>
#include <QPoint>

class WorldToScreenConverter
{
public:
    WorldToScreenConverter(QPoint minScr, QPoint maxScr, double xMinWrld, double yMinWrld, double xMaxWrld, double yMaxWrld);

    QRect Screen;
    double xW_min, xW_max, yW_min, yW_max;
    double xxx, yyy, xw, yh;
    QPoint convert(double xWorld, double yWorld);
    int Xscr(double xWorld);
    int Yscr(double yWorld);
    double Xwrld(int xScreen);
    double Ywrld(int yScreen);
    int get_w();
    int get_h();
    QPoint get_TL();
    QPoint get_TR();
    QPoint get_BL();
    QPoint get_BR();
    double get_Xmin();
    double get_Xmax();
    double get_Ymin();
    double get_Ymax();
    int get_left();
    int get_bottom();
};


#endif // WORLDTOSCREENCONVERTER_H
