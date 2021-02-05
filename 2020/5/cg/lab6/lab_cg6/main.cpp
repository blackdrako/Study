#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ViewWidget w(nullptr);
    w.show();
    return a.exec();
}
