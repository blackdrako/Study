#include "worldtoscreenconverter.h"

WorldToScreenConverter::WorldToScreenConverter(QPoint minScr, QPoint maxScr, double xMinWrld, double yMinWrld, double xMaxWrld, double yMaxWrld):
    Screen(QRect(minScr, maxScr)),
    xW_min(xMinWrld),
    yW_min(yMinWrld),
    xW_max(xMaxWrld),
    yW_max(yMaxWrld)
{
    xxx = Screen.width()/(xW_max-xW_min);
    yyy = Screen.height()/(yW_max-yW_min);
    xw = (xW_max-xW_min)/Screen.width();
    yh = (yW_max-yW_min)/Screen.height();
}

QPoint WorldToScreenConverter::convert(double xWorld, double yWorld){
  int x_local = Screen.left() + (int)((xWorld-xW_min)*xxx);
  int y_local = 1 + Screen.bottom() - (int)((yWorld-yW_min)*yyy);
  return QPoint(x_local, y_local);
}

int WorldToScreenConverter::Xscr(double xWorld){
  return Screen.left() + (int)((xWorld-xW_min)*xxx);
}

int WorldToScreenConverter::Yscr(double yWorld){
  return 1 + Screen.bottom() - (int)((yWorld-yW_min)*yyy);
}

double WorldToScreenConverter::Xwrld(int xScreen){
  return ((xScreen-Screen.x())*xw);
}

double WorldToScreenConverter::Ywrld(int yScreen){
  return ((Screen.y()+Screen.height()-yScreen)*yh);
}

int WorldToScreenConverter::get_w(){
  return Screen.width();
}

int WorldToScreenConverter::get_h(){
  return Screen.height();
}

QPoint WorldToScreenConverter::get_TL(){
  return Screen.topLeft();
}

QPoint WorldToScreenConverter::get_TR(){
  return Screen.topRight();
}

QPoint WorldToScreenConverter::get_BL(){
  return Screen.bottomLeft();
}

QPoint WorldToScreenConverter::get_BR(){
  return Screen.bottomRight();
}

double WorldToScreenConverter::get_Xmin(){
  return xW_min;
}

double WorldToScreenConverter::get_Xmax(){
  return xW_max;
}

double WorldToScreenConverter::get_Ymin(){
  return yW_min;
}

double WorldToScreenConverter::get_Ymax(){
  return yW_max;
}

int WorldToScreenConverter::get_left(){
  return Screen.left();
}

int WorldToScreenConverter::get_bottom(){
  return Screen.bottom();
}
