#include <QCoreApplication>
#include <string>
#include <iostream>
using namespace std;

struct dialog
{
    string name_dialog;//or Name file
    dialog() {}
};

struct user
{
    user() {}
};

struct name
{
    name() {}
};

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    return app.exec();
}
