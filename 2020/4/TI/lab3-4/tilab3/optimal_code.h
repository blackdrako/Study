#ifndef OPTIMAL_CODE_H
#define OPTIMAL_CODE_H

#include <QTextCodec>
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <queue>
#include <map>

#define EPS 0.00001

#define SHENNON_FANO_CODE 1
#define HUFFMAN_CODE 2

//Флаг выбора ввода, если закоментированно то будет компилироваться как 3/4 лаба
//без добавление пробела как последнего символа, иначе добавляет символ "пробел" и считает его вероятность

//#define _RGZ


using namespace std;

//Cимвол алфавита. symb - сам символ, prob - вероятность появления.
class Symbol{
    //Непосредственно символ.
    string symb;
    //Вероятность появления символа.
    double prob;
    //Оптимальный код для элемента алфавита.
    string code;
    //true - код построен, false - код не построен.
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

struct MinHeapNode{
    Symbol symb;
    // Left and right child
    MinHeapNode *left, *right;
    MinHeapNode(Symbol symb);
};

class Alphabet{
    vector<Symbol> arr;
    unsigned long size;
public:
    Alphabet(unsigned long size);
    Symbol operator[](int i);
    unsigned long get_size();

    void read();
    void print();
    void print_codes();
    double sum_probs(int begin,int end);
    //Шаг построения код Шеннона-Фано.
    void shennoncode_build_step(int begin,int end);
    //Строит оптимальный код
    void build_code_arr(int mode);
    //Строит новый алфавит из n-грамм
    Alphabet build_nsized_Alphabet(int n);
    //Возвращает размер символа алфавита
    unsigned get_symbol_size();
    int search_symb(string symb);

    //Возвращает среднюю длину кода.
    double avg_len();
    //Обход дерева и запись кодов в алфавит.
    void storeCodesHuffman(struct MinHeapNode* root, string str);
    //Получение кодов Хаффмана.
    void getHuffmanCodes();

    //Кодирует строку str состоящую из символов этого алфавита. **Первые 8 бит (НЕТ В РГЗ)** - размер блока.
    //**Вторые 8 бит** - кол-во добавленных символов при кусочном кодировании.
    //Остальной код - закодированная строка.*Примечание:* Так как в алфавите в РГЗ есть пробелы строку со словом **читать
    //не через cout**
    string encode_text(string str);
    //Декодирует code в строку состоящую из символов этого алфавита.
    string decode_text(string code);
};

//Возвращает строку с числом num записанным в двоичной форме.
string num_to_binstr(unsigned num);

//Возвращает число num записанным в двоичной форме в строке str.
unsigned binstr_to_num(string str);

#endif // OPTIMAL_CODE_H
