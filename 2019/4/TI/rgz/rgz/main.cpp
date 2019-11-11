#include <QCoreApplication>

#include <QTextCodec>
#include "code.h"
using namespace std;
//cout << QString::fromUtf8("").toLocal8Bit().data();


int main()
{
    QCoreApplication app();
#ifdef Q_OS_WIN32
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("IBM 866"));
#endif

#ifdef Q_OS_LINUX
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
#endif

    int n,m;
    cout<<"Размер алфавита- ";
    cin>>n;
    cout<<"Размер блока- ";
    cin>>m;
    Alphabet a(n);
    a.read();
    a.build_code_arr(0);
    a.print_codes();
    Alphabet b=a.build_nsized_Alphabet(m);
    b.build_code_arr(1);
    b.print_codes();
    string s("AAABBABB");
    return 0;
}
