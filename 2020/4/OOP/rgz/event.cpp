#include "event.h"

int Event::nrOfEvents = 4;

using namespace std;;

Event::Event()
{

}

Event::~Event()
{

}

void Event::generateEvent(Character &character, dArr<Enemy>& enemies)
{
    int i = rand() % Event::nrOfEvents;

    switch (i)
    {
    case 0:
        //Enemy encounter
        this->enemyEncouter(character, enemies);
        break;
    case 1:
        //Shop
        this->shopEncouter(character);
        break;
    default:
        break;
    }
}

//Different events
void Event::shopEncouter(Character &character)
{
    int choice = 0;
    bool shopping = true;
    Inventory merchantInv;
    string inv;

    //Init merchant inv
    int nrOfItems = rand() % 20 + 10;
    bool coinToss = false;

    for (size_t i = 0; i < nrOfItems; i++)
    {
        coinToss = rand() % 2;

        if(coinToss > 0)
            merchantInv.addItem(Weapon(character.getLevel() + rand() % 5, rand() % 4));
        else
            merchantInv.addItem(Armor(character.getLevel() + rand() % 5, rand() % 4));
    }

    while (shopping)
    {
        system("CLS");

        cout << QString::fromUtf8("= Меню магазина =").toLocal8Bit().data() << "\n\n";

        cout << QString::fromUtf8("0: Покинуть").toLocal8Bit().data() << "\n";
        cout << QString::fromUtf8("1: Купить").toLocal8Bit().data() << "\n";
        cout << QString::fromUtf8("2: Продать").toLocal8Bit().data() << "\n";
        cout << "\n";

        cout << QString::fromUtf8("Ввод: ").toLocal8Bit().data();

        cin >> choice;

        while (cin.fail() || choice > 3 || choice < 0)
        {
            system("CLS");

            cout << QString::fromUtf8("Неправильный ввод!").toLocal8Bit().data() << "\n";
            cin.clear();
            cin.ignore(100, '\n');

            cout << QString::fromUtf8("= Меню магазина =").toLocal8Bit().data() << "\n\n";

            cout << QString::fromUtf8("0: Покинуть").toLocal8Bit().data() << "\n";
            cout << QString::fromUtf8("1: Купить").toLocal8Bit().data() << "\n";
            cout << QString::fromUtf8("2: Продать").toLocal8Bit().data() << "\n";

            cout << "\n";

            cout << QString::fromUtf8("Ввод: ").toLocal8Bit().data();
            cin >> choice;
        }

        cin.ignore(100, '\n');
        cout << "\n";

        //Shop
        switch (choice)
        {
        case 0: //Leave
            shopping = false;
            break;

        case 1: //Buy

            cout << QString::fromUtf8("= Меню покупки =").toLocal8Bit().data() << "\n\n";

            cout << QString::fromUtf8(" - Золото: ").toLocal8Bit().data() <<character.getGold() << "\n\n";

            inv.clear();

            for (size_t i = 0; i < merchantInv.size(); i++)
            {
                inv += to_string(i) + ": " + merchantInv[i].toString() + QString::fromUtf8("\n - цена: ").toLocal8Bit().data() + to_string(merchantInv[i].getBuyValue()) + "\n";
            }

            cout << inv << "\n";

            cout << QString::fromUtf8("Золото: ").toLocal8Bit().data() << character.getGold() << "\n";
            cout << QString::fromUtf8("Выбор предмета (-1 to cancel): ").toLocal8Bit().data();

            cin >> choice;

            while (cin.fail() || choice > merchantInv.size() || choice < -1)
            {
                system("CLS");

                cout << QString::fromUtf8("Неправильный ввод!").toLocal8Bit().data() << "\n";
                cin.clear();
                cin.ignore(100, '\n');

                cout << QString::fromUtf8("Золото: ").toLocal8Bit().data() << character.getGold() << "\n";
                cout << QString::fromUtf8("Выбор предмета (-1 to cancel): ").toLocal8Bit().data();
                cin >> choice;
            }

            cin.ignore(100, '\n');
            cout << "\n";

            if (choice == -1)
            {
                cout << QString::fromUtf8("Назад...").toLocal8Bit().data() << "\n";
            }
            else if (character.getGold() >= merchantInv[choice].getBuyValue())
            {
                character.payGold(merchantInv[choice].getBuyValue());
                character.addItem(merchantInv[choice]);

                cout << QString::fromUtf8("Купил предмет ").toLocal8Bit().data() << merchantInv[choice].getName() << " -" << merchantInv[choice].getBuyValue() << "\n";

                merchantInv.removeItem(choice);
            }
            else
            {
                cout << QString::fromUtf8("Вы не можете себе позволить этот предмет!").toLocal8Bit().data() << "\n";
            }

            break;

        case 2: //Sell

            cout << character.getInvAsString(true) << "\n";

            cout << QString::fromUtf8("= Меню продажи =").toLocal8Bit().data() << "\n\n";

            cout << QString::fromUtf8(" - Золото: ").toLocal8Bit().data() << character.getGold() << "\n\n";

            if (character.getInventorySize() > 0)
            {
                cout << QString::fromUtf8("Золото: ").toLocal8Bit().data() << character.getGold() << "\n";
                cout << QString::fromUtf8("Выбор предмета (-1 to cancel): ").toLocal8Bit().data();

                cin >> choice;

                while (cin.fail() || choice > character.getInventorySize() || choice < -1)
                {
                    system("CLS");

                    cout << QString::fromUtf8("Неправильный ввод!").toLocal8Bit().data() << "\n";
                    cin.clear();
                    cin.ignore(100, '\n');

                    cout << QString::fromUtf8("Золото: ").toLocal8Bit().data() << character.getGold() << "\n";
                    cout << QString::fromUtf8("Выбор предмета (-1 to cancel): ").toLocal8Bit().data();
                    cin >> choice;
                }

                cin.ignore(100, '\n');
                cout << "\n";

                if (choice == -1)
                {
                    cout << QString::fromUtf8("Назад...").toLocal8Bit().data() << "\n";
                }
                else
                {
                    character.gainGold(character.getItem(choice).getSellValue());

                    cout << QString::fromUtf8("Предмет продан!").toLocal8Bit().data() << "\n";
                    cout << QString::fromUtf8("Золота получено: ").toLocal8Bit().data() << character.getItem(choice).getSellValue() << "\n\n";
                    character.removeItem(choice);
                }
            }
            else
            {
                cout << QString::fromUtf8("Инвентарь пуст...").toLocal8Bit().data() << "\n";
            }

            break;

        default:
            break;
        }

        cout << QString::fromUtf8("Нажмите Enter, чтобы продолжить...").toLocal8Bit().data() << "\n";
        cin.get();
    }

    cout << QString::fromUtf8("Вы покинули магазин..").toLocal8Bit().data() << "\n\n";
}

void Event::enemyEncouter(Character &character, dArr<Enemy>& enemies)
{
    bool playerTurn = false;
    int choice = 0;

    int coinToss = rand() % 2 + 1;

    if (coinToss == 1)
        playerTurn = true;
    else
        playerTurn = false;

    bool escape = false;
    bool playerDefeated = false;
    bool enemiesDefeated = false;

    int nrOfEnemies = rand() % 5 + 1;

    for (size_t i = 0; i < nrOfEnemies; i++)
    {
        enemies.push(Enemy(character.getLevel() + rand()%3));
    }

    //Battle variables
    int damage = 0;
    int gainExp = 0;
    int gainGold = 0;
    int playerTotal = 0;
    int enemyTotal = 0;
    int combatTotal = 0;
    int combatRollPlayer = 0;
    int combatRollEnemy = 0;

    while (!escape && !playerDefeated && !enemiesDefeated)
    {
        if (playerTurn && !playerDefeated)
        {
            cout << QString::fromUtf8("= Ход игрока =").toLocal8Bit().data() << "\n\n";
            cout << "Continue..." << "\n\n";
            cin.get();
            system("CLS");

            cout << QString::fromUtf8("= Боевое меню =").toLocal8Bit().data() << "\n\n";
            cout << "HP: " << character.getHP() << " / " << character.getHPMax() << "\n\n";

            cout << "0: Escape" << "\n";
            cout << "1: Attack" << "\n";
            cout << "2: Defend" << "\n";
            cout << "3: Use Item" << "\n";
            cout << "\n";

            cout << QString::fromUtf8("Ввод: ").toLocal8Bit().data();

            cin >> choice;

            while (cin.fail() || choice > 3 || choice < 0)
            {
                system("CLS");

                cout << QString::fromUtf8("Неправильный ввод!").toLocal8Bit().data() << "\n";
                cin.clear();
                cin.ignore(100, '\n');

                cout << "= BATTLE MENU =" << "\n\n";

                cout << "0: Escape" << "\n";
                cout << "1: Attack" << "\n";
                cout << "2: Defend" << "\n";
                cout << "3: Use Item" << "\n";
                cout << "\n";

                cout << QString::fromUtf8("Ввод: ").toLocal8Bit().data();
                cin >> choice;
            }

            cin.ignore(100, '\n');
            cout << "\n";

            //Moves
            switch (choice)
            {
            case 0: //ESCAPE
                escape = true;
                break;

            case 1: //ATTACK

                //Select enemy
                cout << "Select enemy: " << "\n\n";

                for (size_t i = 0; i < enemies.size(); i++)
                {
                    cout << i << ": "
                        << "Level: " << enemies[i].getLevel() << " - " <<
                        "HP: " << enemies[i].getHp() << "/" << enemies[i].getHpMax() << " - " <<
                        "Defence: " << enemies[i].getDefence() << " - " <<
                        "Accuracy: " << enemies[i].getAccuracy() << " - " <<
                        "Damage: " << enemies[i].getDamageMin() << " - " << enemies[i].getDamageMax() <<
                        "\n";
                }

                cout << "\n";
                cout << QString::fromUtf8("Ввод: ").toLocal8Bit().data();

                cin >> choice;

                while (cin.fail() || choice >= enemies.size() || choice < 0)
                {
                    cout << QString::fromUtf8("Неправильный ввод!").toLocal8Bit().data() << "\n";
                    cin.clear();
                    cin.ignore(100, '\n');

                    cout << "Select enemy: " << "\n\n";
                    cout << QString::fromUtf8("Ввод: ").toLocal8Bit().data();
                    cin >> choice;
                }

                cin.ignore(100, '\n');
                cout << "\n";

                //Attack roll
                combatTotal = enemies[choice].getDefence() + character.getAccuracy();
                enemyTotal = enemies[choice].getDefence() / (double)combatTotal * 100;
                playerTotal = character.getAccuracy() / (double)combatTotal * 100;
                combatRollPlayer = rand() % playerTotal + 1;
                combatRollEnemy = rand() % enemyTotal + 1;

                cout << "Combat total: " << combatTotal << "\n";
                cout << "Enemy percent: " << enemyTotal << "\n";
                cout << "Player percent: " << playerTotal << "\n\n";
                cout << "Player roll: " << combatRollPlayer << "\n";
                cout << "Enemy roll: " << combatRollEnemy << "\n\n";

                if (combatRollPlayer > combatRollEnemy) //Hit
                {
                    cout << "HIT! " << "\n\n";

                    damage = character.getDamage();
                    enemies[choice].takeDamage(damage);

                    cout << "Damage: " << damage << "!" << "\n\n";

                    if (!enemies[choice].isAlive())
                    {
                        cout << "ENEMY DEFEATED!" << "\n\n";
                        gainExp = enemies[choice].getExp();
                        character.gainExp(gainExp);
                        gainGold = rand() % enemies[choice].getLevel() * 10 + 1;
                        character.gainGold(gainGold);
                        cout << "EXP GAINED: " << gainExp << "\n";
                        cout << "GOLD GAINED: " << gainGold << "\n\n";

                        //Item roll
                        int roll = rand() % 100 + 1;
                        int rarity = -1;

                        if (roll > 20)
                        {
                            rarity = 0; //Common

                            roll = rand() % 100 + 1;
                            if (roll > 30)
                            {
                                rarity = 1; //Uncommon

                                roll = rand() % 100 + 1;
                                if (roll > 50)
                                {
                                    rarity = 2; //Rare

                                    roll = rand() % 100 + 1;
                                    if (roll > 70)
                                    {
                                        rarity = 3; //Legendary

                                        roll = rand() % 100 + 1;
                                        if (roll > 90)
                                        {
                                            rarity = 4; //Mythic
                                        }
                                    }
                                }
                            }
                        }

                        if (roll >= 0)
                        {
                            roll = rand() % 100 + 1;

                            if (roll > 50)
                            {
                                Weapon tempW(character.getLevel(), rarity);
                                character.addItem(tempW);
                                cout << "WEAPON DROP!" << "\n";
                            }
                            else
                            {
                                Armor tempA(character.getLevel(), rarity);
                                character.addItem(tempA);
                                cout << "ARMOR DROP!" << "\n";
                            }
                        }

                        enemies.remove(choice);
                    }
                }
                else //Miss
                {
                    cout << QString::fromUtf8("Промах! \n\n").toLocal8Bit().data();
                }

                break;

            case 2: //DEFEND

                break;

            case 3: //ITEM

                break;

            default:
                break;
            }

            //End turn
            playerTurn = false;
        }
        else if(!playerTurn && !playerDefeated && !escape && !enemiesDefeated)
        {
            cout << QString::fromUtf8("=Ход врага=").toLocal8Bit().data() << "\n";

            cout << QString::fromUtf8("Продолжить...").toLocal8Bit().data() << "\n\n";
            cin.get();
            system("CLS");

            //Enemy attack
            for (size_t i = 0; i < enemies.size(); i++)
            {
                cout << QString::fromUtf8("Продолжить...").toLocal8Bit().data() << "\n\n";
                cin.get();
                system("CLS");

                cout << QString::fromUtf8("Враг: ").toLocal8Bit().data() << i << "\n\n";

                //Attack roll
                combatTotal = enemies[i].getAccuracy() + (character.getDefence() + character.getAddedDefence());
                enemyTotal = enemies[i].getAccuracy() / (double)combatTotal * 100;
                playerTotal = (character.getDefence() + character.getAddedDefence()) / (double)combatTotal * 100;
                combatRollPlayer = rand() % playerTotal + 1;
                combatRollEnemy = rand() % enemyTotal + 1;

                cout << "Combat total: " << combatTotal << "\n";
                cout << "Enemy percent: " << enemyTotal << "\n";
                cout << "Player percent: " << playerTotal << "\n\n";
                cout << "Player roll: " << combatRollPlayer << "\n";
                cout << "Enemy roll: " << combatRollEnemy << "\n\n";

                if (combatRollPlayer < combatRollEnemy) //Hit
                {
                    cout << "HIT! " << "\n\n";

                    damage = enemies[i].getDamage();
                    character.takeDamage(damage);

                    cout << "Damage: " << damage << "!" << "\n";
                    cout << "HP: " << character.getHP() << " / " << character.getHPMax() << "\n\n";

                    if (!character.isAlive())
                    {
                        cout << QString::fromUtf8("Вы проиграли!").toLocal8Bit().data() << "\n\n";
                        playerDefeated = true;
                    }
                }
                else //Miss
                {
                    cout << QString::fromUtf8("Промах! \n\n").toLocal8Bit().data();
                }
            }

            //End turn
            playerTurn = true;
        }

        //Conditions
        if (!character.isAlive())
        {
            playerDefeated = true;
        }
        else if (enemies.size() <= 0)
        {
            enemiesDefeated = true;
        }
    }
}
