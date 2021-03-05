#include <QCoreApplication>
#include <QTextCodec>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <random>
#include <assert.h>
using namespace std;

template <typename Item>
void Write(vector<Item> A){
    for (size_t i = 0;i < A.size(); i++) {
        cout << "A[" << i << "]:" << A[i] << endl;
    }
}

//Улучшенная сортировка обменом 1
template <typename Item>
void extraSortSwap1(vector<Item> &A)
{
    bool flag = false;
    for (size_t i = 0; i < A.size()-1; i++) {
        for (size_t j = (A.size()-1); j > i; j--) {
            if(A[j-1] > A[j]){
                Item t = A[j-1];
                A[j-1] = A[j];
                A[j] = t;
                flag = false;
            } else {
                flag = true;
            }
        }
        if(flag == true)
            return;
    }
}

//Быстрый линейный поиск
template <typename Item>
int speedLinerSearch(vector<Item> A,Item need){
    A.push_back(need);
    size_t i = 0;
    while (A[i]!=need) {
        i++;
    }
    A.pop_back();
    if(i != A.size() ){
        return static_cast<int>(i);
    }
    return -1;
}


template <typename Item>
void RandomGenerateVectorItem(vector<Item> &A){
    Item buffer;
    srand(time(0));
    for (size_t i = 0; i < A.size(); i++) {
        buffer = 1 + rand() % 60;
        A[i] = buffer;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    vector<int> A(20);
    RandomGenerateVectorItem(A);
    Write(A);
    int p;
    cin >> p;
    cout << "ID elementa search:" << speedLinerSearch(A,p) << endl;
    cout << "Sort vector:" << endl;
    extraSortSwap1(A);
    Write(A);
    return a.exec();
}
