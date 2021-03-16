#include <QCoreApplication>
#include <QTextCodec>
#include <iostream>
using namespace std;

#define N 1000
#define M 5

using namespace std;

float randNum = 0;
float sum = 0;
float ivar = 10;
float jvar = 4;
float kvar = 3;

int condition = 1;
int lifeTime[N];
int river = 0;
int stakes = 0;
int longestLifeTime = 0;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
#ifdef Q_OS_WIN32
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("IBM 866"));
#endif

#ifdef Q_OS_LINUX
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
#endif
    float P[M][M] = { 0 };

        P[0][0] = 1;
        P[1][1] = 1;
        P[2][0] = ivar / (ivar + jvar);
        P[2][3] = jvar / (ivar + jvar);
        P[3][2] = ivar / (ivar + jvar + kvar);
        P[3][3] = jvar / (ivar + jvar + kvar);
        P[3][4] = kvar / (ivar + jvar + kvar);
        P[4][1] = kvar / (jvar + kvar);
        P[4][3] = jvar / (jvar + kvar);

        cout << QString::fromUtf8("Матрица переходов:").toLocal8Bit().data() << endl;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < M; j++)
                printf ("%.2f\t", P[i][j]);
            cout << endl;
        }

        for (int i = 0; i < N; i++) { //обнуляем массив
            lifeTime[i] = 0;
        }
        srand(time(0));

        for (int i = 0; i < N;)
        {
            while ((condition != 3 || condition != 4) && i < N)
            {
                randNum = rand() % 99;
                randNum /= 100;

                switch (condition) {
                case 0: //на левой ноге
                    if (randNum < P[2][0])
                    {
                        condition = 3;
                        lifeTime[i]++;
                    }

                    if (randNum >= P[2][0])
                    {
                        condition = 1;
                        lifeTime[i]++;
                    }
                    break;

                case 1: //на двух ногах
                    if (randNum < P[3][2]) {
                        condition = 0;
                        lifeTime[i]++;
                    }

                    if (randNum >= P[3][2] && randNum < (P[3][2] + P[3][3]))
                    {
                        lifeTime[i]++;
                    }

                    if (randNum >= (P[3][2] + P[3][3])) {
                        condition = 2;
                        lifeTime[i]++;
                    }
                    break;

                case 2: //на правой ноге
                    if (randNum < P[4][3])
                    {
                        condition = 1;
                        lifeTime[i]++;
                    }

                    if (randNum >= P[4][3])
                    {
                        condition = 4;
                        lifeTime[i]++;
                    }
                    break;

                case 3:
                    condition = 1;
                    i++;
                    river++;
                    break;

                case 4:
                    condition = 1;
                    i++;
                    stakes++;
                    break;
                }
            }
        }

        //среднее арифметическое
        for (int i = 0; i < N; i++)
        {
            sum += lifeTime[i];
            if (lifeTime[i] > longestLifeTime)
                longestLifeTime = lifeTime[i];
        }

        sum /= N;
        cout << endl << QString::fromUtf8("Продолжительность жизни пьяницы на утесе: ").toLocal8Bit().data() << sum << endl;
        cout << endl << QString::fromUtf8("Количество падений в реку:                ").toLocal8Bit().data() << river << endl;
        cout << endl << QString::fromUtf8("Количество падений на копья:              ").toLocal8Bit().data() << stakes << endl;
        cout << endl << QString::fromUtf8("Максимальная продолжительность жизни:     ").toLocal8Bit().data() << longestLifeTime;

    return a.exec();
}
