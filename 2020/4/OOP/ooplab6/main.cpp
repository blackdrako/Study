#include <QCoreApplication>
#include <QTextCodec>
#include <mutex>
#include <thread>
#include <chrono>
#include <iostream>
#include <string>
#include <limits>
#include <windows.h>
#undef max
using namespace std;
class Thread {
private:
    mutex& m;
    bool sync;
    string& text;
    unsigned& count;
    virtual void body() = 0;
public:
    Thread(mutex& m, bool sync, string& text, unsigned& count) : m(m), sync(sync), text(text), count(count) {};
    void lock_mutex(){ this->m.lock(); }
    void unlock_mutex(){ this->m.unlock(); }
    bool get_sync(){ return this->sync; }
    string& get_text(){ return this->text; }
    unsigned get_count(){ return this->count; }
    void set_count(unsigned new_val){ this->count = new_val; }
    void operator()(){ this->body(); }
};

class CountThread : public Thread {
    void body();
public:
    CountThread(mutex& m, bool sync, string& text, unsigned& count) : Thread(m, sync, text, count) {};
};


class DelThread : public Thread {
    void body();
public:
    DelThread(mutex& m, bool sync, string& text, unsigned& count) : Thread(m, sync, text, count) {};
};


class OutThread : public Thread {
    void body();
public:
    OutThread(mutex& m, bool sync, string& text, unsigned& count) : Thread(m, sync, text, count) {};
};
void CountThread::body() {
    while (this -> get_count() != 1) {
        this->set_count(0);
        int state;
        state = 0;
        for (size_t i = 0; i < this->get_text().size(); i++) {
            if (this->get_text()[i] == ' ') {
                state = 0;
            }
            else if (state == 0) {
                state = 1;
                this->set_count(this->get_count()+1);
            }
        }
        this_thread::sleep_for(chrono::seconds(1));
    }
}
void DelThread::body() {
    size_t i = 0;
    while (i < this->get_text().size()) {
        if (this->get_text()[i] == ' ') {
            for (size_t j = i + 1; j < this->get_text().size(); j++) {
                this->get_text()[j - 1] = this->get_text()[j];
            }
            this->get_text().resize(this->get_text().size() - 1);
        }
        i++;
        this_thread::sleep_for(std::chrono::seconds(1));
    }
}
void OutThread::body() {
    while (1)
    {
        this->lock_mutex();
        cout << QString::fromUtf8("В тексте ").toLocal8Bit().data() << this->get_count() << QString::fromUtf8(" слов.").toLocal8Bit().data() << endl;
        cout << this->get_text() << endl;
        this->unlock_mutex();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    std::mutex m;
#ifdef Q_OS_WIN32
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("IBM 866"));
#endif

#ifdef Q_OS_LINUX
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
#endif
    string text;
    unsigned count;
    int answer;
    do {
        cout << QString::fromUtf8("Работа в синхронном или асинхронном режиме?\n1-синхронный, 2 - асинхронный: ").toLocal8Bit().data();
        cin >> answer;
    }while (answer != 1 && answer != 2);
    bool sync = answer == 1;
    cout << QString::fromUtf8("Введите текст: ").toLocal8Bit().data();
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, text);
    CountThread  ct(ref(m), sync, ref(text), ref(count));
    DelThread	 dt(ref(m), sync, ref(text), ref(count));
    OutThread    ot(ref(m), sync, ref(text), ref(count));
    thread th1(ct);  //1 поток
    thread th2(dt);  //2 поток
    thread th3(ot);  //поток вывода
    th1.detach();
    th2.detach();
    th3.join();
    return a.exec();
}
