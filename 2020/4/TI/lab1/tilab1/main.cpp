#include <QCoreApplication>
#include <QTextCodec>
#include <QTextStream>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <queue>
using namespace std;

long double* read_number(long unsigned int *size){
    queue<long double> tempQueue;
    long double temp;
    long unsigned int count;
    long double sym = 0;
    cout << ":";
    cin >> count;
    for (long unsigned int i = 0; i < count; i++) {
        cout << ":";
        cin >> temp;
        if(temp>0&&sym<1){
            sym = sym + temp;
            tempQueue.push(temp);
        }
    }
    *size = tempQueue.size();
    long double *A = new long double[tempQueue.size()];
    for (long int i = 0; i < *size; i++) {
        A[i] = tempQueue.front();
        tempQueue.pop();
    }
    return A;
}

long double entopy_shenon(long double pA){
    return log2(pA);
}

long double entropy_hartli(long double *A,long unsigned int size){
    long double sum = 0;
    for (long unsigned int i = 0; i < size; i++) {
        sum = sum + A[i]*entopy_shenon(A[i]);
    }
    return (-sum);
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
    long double *A;
    long unsigned int size = 0;
    A = read_number(&size);
    return app.exec();
}
