#include <QCoreApplication>
#include <QTextCodec>
#include <QTextStream>
#include <QString>
#include <iostream>
#include <fstream>
#include <stack>
#include <string>
using namespace std;

void creat_file_pro(string name){
    ofstream fout;
    name = name + ".pro";
    fout.open(name);
    fout <<"QT -= gui\n\n" << "CONFIG += c++11 console\n" << "CONFIG -= app_bundle\n" << "DEFINES += QT_DEPRECATED_WARNINGS\n" << "SOURCES += " << "Xmmmm.cpp";
    fout.close();
}

void solve_rpn(){
    creat_file_pro("solve");
    ofstream fout;
    stack <long double> s;
    long double z1 = 0, z2 = 0, i = 0;
    char a;
    fout.open("Xmmmm.cpp");
    fout << "#include <QCoreApplication>\n" << "#include <QTextCodec>\n" << "#include <QTextStream>\n" << "#include <QString>\n" <<  "#include <iostream>\n"  << "using namespace std;\n\n" << "int main()\n" << "{\n" << "setlocale(LC_ALL, \"rus\");\n";
    cout << QString::fromUtf8("Введите обратную польскую запись:\n").toLocal8Bit().data();
    a = getchar();
    while (a != ' '){
            switch (a) {
            case '+':
                z1 = s.top();
                s.pop();
                z2 = s.top();
                s.pop();
                fout << "long double a" << i << ";\n";
                fout << 'a' << i++ << " = " << z1 << " + " << z2 << ";\n" ;
                s.push(z1+z2);
                break;
            case '-':
                z1 = s.top();
                s.pop();
                z2 = s.top();
                s.pop();
                fout << "long double a" << i << ";\n";
                fout << 'a' << i++ << " = " << z1 << " - " << z2 << ";\n" ;
                s.push(z1-z2);
                break;
            case '*':
                z1 = s.top();
                s.pop();
                z2 = s.top();
                s.pop();
                fout << "long double a" << i << ";\n";
                fout << 'a' << i++ << " = " << z1 << " * " << z2 << ";\n" ;
                s.push(z1*z2);
                break;
            case '/':
                z1 = s.top();
                s.pop();
                z2 = s.top();
                s.pop();
                fout << "long double a" << i << ";\n";
                fout << 'a' << i++ << " = " << z1 << " / " << z2 << ";\n" ;
                s.push(z1/z2);
                break;
            default:
            s.push(a - '0');
            break;
    }
    a = getchar();
    }
    cout << QString::fromUtf8("Ответ: ").toLocal8Bit().data() << s.top();
    getchar();
    fout << "cout <<QString::fromUtf8( \"Ответ: \").toLocal8Bit().data() << " << 'a' << --i << ";\n";
    fout << "getchar();\n" << "}";
    fout.close();
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
    solve_rpn();
    return app.exec();
}