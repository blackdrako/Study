#include <QCoreApplication>
#include <QTextCodec>
#include <iostream>
#include <fstream>
#include <bitset>
#include <string>
#include "bch_code.h"
using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
#ifdef Q_OS_WIN32
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("IBM 866"));
#endif

#ifdef Q_OS_LINUX
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
#endif
    BCH r(4);
    cout << "r = 4" << endl;
    ifstream f;
    f.open("inp.txt", ifstream::in);
    vector<int> info;
    string inp;
    f >> inp;
    cout << endl << QString::fromUtf8("Прочитаное сообщение: ").toLocal8Bit().data() << inp << endl << QString::fromUtf8("Длина сообщения: ").toLocal8Bit().data() << inp.length() << endl;
    int count = 0;

    int pos = 0, added = 0; count = 0;
    string tmpstr = "";
    if (inp.length() % 7 != 0) {
        for (int i = 0; i <inp.length() % 7; i++) {
            inp += "0";
            added++;
            tmpstr += "0";
        }
    }
    cout << " " << endl;



    string* res = new string[(inp.length() / 7) + 1];
    for (int i = 0; i < inp.length(); i++) {
        res[pos] += inp[i];
        count++;
        if (count == 7) {
            cout << res[pos] << endl;
            pos++;
            count = 0;
        }
    }
    string outp = "";
    std::cout << endl;
    for (int i = 0; i < inp.length() / 7; i++) {
        for (int j = 0; j < res[i].length(); j++) {
            info.push_back(res[i][j] - '0');
        }

        vector<int> code = r.coding(info);
        res[i] += " \t ";
        for (int k = 0; k < code.size(); k++) {
            res[i] += code[k] + '0';
            outp += code[k] + '0';
        }
        vector <int> tmpcode = code;
        r.putMistake(tmpcode);

        res[i] += " \t ";
        for (int k = 0; k < tmpcode.size(); k++) {
            res[i] += tmpcode[k] + '0';
        }
        res[i] += " \t ";
        bool flag = false;
        for (int l = 0; l < code.size(); l++) {
            if (code[l] != tmpcode[l]) {
                flag = true;
                res[i] += to_string(l);
                res[i] += "  ";
            }
        }
        if (!flag) {	res[i] += "---- ";}
        info = r.decoding(tmpcode);

        info.clear();
    }
    cout << endl << QString::fromUtf8("Информ. слово \t Кодов. слово \t\t Принят. слово \t\t Ошибка в битах:").toLocal8Bit().data()<< endl;
    for (int i = 0; i < inp.length() / 7; i++) {
        cout << res[i] << endl;
    }
    cout << endl << QString::fromUtf8("Результат кодирования: ").toLocal8Bit().data()<< endl << outp << endl;
    return app.exec();
}
