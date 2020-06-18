#include <stdio.h>
#include <stdlib.h>
#include "t_info.h"

//Совместная энтропия


int main(){
    double **in_matr,**out_matr,**cmm_matr,**probs;
    int mode,n,m;
    printf("1 - p(b/a), 2 - p(a/b), 3 - p(a,b) ");
    scanf("%d",&mode);
    mode--;
    /*printf("Введите размерность матрицы ");
    scanf("%d %d",&n,&m);*/
    if(mode == 0){
        FILE* f = fopen("11.txt", "r");
        fscanf(f, "%d", &n);
        fscanf(f, "%d", &m);
        fclose(f);
    }else if(mode == 1){
        FILE* f = fopen("12.txt", "r");
        fscanf(f, "%d", &n);
        fscanf(f, "%d", &m);
        fclose(f);
    }else{
        FILE* f = fopen("13.txt", "r");
        fscanf(f, "%d", &n);
        fscanf(f, "%d", &m);
        fclose(f);
    }
    /*getchar();*/
    switch (mode) {
        case 0:
            in_matr=scan_chmatr(n,m,mode);
            probs=scan_probs(n,m,mode);
            cmm_matr=source_to_common(in_matr,probs,n,m);
            out_matr=common_to_reciver(cmm_matr,probs,n,m);
        break;
        case 1:
            out_matr=scan_chmatr(n,m,mode);
            probs=scan_probs(n,m,mode);
            cmm_matr=reciver_to_common(out_matr,probs,n,m);
            in_matr=common_to_source(cmm_matr,probs,n,m);
        break;
        case 2:
            cmm_matr=scan_chmatr(n,m,mode);
            probs=scan_probs(n,m,mode);
            in_matr=common_to_source(cmm_matr,probs,n,m);
            out_matr=common_to_reciver(cmm_matr,probs,n,m);
        break;
    }
    print_chmatr(in_matr,probs,n,m,0);
    print_chmatr(out_matr,probs,n,m,1);
    print_chmatr(cmm_matr,probs,n,m,2);
    print_entr(cmm_matr,in_matr,out_matr,probs,n,m);
    getchar();
}
