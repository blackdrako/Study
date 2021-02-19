#include <QCoreApplication>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

void task(){
    int i = 10;
    int j = 4;
    int k = 3;
    double p_0 = i/2*(i+j+k);
    double p_1 = (j+k)/2*(i+j+k);
    double p_2 = (i+k)/2*(i+j+k);
    double p_3 = j/2*(i+j+k);
    for (unsigned int index = 0; index < 10; index++) {
        int E = rand() % 4;
        std::cout << E << "\n";
    }
}

#include <QTextCodec>
//cout << QString::fromUtf8("").toLocal8Bit().data();
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
#ifdef Q_OS_WIN32
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("IBM 866"));
#endif

#ifdef Q_OS_LINUX
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
#endif
    task();
    return a.exec();
}
