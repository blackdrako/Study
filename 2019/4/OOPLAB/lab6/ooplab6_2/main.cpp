#include <QCoreApplication>

#include <QTextCodec>
//cout << QString::fromUtf8("").toLocal8Bit().data();

//Один поток удаляет лишние пробелы в строке, а другой подсчитывает
//количество слов в тексте. Произвести синхронный вывод при каждой
//итерации. Показать выполнение работы программы в синхронном и
//асинхронном режимах.
#include <iostream>
#include <math.h>
#include <time.h>
#include <windows.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <QThread>
using namespace std;

class Thread {
private:
    CONST HANDLE hMutex;
    bool sync;
    string &str;
    int n[2];
public:
    void start_thread(Thread&);
    virtual void func() = 0;
    Thread(CONST HANDLE hMutex, bool sync, std::string& ) : hMutex(hMutex), sync(sync), str(str) {};
    void lock_mutex() { WaitForSingleObject(this->hMutex, INFINITE); }
    void unlock_mutex() { ReleaseMutex(this->hMutex); }
    bool get_sync() { return this->sync; }
    string  &get_str() { return this->str; }
};

DWORD WINAPI start_thread(CONST LPVOID lpParam) {
    ((Thread*)lpParam)->func();
    ExitThread(0);
}

class WordCounter : public Thread {
    unsigned &count_of_word;
public:
    void func();
    WordCounter(CONST HANDLE hMutex, bool sync,unsigned &count_of_word, std::string& str) : Thread(hMutex, sync, str),count_of_word(count_of_word) {};
};

class SpaceEraser : public Thread {
public:
    void func();
    SpaceEraser(CONST HANDLE hMutex, bool sync, std::string& str) : Thread(hMutex, sync, str) {};
};

class OutThread : public Thread {
    unsigned &count_of_word;
public:
    void func();
    OutThread(CONST HANDLE hMutex, bool sync,unsigned &count_of_word, std::string& str) : Thread(hMutex, sync, str),count_of_word(count_of_word) {};
};

 void SpaceEraser::func(){
    for(unsigned i=1;i<get_str().size();i++){
        if(get_sync()) lock_mutex();
            if(get_str()[i]==' '){
                if(get_str()[i-1]==' '){
                    get_str().erase(i,1);
                };
            };
    };
};

int get_word(string &str,int &current_char){
    int char_in_word=0;
    while((current_char<str.size())&&(str[current_char]!=' ')){
        current_char++;
        char_in_word++;
    }
    return char_in_word;
};

void WordCounter::func(){

    while(true){
        if(get_sync()) lock_mutex();
            count_of_word=0;
            int current_char=0;
            while(current_char<get_str().size()){
                if(get_word(get_str(),current_char)>0) count_of_word++;
                current_char++;
            };
        if(get_sync()) unlock_mutex();
    };
};

void OutThread::func(){
    while(true){
        this->lock_mutex();
        cout<<endl<<get_str()<<endl<<"Count of word - "<<count_of_word<<endl;
        this->unlock_mutex();
        Sleep(300);
    }
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
    string s="aaa bbb ccc";
    int sync_mode=0;
    unsigned count_of_word;

    CONST HANDLE Mutex = CreateMutex(NULL, FALSE, NULL);
    HANDLE hThreads[3];

    WordCounter th1(Mutex,sync_mode,ref(count_of_word),ref(s));
    SpaceEraser th2(Mutex,sync_mode,ref(s));
    OutThread th3(Mutex,sync_mode,ref(count_of_word),ref(s));

    hThreads[0] = CreateThread(NULL, 0, &start_thread, &th1, 0, NULL);
    hThreads[1] = CreateThread(NULL, 0, &start_thread, &th2, 0, NULL);
    hThreads[2] = CreateThread(NULL, 0, &start_thread, &th3, 0, NULL);

    WaitForMultipleObjects(3, hThreads, TRUE, INFINITE);

    CloseHandle(hThreads[0]);
    CloseHandle(hThreads[1]);
    CloseHandle(hThreads[2]);

    CloseHandle(Mutex);
    ExitProcess(0);
    return a.exec();
}
