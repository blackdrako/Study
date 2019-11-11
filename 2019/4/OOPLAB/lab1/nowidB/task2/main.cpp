#include <QCoreApplication>

#include <QTextCodec>

#include <iostream>
using namespace std;
/* б. Дан файл целых чисел. Нулевых компонент в файле нет. Число отрицательных компонент равно числу положительных.
 * Преобразовать файл таким образом, чтобы сначала были положительные числа, а затем отрицательные.
 * Порядок следования как положительных, так и отрицательных чисел сохранить.*/
#include <fstream>

void creat_file(){
    ofstream file;
    file.open("test.txt");
    int number;
    while(1){
        cin >> number;
        if(number!=0){
            file << number << " ";
        } else {
            break;
        }
    }
    file.close();
}

void transfer_file(){
    ofstream out,out1,out2;
    out1.open("data1.txt");
    out2.open("data2.txt");
    out.open("data.txt");
    ifstream file("test.txt");
    int number;
    while(1){
        file >> number;
        if(file.eof() == 1){
            break;
        }
        if(number > 0){
            out1 << number << " ";
        } else {
            out2 << number << " ";
        }
    }
    file.close();
    out1.close();
    out2.close();
    ifstream in1("data1.txt");
    ifstream in2("data2.txt");
    while(1){
        in1 >> number;
        if(in1.eof() == 1){
            break;
        }
        out << number << " ";
    }
    while(1){
        in2 >> number;
        if(in2.eof() == 1){
            break;
        }
        out << number << " ";
    }
    out.close();
    out1.close();
    out2.close();
}

int main(int argc, char *argv[])
{
    QCoreApplication applications(argc, argv);
#ifdef Q_OS_WIN32
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("IBM 866"));
#endif

#ifdef Q_OS_LINUX
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
#endif

    creat_file();
    transfer_file();
    return applications.exec();
}
