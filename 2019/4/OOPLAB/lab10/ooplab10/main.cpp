#include "window.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Window w;
    w.show();

    return app.exec();
}
