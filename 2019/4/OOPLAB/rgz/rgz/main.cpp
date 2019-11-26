#include <QCoreApplication>

#include <QTextCodec>
#include "DataBase.h"
#include "Ui.h"

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
    DataBase& db = DataBase::instance();
    db.load();
    Ui ui;
    ui.loginDialog();
    db.write();

    return a.exec();
}
