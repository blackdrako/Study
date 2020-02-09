#include "task.h"

task::task(int V)
{
    if(V==1)
    this->name_file = "test1.txt";
    else {
        this->name_file = "test2.txt";
    }
}

void task::check_date(){
    QDebug(this->name_file);
}
