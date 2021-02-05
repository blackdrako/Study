#ifndef BATTLE_H
#define BATTLE_H
#include <monster.h>
#include <character.h>
class Turn
{
private:
    void castSpell();
    void attack();
};

class battle
{
private:
    long unsigned int counterTurn = 0;
    Unit hero();
    Unit enemy();
public:
    battle(Unit,Unit);
};

#endif // BATTLE_H
