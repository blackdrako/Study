#include <QCoreApplication>
#include <QTextCodec>
#include <QTextStream>
#include <QString>
#include <iostream>
using namespace std;

int main()
{
setlocale(LC_ALL, "rus");
long double a0;
a0 = 3 + 2;
cout <<QString::fromUtf8( "Ответ: ").toLocal8Bit().data() << a0;
getchar();
}