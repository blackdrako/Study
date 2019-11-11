#include "filmlibrary.h"
void filmbib::list_idFilm(){
    unsigned i = 0;
    while(i<m_bib.n_bib){
        cout << "Name film:";
        qDebug() << m_bib.f[i].name;
        cout << "ID film:" << m_bib.f[i].pos << endl;
        cout << "\n";
        i++;
    }
}

void filmbib::add_in_fav(){
    unsigned y_pos;
    list_idFilm();
    cout << "Read ID film" << endl;
    cin >> y_pos;
    //Временный буффер
    filmbib temp;
    temp.m_bib.n_bib = m_bib.n_bib;
    temp.fav_bib.n_bib = fav_bib.n_bib;
    temp.m_bib.f = new film[temp.m_bib.n_bib];
    temp.fav_bib.f = new film[temp.fav_bib.n_bib];
    temp.m_bib.f = m_bib.f;
    temp.fav_bib.f = fav_bib.f;

    //Перевыделения памяти
    m_bib.n_bib--;
    fav_bib.n_bib++;
    m_bib.f = new film[m_bib.n_bib];
    fav_bib.f = new film[fav_bib.n_bib];

    for (unsigned i = 0; i < temp.fav_bib.n_bib; i++) {
        fav_bib.f[i] = temp.fav_bib.f[i];
    }

    unsigned i_id=0;
    for (unsigned i = 0;i<temp.m_bib.n_bib;i++) {
        if(y_pos!=temp.m_bib.f[i].pos){
            m_bib.f[i_id] = temp.m_bib.f[i];
            m_bib.f[i_id].pos = i_id;
            i_id++;
        }
    }

    fav_bib.f[fav_bib.n_bib-1] = temp.m_bib.f[y_pos];
}

void filmbib::write_films(){
    cout << "Films" << endl;
    for (unsigned n=0;n<m_bib.n_bib;n++) {
        cout << "Name:";
        qDebug() << m_bib.f[n].name;
        cout << "Doc:";
        qDebug() << m_bib.f[n].gen_info.doc;
        cout << "Rate:" << m_bib.f[n].gen_info.rate << "   " << "MRate:" << m_bib.f[n].ex_info.y_rate;
        cout << endl;
    }
    cout << endl;
    cout << "Fav-Films" << endl;
    for (unsigned n=0;n<fav_bib.n_bib;n++) {
        cout << "Name:";
        qDebug() << fav_bib.f[n].name;
        cout << "Doc:";
        qDebug() << fav_bib.f[n].gen_info.doc;
        cout << "Rate:" << fav_bib.f[n].gen_info.rate << "   " << "MRate:" << fav_bib.f[n].ex_info.y_rate;
        cout << endl;
    }
}

void filmbib::add_film(){

    //Переменная для сохранение данных
    filmbib temp;
    temp.m_bib.n_bib = m_bib.n_bib;
    temp.m_bib.f = new film[temp.m_bib.n_bib];
    temp.m_bib.f = m_bib.f;

    //Новая память
    m_bib.n_bib++;
    m_bib.f = new film[m_bib.n_bib];

    //Обмен
    for (unsigned i = 0; i<temp.m_bib.n_bib;i++) {
        m_bib.f[i] = temp.m_bib.f[i];
    }

    //Добавление нового фильмы
    cout << "Read name new film:";
    char str[255];
    cin >> str;
    m_bib.f[m_bib.n_bib-1].name=str;
    cout << "Read doc:";
    cin >> str;
    m_bib.f[m_bib.n_bib-1].gen_info.doc = str;
    int rate;
    cout << "Read rate:";
    cin >> rate;
    m_bib.f[m_bib.n_bib-1].gen_info.rate = rate;
    cout << "Read mrate:";
    cin >> rate;
    m_bib.f[m_bib.n_bib-1].ex_info.y_rate = rate;
    m_bib.f[m_bib.n_bib-1].pos = m_bib.n_bib - 1;
}

