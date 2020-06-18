#ifndef _T_INFO
#define _T_INFO
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#define EPS 0.0001
//считывание дроби и перевод ее в double
double scan_frac();

//кол-во информации по Шеннону
double count_of_info(double A);
//энтропия по Шеннону
double entropy_Shenon(double *A,unsigned count);
//энтропия и кол-во по Хартли для равновероятных событий
double entropy_Hartley(double *A,unsigned count);
//коэффицент связности
double r_ratio(double *A,unsigned count);

//Подпрограммы возвращают преобразованную канальную матрицу.
//В probs[0][i] записываются p(a_i),а в probs[1][j] p(b_j).
//перевод из КМО в КМП
double **common_to_reciver(double **matr,double **probs,unsigned n,unsigned m);
//перевод из КМО в КМИ
double **common_to_source(double **matr,double **probs,unsigned n,unsigned m);
//перевод из КМП в КМО
double **reciver_to_common(double **matr,double **probs,unsigned n,unsigned m);
//перевод из КМИ в КМО
double **source_to_common(double **matr,double **probs,unsigned n,unsigned m);
//чтение доп. вероятностей. 0 - чтение строки p(a_i), 1 - p(b_j), 2 - обе строки.
double **scan_probs(unsigned n,unsigned m,int mode);
//чтение канальной матрицы 0 - КМИ, 1 - КМП, 2 - КМО.
double **scan_chmatr(unsigned n,unsigned m,int mode);
//вывод канальной матрицы с вспомогательной строкой 0 - КМИ, 1 - КМП, 2 - КМО.
int print_chmatr(double **matr,double **probs,unsigned n,unsigned m,int mode);

//Совместная энтропия
double cond_ent(double** a,double** b,unsigned n,unsigned m);
//Условная энтропия
double comm_ent(double** a,unsigned n,unsigned m);
//Энтропия матрицы
double prob_ent(double** probs,unsigned n,unsigned m,char mode);

double matr_ent(double** matr,int n,int m);
void print_entr(double** comm,double** origin,double** dest,double** probs,unsigned n,unsigned m);
#endif
