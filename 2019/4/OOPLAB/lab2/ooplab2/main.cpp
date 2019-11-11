#include <QCoreApplication>
#include "filmlibrary.h"
//Программа «Домашняя фильмотека»


filmbib save(){
    filmbib save_film;

    save_film.m_bib.f = new film[3];
    save_film.m_bib.n_bib = 3;

    save_film.fav_bib.f = new film[1];
    save_film.fav_bib.n_bib = 1;

    save_film.m_bib.f[0].name = "The Shawshank Redemption";
    save_film.m_bib.f[0].gen_info.doc = '1';
    save_film.m_bib.f[0].pos = 0;
    save_film.m_bib.f[0].gen_info.rate = 3;
    save_film.m_bib.f[0].ex_info.y_rate = 2;

    save_film.m_bib.f[1].name = "The Green Mile";
    save_film.m_bib.f[1].gen_info.doc = "2";
    save_film.m_bib.f[1].pos = 1;
    save_film.m_bib.f[1].gen_info.rate = 5;
    save_film.m_bib.f[1].ex_info.y_rate = 6;

    save_film.m_bib.f[2].name = "Forrest Gump";
    save_film.m_bib.f[2].gen_info.doc = "3";
    save_film.m_bib.f[2].pos = 2;
    save_film.m_bib.f[2].gen_info.rate = 1;
    save_film.m_bib.f[2].ex_info.y_rate = 2;

    save_film.fav_bib.f[0].name = "Schindler's List";
    save_film.fav_bib.f[0].gen_info.doc = "4";
    save_film.fav_bib.f[0].pos = 0;
    save_film.fav_bib.f[0].gen_info.rate = 3;
    save_film.fav_bib.f[0].ex_info.y_rate = 9;
    return save_film;
}


int main(int argc, char *argv[])
{
    QCoreApplication applications(argc, argv);
#ifdef Q_OS_WIN32
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("IBM 866"));
#endif    

#ifdef Q_OS_LINUX
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
#endif

    //filmbib savefilm = save();
    //savefilm.add_in_fav();
    //savefilm.write_films();
    int a=8;
    printf("%d",(a<<2));

    return applications.exec();
}
