#include <QCoreApplication>

#include <QTextCodec>
//cout << QString::fromUtf8("").toLocal8Bit().data();
#include <iostream>
#include <vector>
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
    vector<vector<int> > matrix;

    return a.exec();
}
