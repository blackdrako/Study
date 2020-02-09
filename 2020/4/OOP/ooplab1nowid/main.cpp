#include <QCoreApplication>
#include <QTextCodec>
#include <QTextStream>
#include <task.h>
int main(int argc, char *argv[])
{
#ifdef Q_OS_WIN32
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("IBM 866"));
#endif

#ifdef Q_OS_LINUX
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
#endif
    QCoreApplication app(argc, argv);
    task Q1(1);
    task Q2(2);
    return app.exec();
}
