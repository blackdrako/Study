#ifndef TRANS_H
#define TRANS_H


#include <iostream>
#include <string>
using namespace std;

struct numberTrans
{
    unsigned int cod_region;//38 - Xz
    string country;//Rus
    string series;//серия C...AB
    unsigned int reg_number;//.065..
};

class Trans
{
protected:
    string marka;
public:
    Trans(string name):marka(name){}
    virtual void print_trans() = 0;
    virtual long double metod_carrying() = 0;
    virtual void scan_trans() = 0;
};

class Car: public Trans
{
public:
    Car(string name):Trans(name){}
    virtual void print_trans() = 0;
    virtual long double metod_carrying() = 0;
    virtual void scan_trans() = 0;
};

#endif // TRANS_H
