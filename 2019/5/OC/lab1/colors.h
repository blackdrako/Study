#ifndef COLORS_H
#define COLORS_H


#include <QObject>
#include <QColor>
#include <windows.h>
/*
 * COLOR_3DDKSHADOW, COLOR_BTNTEXT, COLOR_ACTIVECAPTION
 */

class Colors : public QObject
{
    Q_OBJECT
public:
    explicit Colors(QObject *parent = nullptr);
    Colors(int color);
    static DWORD fromQColor(QColor color);
    static QColor fromCOLORREF(COLORREF color);
    void updateColor();
    QColor getNewColor();
    void setNewColor(QColor color);
    QColor getSavedColor();
private:
    QColor saved_color;
    QColor current_color;
    int color_const;
signals:
    void colorChanged(QColor color);
public slots:
    void changeColor(QColor color);
};


#endif // COLORS_H
