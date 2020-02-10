#include <QCoreApplication>
#include <QTextCodec>
#include <QTextStream>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
void creat_file_task1(string path){
    ofstream fout;
    fout.open(path);//для бинарника доп
    if(!fout.is_open()){
        cout << "Ошибка открытия файла!" << endl;
    } else {
        cout << "Count number:";
        int x;
        cin >> x;
        for (int i=0;i<x;i++) {
            string str;
            cin >> str;
            fout << str << endl;
        }
    }
    fout.close();
}

void task1pod(string path){
    ifstream fin;
    fin.open(path);
    if(!fin.is_open()){
        cout << "Error file" << endl;
    }else {
        string str;
        char temp[255];
        string::iterator it;
        while (fin.getline(temp,255)) {
            str = temp;
            it = str.begin();
            cout << *(it);
        }
    }
    fin.close();
}

void task1(){
    string path1 = "taskout11.txt";
    string path2 = "taskout12.txt";
    int flag = 0;
    cin >> flag;
    if(flag!=0){
        creat_file_task1(path1);
        creat_file_task1(path2);
    }
    task1pod(path1);
    task1pod(path2);
}

void creat_file_task2(){
    ofstream foutf;
    foutf.open("taskout2f.txt");
    ofstream foutg;
    foutg.open("taskout2g.txt");
    if(!foutf.is_open()){
        cout << "Ошибка открытия файла!" << endl;
    } else {
        cout << "Count number:";
        int x;
        cin >> x;
        cout << "File f:";
        int temp;
        for (int i=0; i < x; i++) {
            cin >> temp;
            foutf << temp;
            if(i < x-1)
                foutf << endl;
        }
        cout << "File g:";
        for (int i=0; i < x; i++) {
            cin >> temp;
            foutg << temp;
            if(i < x-1)
                foutg << endl;
        }
    }
    foutf.close();
    foutg.close();
}

void task2(){
    ifstream finf;
    ifstream fing;
    ofstream fout;
    finf.open("taskout2f.txt");
    fing.open("taskout2g.txt");
    fout.open("tempname.txt");
    int tempf;
    int tempg;
    while (!finf.eof()) {
        finf >> tempf;
        fing >> tempg;
        if(tempf > tempg)
            fout << tempf;
    }
    finf.close();
    fing.close();
    fout.close();
    remove("taskout2f.txt");
    rename("tempname.txt","taskout2f.txt");
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
    //task1();
    //creat_file_task2();
    task2();
    return app.exec();
}
