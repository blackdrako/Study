#include <QCoreApplication>
#include <QTextCodec>
#include <QTextStream>
#include <iostream>
#include <string>
using namespace std;
namespace MyString {
class String
{
private:
    char *str;
    int n;
    int checkCountSimbol();
public:
    String(char *a,int n) {}
    void ShowString();
    int GetN(){
        return n;
    }
    int checkProbel();
    void PropisINStoch();
    void deletePripinania();
};
}

int main(int argc, char *argv[])
{
#ifdef Q_OS_WIN32
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("IBM 866"));
#endif

#ifdef Q_OS_LINUX
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
#endif
    QCoreApplication app(argc, argv);
    using namespace MyString;
    string a1,a2;
    a1 = "123";
    a2 = "33";
    return app.exec();
}
