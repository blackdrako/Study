#include <QCoreApplication>

#include <iostream>
#include <fstream>
#include <optimal_code.h>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication applications(argc, argv);
#ifdef Q_OS_WIN32
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("IBM 866"));
#endif

#ifdef Q_OS_LINUX
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
#endif

    int alphabet_size,block_size;
    cout << QString::fromUtf8("Введите размер алфавита - ").toLocal8Bit().data();
    cin >> alphabet_size;

    Alphabet a(alphabet_size);
    a.read();

    string word = "BBCCCAADCACCDCEDAEEA";
    //cout<<"Введите слово для кодирования - ").toLocal8Bit().data();
    //cin>>word;

    char coding_cycle = '1';
    while(coding_cycle!='0'){
        cout << QString::fromUtf8("Введите размер блока - ").toLocal8Bit().data();
        cin >> block_size;
        Alphabet b=a.build_nsized_Alphabet(block_size);

        int code_type;
        cout << QString::fromUtf8("Выберите способ кодирования (1 - Шеннон-Фано, 2 - Хаффман) - ").toLocal8Bit().data();
        cin >> code_type;

        a.build_code_arr(code_type);
        b.build_code_arr(code_type);

        a.print_codes();
        b.print_codes();

        cout << endl;
        cout << QString::fromUtf8("Исходное слово - ").toLocal8Bit().data();
        for(int i=0,size = word.length();i<size;){
            if(size-i>=block_size){
                cout << word.substr(i,block_size) << " ";
                i+=block_size;
            }
            else{
                cout << word.substr(i,size-i);
                i+=size-i;
            };
        };
        cout << endl;
        cout << endl;

        string word_code_block = b.encode_text(word);

        cout << QString::fromUtf8("Длина блочного кода деленная на размер блока слова: ").toLocal8Bit().data() << word_code_block.length() << endl << endl;

        cout << QString::fromUtf8("Продолжить работу программы? (0 - закончить) - ").toLocal8Bit().data();
        cin >> coding_cycle;
};
    return applications.exec();
}
