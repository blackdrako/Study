#ifndef CLARIFICATIONOFRATINGS_H
#define CLARIFICATIONOFRATINGS_H
#include <iostream>
#include "Simplex_table.h"

class ClarSimplexTable : public Simplex_table {
public:
    ClarSimplexTable(long m, long n):Simplex_table(m, n) {};
    long clarification_step();  //øàã ìåòîäà óòî÷íåíèÿ îöåíîê
    void clarification();		//ìåòîä óòî÷íåíèÿ îöåíîê, èñïîëüçóåò ñèìïëåêñ-ìåòîä èç simplex_table
    bool is_last();				//ßâëÿåòñÿ ëè òàáëèöà ïîñëåäíåé
    bool is_valid();			//ßâëÿåòñÿ ëè òàáëèöà äîïóñòèìîé
};
#endif // CLARIFICATIONOFRATINGS_H
