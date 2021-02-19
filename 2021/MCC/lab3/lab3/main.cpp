#include <QCoreApplication>

#include <QTextCodec>
//cout << QString::fromUtf8("").toLocal8Bit().data();
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

namespace sortAlg {
    template <typename Item>
    void exch(Item &A, Item &B)
    {
        Item t = A; A = B; B = t;
    }

    template <typename Item>
    void compexch(Item &A, Item &B)
    {
        if (B < A) exch(A, B);
    }

    template <typename Item>
    void insertion_sort(Item a[], int L, int R)
    {
        for(int i = R; i > L; i--)
            compexch(a[i - 1], a[i]);

        for (int i = L + 2; i <= R; i++)
        {
            int j = i;
            Item cur = a[j];
            while (a[j - 1] > cur)
            {
                a[j] = a[j - 1];
                j--;
            }
            a[j] = cur;
        }
    }
}

namespace seachrAlg {

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
    sortAlg::insertion_sort();
    return a.exec();
}
