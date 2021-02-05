#ifndef ARMOR_H
#define ARMOR_H

#include "STLINCLUDE.h"
#include "Item.h"

enum armorType { HEAD = 0, CHEST, ARMS, LEGS };

class Armor : public Item
{
private:
    int type;
    std::string typeStr;
    int defence;

public:
    Armor();
    Armor(int level,int rarity);
    Armor(int type,int defence,std::string name,int level,int buyValue,int sellValue,int rarity);
    virtual ~Armor();

    virtual Armor* clone()const;

    std::string toString()const;
    std::string toStringSave()const;

    inline int getDefence()const { return this->defence; }
    inline int getType()const { return this->type; }

    static dArr<std::string> names;
    static void initNames();
};

#endif // ARMOR_H
