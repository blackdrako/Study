#include <QCoreApplication>

#include "mm.h"
int main(int argc, char *argv[])
{
    QCoreApplication applications(argc, argv);
#ifdef Q_OS_WIN32
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("IBM 866"));
#endif

#ifdef Q_OS_LINUX
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
#endif
    double **in_matr,**out_matr,**cmm_matr,**probs;
    int mode,n,m;
    cout << QString::fromUtf8("Выберите случай ввода (1 - КМИ, 2 - КМП, 3 - КМО) - ").toLocal8Bit().data();
    scanf("%d",&mode);
    mode--;
    cout << QString::fromUtf8("Введите размерность вводимой матрицы (n,m) - ").toLocal8Bit().data();
    scanf("%d %d",&n,&m);
    getchar();
    switch (mode) {
        case 0:
            in_matr=scan_chmatr(n,m,mode);
            probs=scan_probs(n,m,mode);//failed
            cmm_matr=source_to_common(in_matr,probs,n,m);
            out_matr=common_to_reciver(cmm_matr,probs,n,m);
        break;
        case 1:
            out_matr=scan_chmatr(n,m,mode);
            probs=scan_probs(n,m,mode);
            cmm_matr=reciver_to_common(out_matr,probs,n,m);//failed
            in_matr=source_to_common(cmm_matr,probs,n,m);
        break;
        case 2:
            cmm_matr=scan_chmatr(n,m,mode);
            probs=scan_probs(n,m,mode);
            in_matr=common_to_source(cmm_matr,probs,n,m);//failed
            out_matr=common_to_reciver(cmm_matr,probs,n,m);
        break;
    }
    print_chmatr(in_matr,probs,n,m,0);
    print_chmatr(out_matr,probs,n,m,1);
    print_chmatr(cmm_matr,probs,n,m,2);

    return applications.exec();
}
