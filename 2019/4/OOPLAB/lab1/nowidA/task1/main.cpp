#include <QCoreApplication>

#include <QTextCodec>

#include <iostream>
using namespace std;

#include <fstream>

/*а. B текстовом файле хранятся квадратные вещественные матрицы порядка n (n - const) по строкам.
 * Преобразовать файл, удалив из каждой матрицы первую строку и первый столбец.*/
//cout << QString::fromUtf8("").toLocal8Bit().data();

void creat_file(){
    ofstream file;
    file.open("test.txt");
    unsigned order;
    unsigned count_matr;
    cout << QString::fromUtf8("Введите порядок матрицы:").toLocal8Bit().data();
    cin >> order;
    cout << QString::fromUtf8("Введите количество матриц:").toLocal8Bit().data();
    cin >> count_matr;
    double number;
    file << order*order << endl;
    for (unsigned i=0;i<count_matr;i++) {
        for (unsigned j = 0; j<order*order;j++) {
            cin >> number;
            file << number << " ";
        }
        file << endl;
    }
    file.close();
}

void read_file(){
    ifstream infile("test.txt");
    ofstream outfile;
    outfile.open("data.txt");
    unsigned count;
    infile >> count;
    unsigned i=0;
    unsigned border = count/2;
    double *array = new double [count];
    while(1){
        infile >> array[i];
        if(infile.eof()==1){
            break;
        }
        i++;
        if(i == count){
            for(unsigned j=0;j<count;j++){
                if((j>border) || (j%border != 0)){
                    outfile << array[j] << " ";
                }
            }
            outfile << endl;
            i=0;
        }
    }
    infile.close();
    outfile.close();
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
    creat_file();
    read_file();
    return applications.exec();
}
