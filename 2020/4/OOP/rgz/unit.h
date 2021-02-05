#ifndef UNIT_H
#define UNIT_H
#include <string>

class Unit
{
private:
public:
    std::string nameUnit;
    long int LVL;
    long double maxXP;
    long double maxMP;
    long double maxAtt;
    long double minAtt;
    Unit(): nameUnit("Unknow"){}
    Unit(std::string s,long int a,long double b,long double c,long double d,long double e): nameUnit(s),LVL(a),maxXP(b),maxMP(c),maxAtt(d),minAtt(e){}
};

#endif // UNIT_H
