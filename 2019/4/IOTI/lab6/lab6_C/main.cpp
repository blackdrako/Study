#include <QCoreApplication>

#include <QTextCodec>
//cout << QString::fromUtf8("").toLocal8Bit().data();
#include <iostream>
#include "saddlepoint.h"
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
    int m, n;
    cout << QString::fromUtf8("Введите размеры  платежной матрицы:").toLocal8Bit().data() << endl;
    cin >> m >> n;
    SaddlePoint a(m, n);
    a.inputCosts();
    a.getSaddlePoint();
    a.solveMixedStrats();
    return app.exec();
}
