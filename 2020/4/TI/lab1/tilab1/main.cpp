#include <QCoreApplication>
#include <QTextCodec>
#include <QTextStream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <iostream>
using namespace std;
#define ACC 0.0000001

double count_of_info(double A){
    return(-log2(A));
}

double entropy_Shenon(double *A,unsigned count){
    double sum=0;
    for(int i=0;i<count;i++){
        sum+=count_of_info(A[i])*A[i];
    }
    return sum;
}

double entropy_Hartley(double *A,unsigned count){
    return log2(count);
}
double scan_prob(){
    char c;
    int nm = 0;
    int dnm = 1;
    fflush(stdin);
    c = getchar();
    while (c != ' ' && c != '\n' && c != '.' && c != '/' && c != ','){
        if((c>='0')&&(c<='9')){
            nm *= 10;
            nm += c - '0';
        }
        c = getchar();
    }
    if (c == ' ' || c == '\n'){
        return nm;
    }
    if (c == '/' || c == '\\'){
        dnm=0;
        while(c != ' ' && c != '\n'){
            if((c>='0')&&(c<='9')){
                dnm *= 10;
                dnm += c - '0';
            }
            dnm*=10;
            c = getchar();
        }
        dnm/=10;
        double a = (double)nm / (double)dnm;
        return a;
    }
    if (c == ',' || c == '.'){
        int dnm = 1;
        while(c != ' ' && c != '\n'){
            if((c>='0')&&(c<='9')){
                nm *= 10;
                nm += c - '0';
            }
            dnm*=10;
            c = getchar();
        }
        double a = (double)nm / (double)(dnm/10);
        return a;
    }
    return -1;
}


double* scan_probs(unsigned count){
    fflush(stdin);
    cout << QString::fromUtf8("Введите кол-во значений случайной величины: ").toLocal8Bit().data();
    cin >> count;
    double *temp=(double*)malloc(count * sizeof(double));
    double t;
    int result_count=count;
    getchar();
    cout << QString::fromUtf8("Введите вероятности значений случайной величины через пробел: ").toLocal8Bit().data();
    for(int i=0;i<count;i++){
        t=scan_prob();
        if((t-0.0)>ACC){
            temp[i]=t;
        }
        else result_count--;
    }
    double sum=0;
    for(int i=0;i<count;i++) sum+=temp[i];
    if(sum>(1+ACC)){
        cout << QString::fromUtf8("Сумма вероятностей больше 1").toLocal8Bit().data();
        exit(1);
    }
    count=result_count;
    return temp;
}

double r_ratio(double *A,unsigned count){
    return 1-(entropy_Shenon(A,count)/entropy_Hartley(A,count));
}

int check_probs(double* A,unsigned count){
    double check = A[0];
    int i=0;
    while((A[i]==check)&&(i<count)){
        i++;
    }
    return !(i<count);
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
    unsigned count;
    char mode='Y',flag=1;
    while(((mode=='y')||(mode=='Y'))){
        double* probs=scan_probs(count);

        if(count == 1){
            cout << QString::fromUtf8("Количество информации по Шеннону: %lf\n",count_of_info(*probs)).toLocal8Bit().data();
        }
        else{
            if(check_probs(probs,count)){
                cout << QString::fromUtf8("Энтропия по Шеннону: %lf\n",entropy_Shenon(probs,count)).toLocal8Bit().data();
                cout << QString::fromUtf8("Энтропия по Хартли: %lf\n",entropy_Hartley(probs,count)).toLocal8Bit().data();
                cout << QString::fromUtf8("Коэффицент избыточности: %lf\n",r_ratio(probs,count)).toLocal8Bit().data();
            }
            else{
                cout << QString::fromUtf8("Энтропия по Шеннону: %lf\n",entropy_Shenon(probs,count)).toLocal8Bit().data();
                cout << QString::fromUtf8("Энтропия по Хартли: %lf\n",entropy_Hartley(probs,count)).toLocal8Bit().data();
                cout << QString::fromUtf8("Коэффицент избыточности: %lf\n",r_ratio(probs,count)).toLocal8Bit().data();
            }
        }
        free(probs);
        cout << QString::fromUtf8("Продолжить работу программы? [Y/n]:").toLocal8Bit().data();
        fflush(stdin);
        fflush(stdout);
        getchar();
        scanf("%c",&mode);
        printf("\n");
    }
    return app.exec();
}
