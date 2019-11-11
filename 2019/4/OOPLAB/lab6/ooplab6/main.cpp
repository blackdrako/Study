#include <QCoreApplication>
#include <iostream>
#include <QTextCodec>

//Один поток генерирует входные данные для функции, F=(sin(x)+exp(2x))/tg(x) а другой поток вычисляет значение этой функции.
//Произвести синхронный вывод при каждой итерации. Показать выполнение работы программы в синхронном и асинхронном режимах.
#include <thread>
#include <mutex>
#include <math.h>
#include <time.h>
#include <unistd.h>
using namespace std;

class Thread{
    double &data;
    virtual void func() = 0;
    virtual void func(mutex &m) = 0;
public:
    Thread(double &data):data(data){};
    double get_data();
    void set_data(double new_data);
    void operator()();
    void operator()(mutex &m);
};

class GenData:public Thread{
    void func();
    void func(mutex &m);
public:
    GenData(double &data):Thread(data){
        srand(time(NULL));
    };
};

class ComputeData:public Thread{
    void func();
    void func(mutex &m);
    double &result;
public:
    ComputeData(double &data,double &result):Thread(data),result(result){};
    double get_result();
};

class OutputData:public Thread{
    double &result;
    void func();
    void func(mutex &m);
public:
    OutputData(double &data,double &result):Thread(data),result(result){};
};

double Thread::get_data(){
    return this->data;
};

void Thread::set_data(double new_data){
    this->data=new_data;
};
void Thread::operator()(){
    return this->func();
};

void Thread::operator()(mutex &m){
    return this->func(m);
};

void GenData::func(){
    while(true){
        set_data((double)rand());
    }
};

void GenData::func(mutex &m){
    while(true){
        m.lock();
            set_data((double)rand());
        m.unlock();
    }
};

void ComputeData::func(){
    while(true){
        result=(sin(get_data())+exp(2*get_data()))/tan(get_data());
    }
};

void ComputeData::func(mutex &m){
    while(true){
        m.lock();
            result=(sin(get_data())+exp(2*get_data()))/tan(get_data());
        m.unlock();
    }
};

void OutputData::func(){
    while(true){
        cout<<"X = "<<get_data()<<"; f(X) = "<<result<<"; TRUE f(x) = "<<(sin(get_data())+exp(2*get_data()))/tan(get_data())<<endl;
        usleep(1000000);
    };
};

void OutputData::func(mutex &m){
    while(true){
        m.lock();
            cout<<"X = "<<get_data()<<"; f(X) = "<<result<<"; TRUE f(x) = "<<(sin(get_data())+exp(2*get_data()))/tan(get_data())<<endl;
        m.unlock();
        usleep(1000000);
    };
};
//cout << QString::fromUtf8("").toLocal8Bit().data();
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
#ifdef Q_OS_WIN32
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("IBM 866"));
#endif

#ifdef Q_OS_LINUX
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
#endif
    bool sync_mode=false;
    double data=0,result=0;

    GenData thread_1(data);
    ComputeData thread_2(data,result);
    OutputData thread_3(data,result);

    cout<<"1 - sync, 0 - async"<<endl;
    cin>>sync_mode;

    if(sync_mode){
        mutex m;
        thread th_gen(thread_1,ref(m));
        thread th_calc(thread_2,ref(m));
        thread th_out(thread_3,ref(m));
        th_gen.detach();
        th_calc.detach();
        th_out.join();
    }
    else{
        thread th_gen(thread_1);
        thread th_calc(thread_2);
        thread th_out(thread_3);
        th_gen.detach();
        th_calc.detach();
        th_out.join();
    };
    return a.exec();
}
