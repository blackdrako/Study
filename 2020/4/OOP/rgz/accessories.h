#ifndef ACCESSORIES_H
#define ACCESSORIES_H

#include "STLINCLUDE.h"
#include "Item.h"

enum accessoriesType { LRING = 0, RRING };

class Accessories : public Item
{
private:
    int type;
    std::string typeStr;
    int defence;

public:
    Accessories();
    Accessories(int level,int rarity);
    Accessories(
        int type,
        int defence,
        std::string name,
        int level,
        int buyValue,
        int sellValue,
        int rarity
    );
    virtual ~Accessories();

    virtual Accessories* clone()const;

    std::string toString()const;
    std::string toStringSave()const;

    inline int getDefence()const { return this->defence; }
    inline int getType()const { return this->type; }

    static dArr<std::string> names;
    static void initNames();
};

#endif // ACCESSORIES_H
