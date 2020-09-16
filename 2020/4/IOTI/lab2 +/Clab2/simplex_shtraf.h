#ifndef SIMPLEX_SHTRAF_H
#define SIMPLEX_SHTRAF_H
#include "Simplex_table.h"

class SimplexShtraf: public Simplex_table
{
    Frac_arr Z_M;	//êîýôôèöèåíòû öåëåâîé ôóíêöèè (â òîì ÷èñëå è ñâîáîäíûé ÷ëåí)
    Frac_matr SLU_y, T_y;	//÷èñëîâàÿ ÷àñòü ñèìïëåêñ-òàáëèöû
    long x1, y1;		//ðàçìåðû ñèìïëåêñ-òàáëèöû ìåíòîäà áüîëüøèõ øòðàôîâ
public:
    SimplexShtraf(long m1, long n1): Simplex_table(m1, n1), Z_M(n1 + m1), SLU_y(m1, m1 + n1), T_y() {}
    /*ââîä öåëåâîé ôóíêöèè*/
    void getSimplexShtrafTable();
    /*Øàã ñèìïëåêñ-ìåòîäà (ïåðåõîä ê ñëåäóþùåé ñèìïëåêñ-òàáëèöå)*/
    long simplexShtrafStep();
    long simplexShtraf();
    /*Âûâîä íà ýêðàí ñèìïëêñ-òàáëèöû ñ ïîëÿìè ñîîòâåòñâóþùèìè ìåòîäó áîëüøèõ øòðàôîâ*/
    std::ostream& outputShtrafTable(std::ostream&);
    Fraction maxKoef();
    //~Simplex_table();
};
#endif // SIMPLEX_SHTRAF_H
