#include <QCoreApplication>
#include <QTextCodec>
#include <QTextStream>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
//-log2(p(A)) - количество информации на один символ
template<typename Type>
class Info
{
private:
    Type temp_A;
    Type *A;//Вероятность для символов Алфавита
    Type **M_1;
    Type **M_2;
    Type **M_3;
    unsigned count;
public:
    Type count_of_info(Type t);
    Type entropy_Shenon();
    void Read_Info();
};

template<typename Type>
Type Info<Type>::count_of_info(Type t){
    return -(log2(t));
}

template<typename Type>
Type Info<Type>::entropy_Shenon(){
    Type sum=0;
    for(unsigned i=0;i<count;i++){
        sum+=count_of_info(A[i])*A[i];
    }
    return sum;
}

template<typename Type>
void Info<Type>::Read_Info(){
    cin >> this->count;
    A = new Type [count];
    for (unsigned i =0; i < count; i++) {
        cin >> A[i];
    }
}

int factorial(int k){

}

int CC(int n,int m){
    return (factorial(n))/(factorial(m)*factorial(n-m));
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
    Info<double> K;
    K.Read_Info();
    cout << K.entropy_Shenon()  << endl;
    return app.exec();
}
