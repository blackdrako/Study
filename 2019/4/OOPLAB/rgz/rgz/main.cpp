#include "widget.h"
#include <QApplication>
#include "HousePhone.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    HouseConfig cfg;
    House house = cfg.get_result();
    return a.exec();
}
