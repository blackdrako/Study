#ifndef TASK_H
#define TASK_H
#include <QString>
#include <iostream>
#include <QtDebug>
using namespace std;
class task
{
private:
    QString name_file;
public:
    void check_date();
    task(int);
};

#endif // TASK_H
