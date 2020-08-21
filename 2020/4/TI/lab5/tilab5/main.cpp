#include <QCoreApplication>

#include <QTextCodec>
//cout << QString::fromUtf8("").toLocal8Bit().data();
#include <iostream>
#include <math.h>
#include <string>
#include <bitset>
#include <limits>
#include "logmatr.cpp"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <string> // подключаем строки
#include <fstream> // подключаем файлы

using namespace std;










int EOF_FLAG = 0;

void write_vector(const vector<short>& v)//вывод вектора бит
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i];
}

void read_vector(vector<short>& V, int m, FILE *f)// считываение вектора бит
{
    for (int i = 0; i < m; i++)
    {
        int c;
        c = fgetc(f);
        if (c == EOF){
            EOF_FLAG = 1;
            return;
        }
        V.push_back(c - '0');// приведение к int
    }
}

int invert_rand_bit(vector<short>& v)// инвертирование случайного бита
{
    srand(time(NULL));
    int k = rand() % v.size();
    v[k] = (v[k] + 1) % 2;
    return k;
}

int invert_k_bit(vector<short>& v, int k)//инвертирование к-ого бита
{
    v[k] = (v[k] + 1) % 2;
    return k;
}

int bin_to_dec(vector<short>& v)
{
    int i;
    int res = 0;
    for (i = 0; i < v.size() - 1; i++)
    {
        res |= (v[i] - '0') & 1;
        res <<= 1;
    }
    res |= (v[i] - '0') & 1;
    return res;
}

bool check_syndrome(const vector<short>& synd)// проверка синдрома
{
    for (int i = 0; i < synd.size(); i++)
        if (synd[i] == 1)
            return false;
    return true;
}

int check_for_errors(vector<short>& synd)//нахождение значения синдрома
{
    if (check_syndrome(synd))
        return -1;
    else
    {
        int error_num = bin_to_dec(synd);
        return error_num;
    }
}

vector<short> get_infoword(vector<short>& codeword)//получение информационного слова из кодового
{
    vector<short> infoword;
    int k = 1;
    for (int i = 0; i < codeword.size(); i++)
        if (i + 1 == k)
            k *= 2;
        else
            infoword.push_back(codeword[i]);
    return infoword;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
#ifdef Q_OS_WIN32
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("IBM 866"));
#endif

#ifdef Q_OS_LINUX
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
#endif
    int end_flag = 1;
    while (end_flag)
    {
        int m, n;
        int k = 0;
        cout << QString::fromUtf8("Введите количество проверочных бит r = ").toLocal8Bit().data();
        cin >> k;
        n = pow(2, k) - 1;
        m = n - k;
        cout << QString::fromUtf8("Количество проверочных бит r = ").toLocal8Bit().data() << k << QString::fromUtf8("\nдлина кодового слова n = ").toLocal8Bit().data() << n << QString::fromUtf8("\nдлина информационного слова k = ").toLocal8Bit().data() << m << endl << endl;
        CheckMatr chmatr(k, n);//проверочная матрица H
        chmatr.createCheckMatr();//Генерация проверочной матрицы H
        cout << QString::fromUtf8("Сгенерирована проверочная матрица H").toLocal8Bit().data() << k << "x" << n << endl;
        cout << chmatr << endl;;// вывод проверочной матрицы H
        GeneratorMatr genmatr(m, n);//порождающая матрица
        genmatr.createGeneratorMatr();//создание порождающей матрицы
        cout << QString::fromUtf8("Сгенерирована порождающая матрица G").toLocal8Bit().data() << m << "x" << n << endl;
        cout << genmatr << endl;;//вывод порождающей матрицы

        vector<short> infoword;//информационное слово
        int count = 0;
        ifstream file;
        file.open("file.txt");
        char s[1000],s2[1000];
        string s3="101010101011";
        strcpy(s,s3.c_str());
        cout << QString::fromUtf8("В файле хранится сообщение\n").toLocal8Bit().data() << s << endl;//вывод информационного слова на экран
        int len = strlen(s);//размер информационного слова
        int t = len / m;//кол во блоков информацинного слова
        cout << QString::fromUtf8("Длина сообщения ").toLocal8Bit().data() << len << endl;
        cout << QString::fromUtf8("Разобьем сообщения на блоки: ").toLocal8Bit().data() << endl;
        int count1 = 0;
        for (int i = 0; i < len; i++) {
            cout << s[i];
            s2[i]=s[i];
            count1++;
            if (count1 == m) {
                count1 = 0;
                cout << endl;
            }
        }

        cout << endl;
        if (len % m){
            cout << QString::fromUtf8("Длина сообщения не кратна длине информационного слова. Дополняем сообщение до ").toLocal8Bit().data() << (t + 1)*m << QString::fromUtf8(" символов.").toLocal8Bit().data() << endl;
            for (int i = 0; i < t; i++){
                s[len + i] = '0';
            }
            s[len + (len % m)] = '\0';
        }
        t = m - (len % m);
        int tr=t;
        cout << QString::fromUtf8("В начало выходного файла дописываем количество добавленных символов (").toLocal8Bit().data() << t << ")" << endl;
        char tmp[20],itog[256];
        for (int i = m-1; i >= 0; i--){
            tmp[i] = t % 2 + '0';
            t /= 2;
        }
       for (int i = 0; i <m; i++)
            itog[i]=tmp[i];
       int counter=0;
       for (int i = m; i <m+len; i++){
                itog[i]=s[counter];
                counter++;
       }
       for (int i = m+len; i <m+len+tr; i++)
            itog[i]='0';
       itog[m+len+tr]='\0';
      // cout << itog<<endl;
        //for (int i = m; i< (m+len-); i++)

        tmp[m] = '\0';
        cout << tmp << endl;
        cout << QString::fromUtf8("Кодируем поблочно содержимое файла.").toLocal8Bit().data() << endl;
        file.close();
        FILE* f = fopen("file_dop.txt", "w");
        //fprintf(f, "%s", tmp);
        fprintf(f, "%s", s);
        fclose(f);
        f = fopen("file_dop.txt", "r");
        cout << endl;
        while (!EOF_FLAG){// пока не конец файла
            count ++;
            cout << QString::fromUtf8("Читаем блок номер ").toLocal8Bit().data()<< count << "\n";
            infoword.clear();
            read_vector(infoword, m, f);
            if (infoword.size() < m){
                cout << QString::fromUtf8("Данные в файле кончились.\n").toLocal8Bit().data();
                break;
            }
            cout << QString::fromUtf8("Прочитано слово ").toLocal8Bit().data();
            write_vector(infoword);
            vector<short> codeword = infoword * genmatr;//создаем кодовое слово
            cout << endl;
            cout << QString::fromUtf8("Получаем кодовое слово по формуле c = i * G").toLocal8Bit().data() << endl;
            cout << QString::fromUtf8("Получено кодовое слово c = ").toLocal8Bit().data();
            write_vector(codeword);
            cout << endl;

            bool er_flag;
            vector<short> false_codeword = codeword;
            cout << QString::fromUtf8("Имитировать помеху при передаче (одиночная ошибка)? (0/1) ").toLocal8Bit().data(); cin >> er_flag;
            int error_num;
            if (er_flag) {
                error_num = invert_rand_bit(false_codeword);
                cout << QString::fromUtf8("Был инвертирован ").toLocal8Bit().data() << error_num + 1 << QString::fromUtf8("-й бит кодового слова.").toLocal8Bit().data() << endl;
            }

            cout << endl;
            cout << QString::fromUtf8("Принято кодовое слово: ").toLocal8Bit().data(); write_vector(false_codeword); cout << endl;
            CheckMatr chmatr_transp(k, n);
            chmatr_transp.transMatr();
            vector<short>syndrome;
            syndrome = false_codeword * chmatr_transp;// создание синдрома
            cout << endl;
            cout << QString::fromUtf8("Получаем синдром по формуле s = y * H").toLocal8Bit().data() << endl;
            cout << QString::fromUtf8("Синдром s = ").toLocal8Bit().data();
            write_vector(syndrome);
            cout << endl;
            error_num = check_for_errors(syndrome);
            if (error_num != -1)
            {
                cout << QString::fromUtf8("Обнаружена ошибка в ").toLocal8Bit().data() << error_num << QString::fromUtf8("-м бите. Инвертируем этот бит").toLocal8Bit().data() << endl;
                invert_k_bit(false_codeword, error_num - 1);
            }
            else cout << QString::fromUtf8("Синдром равен 0, ошибок не обнаружено").toLocal8Bit().data() << endl;

            vector<short> new_infoword = get_infoword(false_codeword);
            cout << QString::fromUtf8("Отбросив биты с номерами, равными степени 2, получим информационное слово ").toLocal8Bit().data();
            write_vector(new_infoword);
            cout << endl << endl;

        }
        fclose(f);
        cout << QString::fromUtf8("Принятое сообщение: ").toLocal8Bit().data()<<itog<<endl;
        cout<<QString::fromUtf8("Информационное слово полученное из принятого сообщения: ").toLocal8Bit().data()<<s2<<endl;
        cout << QString::fromUtf8("Повторить кодирование? (0/1): ").toLocal8Bit().data(); cin >> end_flag;
    }
    return a.exec();
}
