#include "accessories.h"

dArr<std::string> Accessories::names;

void Accessories::initNames()
{
    Accessories::names.push("Bro-Saver");
    Accessories::names.push("Cotton-Rag");
    Accessories::names.push("Devlish-Defender");
    Accessories::names.push("Angels-Balls");
    Accessories::names.push("Iron-Sheets");
    Accessories::names.push("Assassins-Bedsheets");
}

Accessories::Accessories()
    :Item()
{
    this->type = -1;
    this->defence = 0;
}

Accessories::Accessories(int level, int rarity)
    :Item(itemTypes::ACCESSORIES, level, rarity)
{
    this->defence = rand() % (level * (rarity+1));
    this->defence += (rarity + 1) * 5;
    this->type = rand() % 4;

    switch (this->type)
    {
    case accessoriesType::LRING:
        this->typeStr = "Head";
            break;
    case accessoriesType::RRING:
        this->typeStr = "Chest";
            break;
    default:
        this->typeStr = "ERROR INVALID!";
            break;
    }

    this->setName(Accessories::names[rand() % Accessories::names.size()]);

    if(rarity == 3)
        this->defence += level * 5;
    else if (rarity == 4)
        this->defence += level * 10;
}

Accessories::Accessories(int type, int defence, std::string name, int level, int buyValue, int sellValue, int rarity)
    : Item(itemTypes::ACCESSORIES, name, level, buyValue, sellValue, rarity)
{
    this->type = type;
    this->defence = defence;
}

Accessories::~Accessories()
{

}

Accessories* Accessories::clone()const
{
    return new Accessories(*this);
}

std::string Accessories::toString()const
{
    std::string str =
        this->getName()
        + " | Type: "
        + this->typeStr
        + " | Lvl: "
        + std::to_string(this->getLevel())
        + " | Rarity: "
        + std::to_string(this->getRarity())
        + " | Def: "
        + std::to_string(this->defence);

    return str;
}

std::string Accessories::toStringSave()const
{
    std::string str =
        std::to_string(this->getItemType())
        + " "
        + this->getName()
        + " "
        + std::to_string(this->getLevel())
        + " "
        + std::to_string(this->getRarity())
        + " "
        + std::to_string(this->getBuyValue())
        + " "
        + std::to_string(this->getSellValue())
        + " "
        + std::to_string(this->defence)
        + " "
        + std::to_string(this->type)
        + " ";

    return str;
}
