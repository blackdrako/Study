#ifndef ITEM_H
#define ITEM_H


#include "STLINCLUDE.h"

enum itemTypes {WEAPON = 0, ARMOR, ACCESSORIES};

class Item
{
private:
    int itemType;
    std::string name;
    int level;
    int buyValue;
    int sellValue;
    int rarity;

public:
    Item();
    Item(int itemType,int level,int rarity);
    Item(int itemType,std::string name,int level,int buyValue,int sellValue,int rarity);
    virtual ~Item();

    inline std::string debugPrint() const { return this->name; }
    virtual Item* clone()const = 0;
    virtual std::string toString()const = 0;
    virtual std::string toStringSave()const = 0;

    inline const std::string& getName() const { return this->name; }
    inline const int& getLevel() const { return this->level; }
    inline const int& getBuyValue() const { return this->buyValue; }
    inline const int& getSellValue() const { return this->sellValue; }
    inline const int& getRarity() const { return this->rarity; }
    inline const int& getItemType() const { return this->itemType; }

    inline void setName(std::string name) { this->name = name; }
};

enum rarity {
    COMMON = 0,
    UNCOMMON,
    RARE,
    LEGENDARY,
    MYTHIC
};

#endif // ITEM_H
