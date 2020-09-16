#include <QCoreApplication>
#include <QTextCodec>
#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <Windows.h>
using namespace std;
#undef max
#define PAUSE 500

const int OFFSET = ('a' - 'A');

class Thread {
private:
    CONST HANDLE hMutex;
    bool sync;
    string& text;
public:
    friend void start_thread(Thread&);
    virtual void body() = 0;
    Thread(CONST HANDLE hMutex, bool sync, string& text) : hMutex(hMutex), sync(sync), text(text) {};
    void lock_mutex() { WaitForSingleObject(this->hMutex, INFINITE); }
    void unlock_mutex() { ReleaseMutex(this->hMutex); }
    bool get_sync() { return this->sync; }
    string& get_text() { return this->text; }
};

class UpThread : public Thread {
public:
    void body();
    UpThread(CONST HANDLE hMutex, bool sync, string& text) : Thread(hMutex, sync, text) {};
};


class DownThread : public Thread {
public:
    void body();
    DownThread(CONST HANDLE hMutex, bool sync, string& text) : Thread(hMutex, sync, text) {};
};


class OutThread : public Thread {
    void body();
public:
    OutThread(CONST HANDLE hMutex, bool sync, string& text) : Thread(hMutex, sync, text) {};
};


void UpThread::body() {
    while (1) {
        if (this->get_sync()) this->lock_mutex();
        int rand_number = rand() % this->get_text().size();
        if (this->get_text()[rand_number] > 'Z') {
            this->get_text()[rand_number] -= OFFSET;
        }
        if (this->get_sync()) this->unlock_mutex();
        Sleep(PAUSE);
    }
}


void DownThread::body() {
    while (1) {
        if (this->get_sync()) this->lock_mutex();
        int rand_number = rand() % this->get_text().size();
        if (this->get_text()[rand_number] < 'a'){
            this->get_text()[rand_number] += OFFSET;
        }
        if (this->get_sync()) this->unlock_mutex();
        Sleep(PAUSE);
    }
}

void OutThread::body() {
    while (1)
    {
        this->lock_mutex();
        cout << endl;
        cout << this->get_text();
        cout << endl;
        this->unlock_mutex();
        Sleep(PAUSE);
    }
}






DWORD WINAPI start_thread(CONST LPVOID lpParam) {
    ((Thread*)lpParam)->body();
    ExitThread(0);
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
    srand(time(nullptr));

    string text;

    int answer;
    do {
        cout << QString::fromUtf8("Работа в синхронном или асинхронном режиме?\n1-синхронный, 2 - асинхронный: ").toLocal8Bit().data();
        cin >> answer;
    } while (answer != 1 && answer != 2);

    bool sync = answer == 1;

    cout << QString::fromUtf8("Введите текст: ").toLocal8Bit().data();
    cin.clear();
    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    getline(cin, text);

    CONST HANDLE hMutex = CreateMutex(NULL, FALSE, NULL);


    UpThread	 ut(hMutex, sync, ref(text));
    DownThread	 dt(hMutex, sync, ref(text));
    OutThread     ot(hMutex, sync, ref(text));

    HANDLE hThreads[3];
    hThreads[0] = CreateThread(NULL, 0, &start_thread, &ut, 0, NULL);
    hThreads[1] = CreateThread(NULL, 0, &start_thread, &dt, 0, NULL);
    hThreads[2] = CreateThread(NULL, 0, &start_thread, &ot, 0, NULL);

    WaitForMultipleObjects(3, hThreads, TRUE, INFINITE);

    CloseHandle(hThreads[0]);
    CloseHandle(hThreads[1]);
    CloseHandle(hThreads[2]);

    CloseHandle(hMutex);
    ExitProcess(0);

    return a.exec();
}
