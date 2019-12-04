#include <QCoreApplication>

#include <QTextCodec>
//cout << QString::fromUtf8("").toLocal8Bit().data();
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "koshi.h"
#define  EPS 0.000000001

double var_7(double x,double y){
    return x*sin(x)+y/x;
}

void print_result(double **table,int step){
    printf("x%0* y%0*\n",5,5 );
    for (int i=0;i<step;i++){
        printf("%f %f\n",table[i][0],table[i][1]);
    }
    printf("\n");
}


int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
#ifdef Q_OS_WIN32
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("IBM 866"));
#endif

#ifdef Q_OS_LINUX
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
#endif
    double y0,a,b;
    int step,temp_step;
    double **result;
    y0=1;
    a=1.570796327;
    b=2.570796327;
    step=8;
    func f=var_7;
    method_func method;

    method=method_euler;
    temp_step=step;
    result=runge_eps(method,var_7,a,b,y0,EPS,&temp_step,1);
    printf("\nEuler's method calc on %d steps \n",temp_step);
    print_result(result,temp_step);
    free(result);

    method=method_euler_cauchy;
    temp_step=step;
    result=runge_eps(method,var_7,a,b,y0,EPS,&temp_step,2);
    printf("\nEuler-Cauchy method calc on %d steps\n",temp_step);
    print_result(result,temp_step);
    free(result);

    method=method_mod_euler;
    temp_step=step;
    result=runge_eps(method,var_7,a,b,y0,EPS,&temp_step,2);
    printf("\nmodificaton of Euler's method calc on %d steps\n",temp_step);
    print_result(result,temp_step);
    free(result);

    method=method_runge_kutta;
    temp_step=step;
    result=runge_eps(method,var_7,a,b,y0,EPS,&temp_step,4);
    printf("\nRunge-Kutta method calc on %d steps \n",temp_step);
    print_result(result,temp_step);
    free(result);

    return app.exec();
}
