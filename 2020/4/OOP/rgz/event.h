#ifndef EVENT_H
#define EVENT_H

#include "STLINCLUDE.h"
#include "Character.h"
#include "Enemy.h"
#include "Boss.h"

class Event
{
private:

public:
    Event();
    virtual ~Event();
    void generateEvent(Character &character, dArr<Enemy>& enemies);

    void shopEncouter(Character &character);
    void enemyEncouter(Character &character, dArr<Enemy>& enemies);

    static int nrOfEvents;
};

#endif // EVENT_H
