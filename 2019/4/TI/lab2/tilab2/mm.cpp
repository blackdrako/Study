#include "mm.h"
//cout << QString::fromUtf8("").toLocal8Bit().data();
double scan_frac(){
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

double count_of_info(double A){
    return(-log2(A));
}
double entropy_Shenon(double *A,unsigned count){
    double sum=0;
    for(unsigned i=0;i<count;i++){
        sum+=count_of_info(A[i])*A[i];
    }
    return sum;
}
double entropy_Hartley(double *A,unsigned count){
    return log2(count);
}
double r_ratio(double *A,unsigned count){
    return 1-(entropy_Shenon(A,count)/entropy_Hartley(A,count));
}

double **common_to_source(double **matr,double** probs,unsigned n,unsigned m){
    double t_sum;
    double **result_matr=(double**)malloc(n);
    for(unsigned i=0;i<n;i++)
        result_matr[i]=(double*)malloc(m);
    for(unsigned i=0;i<m;i++){
        t_sum=0;
        for(unsigned j=0;j<n;j++){
            t_sum+=matr[i][j];
        }
        probs[0][i]=t_sum;
    }
    for(unsigned i=0;i<n;i++){
        for(unsigned j=0;j<m;j++){
            result_matr[i][j]=matr[i][j]/probs[0][i];
        }
    }
    return result_matr;
}

double **common_to_reciver(double **matr,double** probs,unsigned n,unsigned m){
    double t_sum;
    double **result_matr=(double**)malloc(n);
    for(unsigned i=0;i<n;i++)
        result_matr[i]=(double*)malloc(m);
    for(unsigned i=0;i<n;i++){
        t_sum=0;
        for(unsigned j=0;j<m;j++){
            t_sum+=matr[j][i];
        }
        probs[1][i]=t_sum;
    }
    for(unsigned i=0;i<n;i++){
        for(unsigned j=0;j<m;j++){
            result_matr[i][j]=matr[i][j]/probs[1][j];
        }
    }
    return result_matr;
}

double **source_to_common(double **matr,double** probs,unsigned n,unsigned m){
    double **result_matr=(double**)malloc(n);
    for(unsigned i=0;i<n;i++)
        result_matr[i]=(double*)malloc(m);
    for(unsigned i=0;i<n;i++){
        for(unsigned j=0;j<m;j++){
            result_matr[i][j]=matr[i][j]*probs[0][i];
        }
    }
    return result_matr;
}

double **reciver_to_common(double **matr,double** probs,unsigned n,unsigned m){
    double **result_matr=(double**)malloc(n);
    for(unsigned i=0;i<n;i++)
        result_matr[i]=(double*)malloc(m);
    for(unsigned i=0;i<n;i++){
        for(unsigned j=0;j<m;j++){
            result_matr[i][j]=matr[i][j]*probs[1][j];
        }
    }
    return result_matr;
}

double **scan_probs(unsigned n,unsigned m,int mode){
    fflush(stdin);
    double **probs=(double**)malloc(2);
    for(int i=0;i<2;i++)
        probs[i]=(double*)malloc(n+m);
    switch (mode) {
        case 0:
            cout << QString::fromUtf8("Введите p(a_i)\n").toLocal8Bit().data();
            for(unsigned i=0;i<n;i++) probs[0][i]=scan_frac();
        break;
        case 1:
            cout << QString::fromUtf8("Введите p(b_j)\n").toLocal8Bit().data();
            for(unsigned i=0;i<m;i++) probs[1][i]=scan_frac();
        break;
        case 2:
        break;
    }
    return probs;
}

double **scan_chmatr(unsigned n,unsigned m,int mode){
    fflush(stdin);
    double **result_matr=(double**)malloc(n);
    for(unsigned i=0;i<n;i++)
        result_matr[i]=(double*)malloc(m);
    switch (mode){
        case 0:
            cout << QString::fromUtf8("Введите канальную матрицу источника\n").toLocal8Bit().data();
            for(unsigned i=0;i<n;i++)
                for(unsigned j=0;j<m;j++)
                    result_matr[i][j]=scan_frac();
        break;
        case 1:
            cout << QString::fromUtf8("Введите канальную матрицу приемника\n").toLocal8Bit().data();
            for(unsigned i=0;i<n;i++)
                for(unsigned j=0;j<m;j++)
                    result_matr[i][j]=scan_frac();
        break;
        case 2:
            cout << QString::fromUtf8("Введите общую канальную матрицу\n").toLocal8Bit().data();
            for(int i=0;i<n;i++)
                for(int j=0;j<m;j++)
                    result_matr[i][j]=scan_frac();
        break;
    }
    return result_matr;
}

int print_chmatr(double **matr,double **probs,unsigned n,unsigned m,int mode){
    switch (mode){
        case 0:
            cout << QString::fromUtf8("\nКанальная матрица источника").toLocal8Bit().data();
            for(unsigned i=0;i<n;i++){
                printf("\n");
                for(unsigned j=0;j<m;j++){
                    printf("%f ",matr[i][j]);
                }
            }
            printf("\np(a_i) - ");
            for(unsigned i=0;i<n;i++)
                printf("%f ",probs[0][i]);
            printf("\n");
        break;
        case 1:
            cout << QString::fromUtf8("Канальная матрица приемника").toLocal8Bit().data();
            for(unsigned i=0;i<n;i++){
                printf("\n");
                for(unsigned j=0;j<m;j++){
                    printf("%f ",matr[i][j]);
                }
            }
            printf("\np(b_j) - ");
            for(unsigned i=0;i<m;i++)
                printf("%f ",probs[1][i]);
            printf("\n");
        break;
        case 2:
        cout << QString::fromUtf8("Общая канальная матрица").toLocal8Bit().data();
        for(unsigned i=0;i<n;i++){
            printf("\n");
            for(unsigned j=0;j<m;j++){
                printf("%f ",matr[i][j]);
            }
        }
        printf("\np(a_i) - ");
        for(unsigned i=0;i<n;i++)
            printf("%f ",probs[0][i]);
        printf("\np(b_j) - ");
        for(unsigned i=0;i<m;i++)
            printf("%f ",probs[1][i]);
        printf("\n");
        break;
    }
    return 0;
}

double matr_ent(double** a,unsigned n,unsigned m){
    double entropy=0;
    double prob=0,log_sum=0;
    for(unsigned i=0;i<n;i++){
        for(unsigned j=0;j<m;j++){
            if(a[i][j]-0<EPS){
                entropy+=a[i][j]*log2(a[i][j]);
            }
    }
    return -entropy;
    }
}
