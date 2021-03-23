#include <QCoreApplication>
#include <QTextCodec>
#include <iostream>
using namespace std;
enum namepoint {A,B,C};

void write_vector(vector<double> M){
    unsigned int i = 0;
    cout << "A->B:" << M[i] << endl;
    i++;
    cout << "A->C:" << M[i] << endl;
    i++;
    cout << "B->A:" << M[i] << endl;
    i++;
    cout << "B->C:" << M[i] << endl;
    i++;
    cout << "C->A:" << M[i] << endl;
    i++;
    cout << "C->B:" << M[i] << endl;
    i++;
    cout << "C->C:" << M[i] << endl;
}

void task(){
    const double i = static_cast<double>(10.f);
    const double j = static_cast<double>(4.f);
    const double k = static_cast<double>(3.f);
    int point = namepoint::A;
    vector<double> M(7);
    M[0] = (j/(j+k));//A->B
    M[1] = (k/(j+k));//A->C
    M[2] = (i/(i+j));//B->A
    M[3] = (j/(i+j));//B->C
    M[4] = (i/(i+j+k));//C->A
    M[5] = (j/(i+j+k));//C->B
    M[6] = (k/(i+j+k));//C->C
    write_vector(M);
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
#ifdef Q_OS_WIN32
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("IBM 866"));
#endif

#ifdef Q_OS_LINUX
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
#endif
    task();
    return a.exec();
}
