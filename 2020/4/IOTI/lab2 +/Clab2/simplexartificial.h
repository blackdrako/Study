#ifndef SIMPLEXARTIFICIAL_H
#define SIMPLEXARTIFICIAL_H
#include "Simplex_table.h"

class SimplexArtificial: public Simplex_table
{
    Frac_arr Z_M;	//коэффициенты целевой функции (в том числе и свободный член)
    Frac_matr SLU_y, T_y;	//числовая часть симплекс-таблицы
    long x1, y1;		//размеры симплекс-таблицы ментода бьольших штрафов
public:
    SimplexArtificial(long m1, long n1) : Simplex_table(m1, n1), Z_M(n1 + m1), SLU_y(m1, m1 + n1), T_y() {}
    /*ввод целевой функции*/
    void getSimplexArtificialTable();
    /*Шаг симплекс-метода (переход к следующей симплекс-таблице)*/
    long simplexArtificialStep();
    void replace_y();
    long simplexArtificial();
    /*Вывод на экран симплкс-таблицы с полями соответсвующими методу больших штрафов*/
    std::ostream& outputArtificialTable(std::ostream&);
};
#endif // SIMPLEXARTIFICIAL_H
