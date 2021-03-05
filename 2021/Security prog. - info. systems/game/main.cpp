#include <QCoreApplication>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

/* Функция возвращает случайное число по таблице случайных величин.
 * Входные параметры: a(значение), p(вероятность), n(Количество генераций).
 * Выходные параметры: a(значение), p(вероятность).
*/
double getRand(std::vector<double> &a, std::vector<double> &p){
    double r = rand() / double(RAND_MAX);//Генератор псевдослучайных чисел
    double temp = 0.f;
    for ( unsigned i = 0; i < a.size(); i++) {
        temp += p[i];
        if(r<temp)
            return a[i];
    }
    return 0;
}

/* Функция возвращает частоты выпадения при n бросках.
 * Входные параметры: a(значение), p(вероятность), n(Количество генераций).
 * Выходные параметры: a(значение), p(вероятность).
*/
std::vector<double> getRandFreq(std::vector<double>& a, std::vector<double>& p, unsigned int n){
    std::vector<double> buffer;
    for (unsigned int i = 0; i < a.size(); i++)
        buffer.push_back(0);
    for (unsigned int i = 0; i < n; i++){
        double r = getRand(a, p);
        for (unsigned int i = 0; i < a.size(); i++)
            if(a[i] == r)
                buffer[i]++;
    }
    return buffer;
}

/* Функция возвращает истину или лож в зависимости от результата проверки на достоверность используя критерий
 * сравения долей.
 * Входные параметры: a(значение), p(вероятность), n(Количество генераций) alp
 * Выходные параметры: a(значение), p(вероятность).
 */
bool checkTrue(std::vector<double>& a, std::vector<double>& p, unsigned int count, float alp){
    std::vector<double> n = getRandFreq(a, p, count);
    for (unsigned int i = 0; i < n.size(); i++) {
        std::cout << "n[" << i << "]:" << n[i] << std::endl;
    }
    std::vector<double> np;
    double s = 0.f;
    for (unsigned int i = 0; i < n.size(); i++)
        s += n[i];
    for(auto a : p)
        np.push_back(a * s);
    for (unsigned int i = 0; i < np.size(); i++) {
        std::cout << "np[" << i << "]:" << np[i] << std::endl;
    }
    double kv = 0.f;
    for (unsigned int i = 0; i < n.size(); i++)
        kv += (n[i]-np[i])*(n[i]-np[i]) / np[i];
    std::cout << "kv = " << kv << std::endl;
    return kv < 7.8f;
}

void task(){
    std::vector<double> a = { 0.f, 1.f, 2.f, 3.f}; //Значения
    std::vector<double> p = {10.f/34.f, 7.f/34.f, 13.f/34.f, 4.f/34.f}; //Вероятности
    unsigned int n = 10000; //Количество генерация(экспериментов
    if (checkTrue(a, p, n, 0.05f))
        std::cout << "True" << std::endl;
    else
        std::cout << "False" << std::endl;
}

#include <QTextCodec>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
#ifdef Q_OS_WIN32
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("IBM 866"));
#endif

#ifdef Q_OS_LINUX
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
#endif
    task();
    return a.exec();
}
