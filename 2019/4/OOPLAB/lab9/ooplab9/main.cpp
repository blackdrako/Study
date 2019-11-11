#include <QCoreApplication>
#include <QString>
#include <QTextStream>
#include "rpn.h"
using namespace std;

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
    QString str;
    string result_str;
     vector<Token*> token_list;
     cout<<QString::fromUtf8("Введите строку в инфиксной нотации - ").toLocal8Bit().data();
     QTextStream s(stdin);
     str = s.readLine();
     result_str = infix_to_postfix(str.toStdString());
     cout<<result_str<<endl;
     token_list=str_to_token(result_str);
     cout<<QString::fromUtf8("Результат = ").toLocal8Bit().data()<<calc_tokens(token_list);
    return a.exec();
}
