#include <QCoreApplication>
#include <QTextCodec>
#include <tree.h>
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
    Tree <int, 4> t4(0);
    t4 = Tree <int, 4>(0);
        for (int i = 1; i <= 4; i++) {
            t4.add_nth(i - 1, new Tree <int, 4>(i));
        }
        t4.get_nth(1)->add_nth(2, new Tree <int, 4>(10));
        t4.print();

    return a.exec();
}
