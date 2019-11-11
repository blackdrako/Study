#include "code.h"
using namespace std;

Symbol::Symbol(string symb,double prob):symb(symb),prob(prob){};
Symbol::Symbol(string symb,double prob,unsigned long pos):symb(symb),prob(prob),pos(pos){};

double Symbol::get_prob(){
    return this->prob;
};
string Symbol::get_symb(){
    return this->symb;
};
string Symbol::get_code(){
    return this->code;
};
unsigned long Symbol::get_pos(){
    return this->pos;
};
void Symbol::set_prob(double a){
    this->prob=a;
};
void Symbol::set_symb(string origin){
    this->symb=origin;
};
void Symbol::set_code(string code){
    this->code=code;
};
void Symbol::set_pos(unsigned long pos){
    this->pos=pos;
};

void Symbol::clear_code(){
    this->code.clear();
};

void Symbol::print(){
    cout<<"\""<<this -> symb<<"\" - "<<this->prob;
};

void Symbol::print_code(){
    cout<<"\""<<this -> symb<<"\" - "<<this->prob <<" - "<< this->code;
};

Alphabet::Alphabet(unsigned long size):size(size){};

void Alphabet::read(){
    cout<<"Введите алфавит размера "<<this->size<<" :\n";
    string t_symb;
    double t_prob;
    for(int i=0;i<this->size;i++){
        cin>>t_symb>>t_prob;
        this->arr.push_back(Symbol(t_symb,t_prob,i+1));
    };
};

unsigned long Alphabet::get_size(){
    return this->size;
};



void Alphabet::print(){
    cout<<endl;
    for(int i=0;i<this->size;i++){
        cout<<this->arr[i].get_pos()<<". ";
        this->arr[i].print();
        cout<<"\n";
    };
};

void Alphabet::print_codes(){
    cout<<endl;
    for(int i=0;i<this->size;i++){
        this->arr[i].print_code();
        cout<<endl;
    };
};

Symbol Alphabet::operator[](int i){
    return this->arr[i];
};


//Возвращает сумму вероятностей алфавита с элемента begin по end.
double Alphabet::sum_probs(int begin,int end){
    double t_sum=0;
    for(int i=begin;i<end;i++){
        t_sum+=this->arr[i].get_prob();
    }
    return t_sum;
};

//Шаг алгоритма Шеннона-Фано.
void Alphabet::code_filling_step(int begin,int end){
    //номер элемента делящий алфавит на 2 равные по вероятностям части.
    int mid=begin;
    //Флаг остановки
    bool flag=true;
    double min_diff,diff=1;
    //Пока разность вероятностей между левой и правой частью уменьшается сдвигает mid вправо.
    do{
        mid++;
        min_diff=diff;
        diff=fabs(this->sum_probs(begin,mid)-this->sum_probs(mid,end));
    }while(diff<min_diff);
    //Возвращаемся к середенному элементу
    mid--;
    //Условия остановки рекурсии: 1.Начальный элемент последовательности равен конечному 2.Между начальным и конечным элеметом нет других элементов.
    if((begin!=end)&&(abs(begin-end)!=1)){
        //Заполняем коды символов
        for(int i=begin;i<mid;i++){
            this->arr[i].set_code(this->arr[i].get_code()+"0");
        }
        for(int i=mid;i<end;i++){
            this->arr[i].set_code(this->arr[i].get_code()+"1");
        }
        //Применяем шаг алгоритма к правому и левому подмасиву относительно mid.
        this->code_filling_step(begin,mid);
        this->code_filling_step(mid,end);
    }
};

void Alphabet::build_code_arr(int mode){
    //Сортировка алфавита по убыванию.
    sort(this->arr.begin(),this->arr.end(), [](Symbol& a, Symbol& b){
            if(a.get_prob()==b.get_prob()){
                return a.get_pos()<b.get_pos();
            }
            return a.get_prob()>b.get_prob();
        });
    for(int i=0;i<this->size;i++){
        this->arr[i].clear_code();
    }
    //Заполнение кодов символов.
    switch (mode){
        case 0:
            this->code_filling_step(0,this->size);
        break;
        case 1:
            cout<<"НУ ТУТ КАРОЧЕ ХАФФМАН"<<endl;
        default:
            cout<<"НЕКОРЕКТНЫЙ ВЫБОР АЛГОРИТМА ПОСТРОЕНИЯ ОПТИМАЛЬНОГО КОДА"<<endl<<"ИСПРАВЬТЕ ИСХОДНЫЙ КОД"<<endl;
            exit(1);
        break;
    };
    //Сортировка в лексикографическом порядке.
    sort(this->arr.begin(),this->arr.end(), [](Symbol& a, Symbol& b){
        return a.get_pos()<b.get_pos();
    });
};

Alphabet Alphabet::build_nsized_Alphabet(int n){
    //Размер исходного алфавита.
    unsigned long m=this->size;
    //Создание результирующего алфавита размером m^n
    unsigned long new_size=(int)round(pow(m,n));
    Alphabet newAlphabet(new_size);
    //Временные переменные для формирования нового символа алфавита.
    string t_symb; double t_prob;
    //Массив индексов символов исходного алфавита, 0-ой элемент сигнальный для остановки алгоритма.
    int index_arr[n+1];
    for (int i=0;i<=n;i++) index_arr[i]=0;
    //Инициализация временной переменной вероятности символа.
    t_prob=1;
    //Переменная для записи номера символа в алфавите.
    int j=1;
    do{
        //Построение нового символа алфавита по массиву индексов.
        for(int i=1;i<=n;i++){
            int index = index_arr[i];
            t_symb+=this->arr[index].get_symb();
            t_prob*=this->arr[index].get_prob();
        };
        //Запись символа в новый алфавит
        newAlphabet.arr.push_back(Symbol(t_symb,t_prob,j));
        //Очистка временных переменных
        t_symb.clear();
        t_prob=1;

        int last=n; index_arr[last]++;
        //Перенос единицы при переполнении разрядов.
        while(index_arr[last]==m){
            index_arr[last]=0;
            index_arr[last-1]+=1;
            last--;
        };
        j++;
    } while(index_arr[0]==0);
    return newAlphabet;
};
