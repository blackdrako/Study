#include <QCoreApplication>

#include <QTextCodec>
//cout << QString::fromUtf8("").toLocal8Bit().data();
#include <iostream>
#include "Gomory.h"
#include <Windows.h>
#include "BranchesAndBorders.h"

using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
#ifdef Q_OS_WIN32
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("IBM 866"));
#endif

#ifdef Q_OS_LINUX
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
#endif
    long m, n;
    cout << "Введите m и n: ";
    cin >> m >> n;
    Gomory G(m, n);
    G.Input();
    G.GomorySolution();
    /*BranchesAndBorders B(m, n);
    B.branchesAndBordersSolution();*/

    return app.exec();
}
