#ifndef KOSHI_H
#define KOSHI_H
typedef double(* func)(double,double);
typedef double**(* method_func)(func,double,double,double,int*);


double** malloc_array(unsigned n);
void free_array(double **a, unsigned n);
double **method_euler(func f, double a, double b, double y0,int* step);
double **method_euler_cauchy(func f, double a, double b, double y0,int* step);
double **method_mod_euler(func f, double a, double b, double y0,int* step);
double **method_runge_kutta(func f, double a, double b, double y0,int* step);
double **runge_eps(method_func method,func fx, double a, double b, double y0,double eps,int* step,int acc_order);

#endif // KOSHI_H
