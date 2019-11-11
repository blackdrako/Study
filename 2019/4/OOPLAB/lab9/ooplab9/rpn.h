#ifndef RPN_H
#define RPN_H
#include <QTextCodec>
#include <string>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

const string STR_PLUS = "+";
const string STR_SUB = "-";
const string STR_MULT = "*";
const string STR_DIV = "/";
const string STR_OPEN_BRC = "(";
const string STR_CLOSE_BRC = ")";


enum Token_priority{
    operand_priority = 0,
    bracket_priority = 0,
    mult_priority = 2,
    div_priority = 2,
    sum_priority = 1,
    sub_priority = 1
};

enum Token_id{
    operand_id = 0,
    sum_id = 1,
    subst_id = 2,
    mult_id = 3,
    div_id = 4,
    open_brc_id = 5,
    close_brc_id = 6,
};

class Token{
    public:
        virtual int calc(int a,int b) = 0;
        virtual int get_value() = 0;
        virtual string get_str() = 0;
        virtual Token_priority get_prior() = 0;
        virtual Token_id get_id() = 0;
};

class Operand: public Token{
    private:
        int value;
    public:
        int calc(int a, int b){return 0;};
        Operand(int value):value(value){};
        int get_value(){return this->value;};
        void set_value(int val){this->value=val;};
        string get_str(){return to_string(this->value);};
        Token_priority get_prior(){return operand_priority;};
        Token_id get_id(){return operand_id;};
};

class Open_bracket: public Token{
    public:
        int calc(int a, int b){return 0;};
        int get_value(){return 0;};
        string get_str(){return STR_OPEN_BRC;};
        Token_priority get_prior(){return bracket_priority;};
        Token_id get_id(){return open_brc_id;};
};

class Close_bracket: public Token{
    public:
        int calc(int a, int b){return 0;};
        int get_value(){return 0;};
        string get_str(){return STR_CLOSE_BRC;};
        Token_priority get_prior(){return bracket_priority;};
        Token_id get_id(){return close_brc_id;};
};


class OperatorPlus: public Token{
    public:
        int calc(int a,int b){
            return a+b;
        };
        int get_value(){return 0;};
        Token_priority get_prior(){return sum_priority;};
        Token_id get_id(){return sum_id;};
        string get_str(){return STR_PLUS;};
};

class OperatorMinus: public Token{
    public:
        int calc(int a,int b){
            return a-b;
        };
        int get_value(){return 0;};
        Token_priority get_prior(){return sub_priority;};
        Token_id get_id(){return subst_id;};
        string get_str(){return STR_SUB;};
};

class OperatorDiv: public Token{
    public:
        int calc(int a,int b){
            return a/b;
        };
        int get_value(){return 0;};
        Token_priority get_prior(){return div_priority;};
        Token_id get_id(){return div_id;};
        string get_str(){return STR_DIV;};
};

class OperatorMult: public Token{
    public:
        int calc(int a,int b){
            return a*b;
        };
        int get_value(){return 0;};
        Token_priority get_prior(){return mult_priority;};
        Token_id get_id(){return mult_id;};
        string get_str(){return STR_MULT;};
};

Token* create_token(Token_id id);
string infix_to_postfix(string str);
vector<Token*> str_to_token(string str);
int calc_tokens(vector<Token*> tokens);
#endif // RPN_H
