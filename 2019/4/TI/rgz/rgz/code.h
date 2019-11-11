#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//Cимвол алфавита. symb - сам символ, prob - вероятность появления.
class Symbol{
    //Непосредственно символ.
    string symb;
    //Вероятность появления символа.
    double prob;
    //Оптимальный код для элемента алфавита.
    string code;
    //Позиция символа в алфавите
    unsigned long pos;
public:
    Symbol(string symb,double prob);
    Symbol(string symb,double prob,unsigned long pos);
    double get_prob();
    string get_symb();
    string get_code();
    unsigned long get_pos();
    void set_prob(double a);
    void set_symb(string origin);
    void set_code(string code);
    void set_pos(unsigned long pos);
    void clear_code();
    void print();
    void print_code();
};

class Alphabet{
    vector<Symbol> arr;
    vector<string> code_arr;
    unsigned long size;
public:
    Alphabet(unsigned long size);
    void read();
    unsigned long get_size();
    void print();
    void print_codes();
    double sum_probs(int begin,int end);
    void code_filling_step(int begin,int end);
    //Строит оптимальный код (0 - Шеннона-Фано, 1 - Хаффмана)
    void build_code_arr(int mode);
    //Строит новый алфавит из n-грамм
    Alphabet build_nsized_Alphabet(int n);
    Symbol operator[](int i);
};
