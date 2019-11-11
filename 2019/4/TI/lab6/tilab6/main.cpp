#include <QCoreApplication>
#include <QTextCodec>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <fstream>
#include <math.h>

#include <sstream>
#include <cstdlib>
#include <ctime>
#include "polynom.h"

int choose(std::string s, int min, int max){
    int answer;
    do{
        std::cout << s << std::endl;
        std::cin >> answer;
    }while (answer < min || answer > max);
    return answer;
}

/*
 * Конвертация строки в массив булев
 */
// С конца строки копируем ее в массив. То есть, строка 1011 создаст массив 1, 1, 0, 1, 0, 0, ...
void str_to_bools(std::string s, bool a[]){
    int i = 0;
    for (std::string::iterator it=s.begin(); it!=s.end(); it++) {
        //std::cout << *it << std::endl;
        a[i] = *it - '0';
        //std::cout << i << a[i] << std::endl;
        i++;
    }
    while (i < size){
        a[i] = 0;
        i++;
    }
    //std::cout << std::endl;
}
int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
#ifdef Q_OS_WIN32
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("IBM 866"));
#endif

#ifdef Q_OS_LINUX
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
#endif
    system("chcp 65001");
    std::string a[100];
    std::string M;
    std::string M_cod;

    std::string MMM = "";

    std::string i_str;
    std::string raw_str;

    char* f_name;
    std::ifstream f_in;
   //     std::cin >> f_name;
   int f;
   std::cout << "выберите способ ввода (0 - клавиатуры / 1 - файл)  :  ";
   std::cin >> f;
   std::string new_msg;
   switch (f)
   {
   case 0:
        std::cin >> new_msg;
        break;
   case 1:
        f_name = "message.txt";
        f_in.open(f_name);
        f_in >> new_msg;
        break;
   }

    int RR = 4;
    int NN = 1;
    for (int i = 0; i < RR; i++)
        NN = NN*2;
    NN = NN - 1;
    int KK = NN - RR;


        std::cout << "\n\n\nпрочитана последовательность: \n" << new_msg << "(" << new_msg.length() <<")" <<std::endl;
//        int QW = new_msg.length() % KK;
//        if (QW != 0)
//        {
//            std::cout << "дополним в конец сообщения " << (KK - QW) % KK << " битами 0\n";
//            for (int i = 0; i < (KK - QW) % KK; i++)
//                new_msg += "0";
//        }
//
//        std::cout << "допишем в начало сообщения " << KK << "бит с количеством дополненных символов = "<< (KK - QW) % KK << "\n";
//        std::string new_block = to_dv(KK, (KK - QW) % KK);
//
//
//
//        std::cout << new_block << new_msg << "(" << new_msg.length() + new_block.length() <<")"<< "\n";
        for (int i = new_msg.length() - 1; i >= 0; i--)
            raw_str = raw_str + new_msg[i];
//        for (int i = 0; i < new_block.length(); i++)
//            raw_str = new_block[i] + raw_str;
        f_in.close();

        std::string::iterator it = raw_str.begin();
//////        srand(time(NULL));
//////        int ran = rand() % (raw_str.length() / k);
        // Заменить 4 на реальную длину
//////        printf("\n\n\nERROR = %i\n\n\n",ran);
//////        QW = 0;
        while(it + KK <= raw_str.end()) {

            i_str.clear();
            i_str.resize(KK);
            for (int i = 0; i < KK; i++){
                i_str[i] = *it;
                it++;
            }
            std::cout << "Кодируем блок: ";
            for (int j = i_str.length() - 1; j >= 0; j--)
                std::cout << i_str[j];
            std::cout << std::endl;

            bool i_array[size];
            str_to_bools(i_str, i_array);
            Polynomial i(i_array);
            std::cout << "Информационное слово i(x) = " << i.str() << std::endl << std::endl;
//////            if (QW == ran)
//////            {
//////                int er = rand() % n;
//////                printf("произошла ошибка %i бите\n", er);
//////                i_str[er] ^= 1;
//////                std::cout << i_str << std::endl;
//////            }
//////            QW++;
            // Кодирование
            Polynomial g(const_g);
            Polynomial xr(const_xr);
            std::cout << "Получаем кодовое слово по формуле c(x) = x^r * i(x) + Rem_g(x) (x^r * i(x))" << std::endl;
            std::cout << "g(x) = " << g.str() << std::endl;
            std::cout << "x^r = " << xr.str() << std::endl;
            Polynomial t = xr * i;
            std::cout << "x^r * i(x) = " << t.str() << std::endl;
            Polynomial r = t % g;
            std::cout << "Rem = (x^r * i(x)) % g(x) = " << r.str() << std::endl;
            Polynomial c = t + r;
            std::cout << "c(x) = x^r * i(x) + Rem = " << c.str() << std::endl;
            std::cout << "В канал связи передается последовательность ";
            for (int j = c.str_bit().length() - 1; j >= 0 ; j--)
                std::cout << c.str_bit()[j];
             std::cout << std::endl << std::endl;

            bool corrupt_bit;

            // выбираем, какой бит убить к чертям собачьим

            // Надо ли вообще вносить ошибку?
            corrupt_bit = 1; // Вероятность не получить ошибку 1/3
                         /*
            // Если ошибку требуется вносить всегда, выбери эту строку
            corrupt_bit = true;
            */
            // Если выбираем внесение ошибки вручную, выбери эту строку
            //corrupt_bit = choose("Внести ошибку в передаваемое сообщение? 1 - не вносить, 2 - внести: ", 1, 2) - 1;

            Polynomial y;
            std::string MM = "";
            if (corrupt_bit) {
                int bit = 7;
                Polynomial e(bit, size);
                std::cout << "Вносим ошибку в " << bit
                          << "-й бит передаваемого слова c, получаем слово y(x) = c(x) + e(x)" << std::endl;
                y = c + e;
                std::cout << "y(x) = " << c.str() << " + " << e.str() << " = " << y.str() << std::endl << std::endl;
                std::cout << "Декодер принял последовательность ";
                for (int j = y.str_bit().length() - 1; j >= 0; j--)
                    std::cout << y.str_bit()[j];
                std::cout<< std::endl;
                std::cout << "Для проверки правильности принятого кода вычисляем y(e) = ";
                std::cout << y.str_epsilon() << " = ";
                Polynomial syndrome = y.sum_epsilon();
                std::cout << syndrome.str('e');
                int e_d = syndrome.error_digit();
                // Тут будет грязно
                if (e_d >= 3) {
                    std::cout << " = e" << e_d;
                }
                std::cout << std::endl;

                std::cout << "Ошибка произошла в " << e_d << "-м бите" << std::endl << std::endl;
                Polynomial re_e(e_d, size);
                y += re_e;
                std::cout << "Чтобы исправить ошибку, выполним сложение y(x) = y(x) + e(x) = " << y.str() << std::endl
                          << std::endl;
            } else {
                y = c;
            }

            std::cout << "Для проверки правильности принятого кода вычисляем y(e) = ";
            std::cout << y.str_epsilon() << " = ";
            Polynomial syndrome = y.sum_epsilon();
            std::cout << syndrome.str('e') << std::endl;
            int e_d = syndrome.error_digit();
            if (e_d == -1) {
                std::cout << "Ошибок не обнаружено" << std::endl << std::endl;
            } else {
                std::cout << "Ошибка произошла в " << e_d << "-м бите" << std::endl;
            }

            y <<= RR;
            std::string M = y.str_bit();
            M.erase(KK);
            std::cout << "Отбрасываем проверочные биты, получаем многочлен " << y.str() << std::endl;
            std::cout << "Он соответствует информационному слову ";
            for (int j = M.length() - 1; j >= 0; j--)
                std::cout << M[j];
            std::cout << std::endl << std::endl;
            MMM += M;
     //       getch();
        }

    return app.exec();
}
