#include <QCoreApplication>
#include <QTextCodec>
#include <iostream>
using namespace std;

/* Функция возвращает случайное число по таблице случайных величин.
 * Входные параметры: a(значение), p(вероятность), n(Количество генераций).
 * Выходные параметры: a(значение), p(вероятность).
*/
template <typename Item>
double getRand(vector<Item> &a, vector<Item> &p){
    double r = rand() / static_cast<Item>(RAND_MAX);//Генератор псевдослучайных чисел
    double temp = static_cast<double>(0.f);
    for ( unsigned i = 0; i < a.size(); i++) {
        temp += p[i];
        if(r<temp)
            return a[i];
    }
    return 0;
}

struct Life
{
    int lifeTime;
    int state;

    Life() : lifeTime(0), state(0) {}

    bool isLive()
    {
        return (state != 3 && state != 4);
    }

/*
Функция движения пьяницы
Вход:
p - вектор с вероятностями переходов {
0)0->0,
1)1->0,
2)0->1,
3)1->3,
4)2->0,
5)0->2,
6)2->4
}

новое состояние:
0 - обе ноги
1 - левая нога
2 - правая нога
3 - река
4 - колья
*/
    void move(vector<float> p)
    {
        //Проверяем состояния
        if (state == 0)
        {
            //Получаем СВ
            vector<float> buf_p = { p[0], p[2],p[5] };
            vector<float> states = { 0, 1, 2 };
            state = getRand(states, buf_p);
            lifeTime++;
        }
        else if (state == 1)
        {
            vector<float> buf_p = { p[1], p[3] };
            vector<float> states = { 0, 3 };
            state = getRand(states, buf_p);
            lifeTime++;
        }
        else if (state == 2)
        {
            vector<float> buf_p = { p[4], p[6] };
            vector<float> states = { 0, 4 };
            state = getRand(states, buf_p);
            lifeTime++;
        }
        else
        {
            state = state;
        }
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
#ifdef Q_OS_WIN32
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("IBM 866"));
#endif

#ifdef Q_OS_LINUX
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
#endif
    srand(time(0));
    vector<float> p = {0.4f, 4.f/7.f, 0.3f, 3.f/7.f,4.f/7.f,0.3f, 3.f/7.f}; //Вероятности переходов
    int n = 1000; //Количество экспериментов

    //Просчет жизней
    vector<Life> lifes;
    for (int i = 0; i < n; i++)
    {
        Life l;
        while (l.isLive())
            l.move(p);

        lifes.push_back(l);
    }

    //Расчет показателей
    int totalRiverDeath = 0;
    int totalStakesDeath = 0;
    int totalLifeTime = 0;

    for (auto a : lifes)
    {
        if (a.state == 3)
            totalRiverDeath++;
        else if (a.state == 4)
            totalStakesDeath++;
        totalLifeTime += a.lifeTime;
    }

    cout << "Average life time: " << (float)totalLifeTime / n << endl;
    cout << "% river death: " << (float)totalRiverDeath / n * 100 <<"%"<< endl;
    cout << "% stakes death: " << (float)totalStakesDeath / n * 100 << "%" << endl;

    return a.exec();
}
