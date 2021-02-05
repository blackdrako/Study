#ifndef GAME_H
#define GAME_H

#include "STLINCLUDE.h"
#include "Event.h"

using namespace std;

class Game
{
private:
    int choice;
    bool playing;

    int activeCharacter;
    std::vector<Character> characters;
    std::string fileName;

    dArr<Enemy> enemies;

public:
    Game();
    virtual ~Game();

    void initGame();
    void mainMenu();
    void createNewCharacter();
    void levelUpCharacter();
    void characterMenu();
    void saveCharacters();
    void loadCharacters();
    void selectCharacter();
    void travel();
    void rest();

    inline bool getPlaying() const { return this->playing; }

};

#endif // GAME_H
