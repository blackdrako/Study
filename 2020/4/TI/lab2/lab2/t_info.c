#include "../../Desktop/lab2/t_info.h"

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
        fflush(stdin);
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
        fflush(stdin);
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
        fflush(stdin);
        return a;
    }
    fflush(stdin);
    return -1;
}

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
double r_ratio(double *A,unsigned count){
    return 1-(entropy_Shenon(A,count)/entropy_Hartley(A,count));
}

double **common_to_source(double **matr,double** probs,unsigned n,unsigned m){
    double t_sum;
    double **result_matr=malloc(sizeof(double*)*n);
    for(int i=0;i<n;i++) result_matr[i]=malloc(sizeof(double)*m);
    for(int i=0;i<m;i++){
        t_sum=0;
        for(int j=0;j<n;j++){
            t_sum+=matr[i][j];
        }
        probs[0][i]=t_sum;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            result_matr[i][j]=matr[i][j]/probs[0][i];
        }
    }
    return result_matr;
}

double **common_to_reciver(double **matr,double** probs,unsigned n,unsigned m){
    double t_sum;
    double **result_matr=malloc(sizeof(double*)*n);
    for(int i=0;i<n;i++) result_matr[i]=malloc(sizeof(double)*m);
    for(int i=0;i<n;i++){
        t_sum=0;
        for(int j=0;j<m;j++){
            t_sum+=matr[j][i];
        }
        probs[1][i]=t_sum;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            result_matr[i][j]=matr[i][j]/probs[1][j];
        }
    }
    return result_matr;
}

double **source_to_common(double **matr,double** probs,unsigned n,unsigned m){
    double **result_matr=malloc(sizeof(double*)*n);
    for(int i=0;i<n;i++) result_matr[i]=malloc(sizeof(double)*m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            result_matr[i][j]=matr[i][j]*probs[0][i];
        }
    }
    return result_matr;
}

double **reciver_to_common(double **matr,double** probs,unsigned n,unsigned m){
    double **result_matr=malloc(sizeof(double*)*n);
    for(int i=0;i<n;i++) result_matr[i]=malloc(sizeof(double)*m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            result_matr[i][j]=matr[i][j]*probs[1][j];
        }
    }
    return result_matr;
}

double **scan_probs(unsigned n,unsigned m,int mode){
    fflush(stdin);
    double **probs=malloc(sizeof(double*)*(2));
    for(int i=0;i<2;i++) probs[i]=malloc(sizeof(double)*(n+m));
    if(mode == 0){
       FILE* h = fopen("31.txt", "r");
            for(int i = 0; i < n; i++)
                fscanf(h, "%lf", &probs[0][i]);
            fclose(h);
    }else if(mode == 1){
       FILE* h = fopen("32.txt", "r");
            for(int i = 0; i < n; i++)
                fscanf(h, "%lf", &probs[1][i]);
            fclose(h);
    }
    /*switch (mode) {
        case 0:
            printf("Введите все p(ai)\n");
            for(int i=0;i<n;i++) probs[0][i]=scan_frac();
        break;
        case 1:
            printf("Введите все p(bj)\n");
            for(int i=0;i<m;i++) probs[1][i]=scan_frac();
        break;
        case 2:
        break;
    }*/
    return probs;
}

double **scan_chmatr(unsigned n,unsigned m,int mode){
    fflush(stdin);
    double **result_matr=malloc(sizeof(double*)*n);
    for(int i=0;i<n;i++) result_matr[i]=malloc(sizeof(double)*m);
    if(mode == 0){
       FILE* g = fopen("21.txt", "r");
            for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++){
                    fscanf(g, "%lf", &result_matr[i][j]);
                }
            fclose(g);
    }else if(mode == 1){
       FILE* g = fopen("22.txt", "r");
            for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++){
                    fscanf(g, "%lf", &result_matr[i][j]);
                }
            fclose(g);
    }else{
       FILE* g = fopen("23.txt", "r");
            for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++){
                    fscanf(g, "%lf", &result_matr[i][j]);
                }
            fclose(g);
    }
    /*switch (mode){
        case 0:
            printf("Введите канальную матрицу источника\n");
            for(int i=0;i<n;i++) for(int j=0;j<m;j++) result_matr[i][j]=scan_frac();
        break;
        case 1:
            printf("Введите канальную матрицу приемника\n");
            for(int i=0;i<n;i++) for(int j=0;j<m;j++) result_matr[i][j]=scan_frac();
        break;
        case 2:
            printf("Введите общую канальную матрицу\n");
            for(int i=0;i<n;i++) for(int j=0;j<m;j++) result_matr[i][j]=scan_frac();
        break;
    }*/
    return result_matr;
}

int print_chmatr(double **matr,double **probs,unsigned n,unsigned m,int mode){
    switch (mode){
        case 0:
            printf("\nКанальная матрица источника\n");
            for(int i=0;i<n;i++){
                printf("\n");
                for(int j=0;j<m;j++){
                    printf("%f ",matr[i][j]);
                }
            }
            printf("\np(a_i) - ");
            for(int i=0;i<n;i++) printf("%f ",probs[0][i]);
            printf("\n");
        break;
        case 1:
            printf("\nКанальная матрица приемника\n");
            for(int i=0;i<n;i++){
                printf("\n");
                for(int j=0;j<m;j++){
                    printf("%f ",matr[i][j]);
                }
            }
            printf("\np(b_j) - ");
            for(int i=0;i<m;i++) printf("%f ",probs[1][i]);
            printf("\n");
        break;
        case 2:
        printf("\nОбщая канальная матрица\n");
        for(int i=0;i<n;i++){
            printf("\n");
            for(int j=0;j<m;j++){
                printf("%f ",matr[i][j]);
            }
        }
        printf("\np(a_i) - ");
        for(int i=0;i<n;i++) printf("%f ",probs[0][i]);
        printf("\np(b_j) - ");
        for(int i=0;i<m;i++) printf("%f ",probs[1][i]);
        printf("\n");
        break;
    }
    return 0;
};

double prob_ent(double** probs,unsigned n,unsigned m,char mode){
    double entropy=0;
    int border=0;
    switch (mode){
        case 0:
            border= n;
        break;
        case 1:
            border = m;
        break;
    }
    for(int i=0;i<border;i++){
            if(probs[mode][i]!=0.0)
            entropy+=probs[mode][i]*log2(probs[mode][i]);
    };
    return -entropy;
};

double matr_ent(double** matr,int n,int m){
    double entropy=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matr[i][j]!=0.0)
                entropy+=matr[i][j]*log2(matr[i][j]);
            else entropy+=0;
        }
    }
    return -entropy;
};

double cond_ent(double** a,double** b,unsigned n,unsigned m){
    double entropy=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]!=0.0||b[i][j]!=0.0)
                entropy+=a[i][j]*log2(b[i][j]);
            else entropy+=0;
        }
    }
    return -entropy;
};

void print_entr(double** comm,double** origin,double** dest,double** probs,unsigned n,unsigned m){
    printf("\n");
    //ИСПРАВИТЬ
    printf("H(A) - %lf\n",prob_ent(probs,n,m,0));
    printf("H(B) - %lf\n",prob_ent(probs,n,m,1));
    printf("H(A/B) - %lf\n",cond_ent(comm,dest,n,m));
    printf("H(B/A) - %lf\n",cond_ent(comm,origin,n,m));
    printf("H(A,B) - %lf\n",matr_ent(comm,n,m));
    printf("I(A,B) - %lf\n",prob_ent(probs,n,m,0)+prob_ent(probs,n,m,1)-matr_ent(comm,n,m));
};
