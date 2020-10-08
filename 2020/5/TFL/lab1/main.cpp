#include <QCoreApplication>
#include <QTextCodec>
#include <QTextStream>
#include <ks.h>
int main(int argc, char *argv[])
{
#ifdef Q_OS_WIN32
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("IBM 866"));
#endif

#ifdef Q_OS_LINUX
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
#endif
    QCoreApplication app(argc, argv);
    ks k;
    k.read_ksm();
    k.write_ksm();
    return app.exec();
}
