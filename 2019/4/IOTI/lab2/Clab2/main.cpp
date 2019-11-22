#include <QCoreApplication>

#include <QTextCodec>
//cout << QString::fromUtf8("").toLocal8Bit().data();
#include <iostream>
#include "Simplex_shtraf.h"
#include "SimplexArtificial.h"
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
#ifdef Q_OS_WIN32
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("IBM 866"));
#endif

#ifdef Q_OS_LINUX
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
#endif
    long m, n;
    cout << "Введите кол-во строк и переменных: ";
    cin >> m >> n;
    Simplex_table C(m, n);
    cout << "Введите коэффициенты системы ограничений:" << endl;
    C.Input_SLU(cin);
    cout << "Введите коэффициенты целевой функции:" << endl;
    C.Input_Z(cin);
    C.Simplex();
    return a.exec();
}
