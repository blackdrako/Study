#ifndef WEAPON_H
#define WEAPON_H
#include "STLINCLUDE.h"
#include "Item.h"

class Weapon : public Item
{
private:
    int damageMin;
    int damageMax;

public:
    Weapon();
    Weapon(int level,int rarity);
    Weapon(int damageMin,int damageMax,std::string name,int level,int buyValue,int sellValue,int rarity);
    virtual ~Weapon();

    virtual Weapon* clone()const;

    std::string toString()const;
    std::string toStringSave()const;

    inline int getDamageMin()const { return this->damageMin; }
    inline int getDamageMax()const { return this->damageMax; }

    static dArr<std::string> names;
    static void initNames();
};

#endif // WEAPON_H
