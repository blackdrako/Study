#include "colors.h"

Colors::Colors(QObject *parent) : QObject(parent)
{

}

Colors::Colors(int color)
{
    color_const = color;
    current_color = saved_color = QColor(Colors::fromCOLORREF(GetSysColor(color_const)));
}

DWORD Colors::fromQColor(QColor color)
{
    return RGB(color.red(), color.green(), color.blue());
}

QColor Colors::fromCOLORREF(COLORREF color)
{
    return QColor(GetRValue(color), GetGValue(color), GetBValue(color));
}

void Colors::updateColor()
{
    emit colorChanged(current_color);
}

QColor Colors::getNewColor()
{
    return current_color;
}

void Colors::setNewColor(QColor color)
{
    current_color = color;
}

QColor Colors::getSavedColor()
{
    return saved_color;
}

void Colors::changeColor(QColor color)
{
    COLORREF temp_color = Colors::fromQColor(color);
    SetSysColors(1, &color_const, &temp_color);
    emit colorChanged(current_color);
}
