#include <QCoreApplication>

#include <QTextCodec>
#include <iostream>
#include "DualSimplex.h"
#include "ClarificationOfRatings.h"
//cout << QString::fromUtf8("").toLocal8Bit().data();
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
    cout << QString::fromUtf8("Каким методом хотите решить? 0 - двойственный СМ, 1 - метод последовательного уточнения оценок").toLocal8Bit().data() << endl;
    if (getchar() == '0') {
        cout << QString::fromUtf8("Введите m и n: ").toLocal8Bit().data();
        cin >> m >> n;
        DualSimplexTable a(m, n);
        cout << QString::fromUtf8("Введите коэффициенты системиы ограничений:").toLocal8Bit().data() << endl;
        a.Input_SLU(cin);
        cout << QString::fromUtf8("Введите коэффициенты целевой функции:").toLocal8Bit().data() << endl;
        a.Input_Z(cin);
        a.getDualTask();
        a.Simplex();
        a.printAnswer();
    }
    else {
        cout << QString::fromUtf8("Введите m и n: ").toLocal8Bit().data();
        cin >> m >> n;
        ClarSimplexTable a(m, n);
        cout << QString::fromUtf8("Введите коэффициенты системиы ограничений:").toLocal8Bit().data() << endl;
        a.Input_SLU(cin);
        cout << QString::fromUtf8("Введите коэффициенты целевой функции:").toLocal8Bit().data() << endl;
        a.Input_Z(cin);
        a.clarification();
    }
    return a.exec();
}
