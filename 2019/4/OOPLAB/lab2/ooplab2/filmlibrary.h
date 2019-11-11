#ifndef FILMLIBRARY_H
#define FILMLIBRARY_H
#include <QTextCodec>
#include <QTextStream>

#include <iostream>
using namespace std;
#include <string>
#include <QObject>
#include <QtDebug>
#include <QString>
#include <stdio.h>

//Основная информация***Авторская инфа
struct general{
    QString doc;
    int rate;//1-10;
};

//Допольнительная информация***С ней можно взаимодействовать
struct extra{
    int y_rate;//1-10;
};

//Фильм
struct film{
    QString name;
    unsigned pos;
    general gen_info;//Освновная инфа
    extra ex_info;//Доп инфа
};

//Фильмы
struct bib{
    film *f;//Сами фильмы
    unsigned n_bib;//Количество фильмов
};

//Библиотеки
struct filmbib{
    bib m_bib;//Подкаталог фильмы
    bib fav_bib;//Избранные фильмы
    void write_films();//Выводит всю библиотеку
    void add_film();
    void add_in_fav();
    void list_idFilm();
};



#endif // FILMLIBRARY_H
