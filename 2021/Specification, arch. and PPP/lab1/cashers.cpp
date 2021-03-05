#include "cashers.h"

cashers::cashers(std::string str)
{
    this->nameCashers = str;
}

void cashers::set_nameCashers(std::string str){
    this->nameCashers = str;
}

void cashers::add_customerINCashers(customer c){
    this->queueCustomer.push(c);
}

void cashers::kill_customerINCashers(){
    this->queueCustomer;
}

void cashers::refactoringCustomer(){

}

cashers& cashers::operator=(const cashers &right){
    if (this == &right){
        return *this;
    }
    nameCashers = right.nameCashers;
    queueCustomer = right.queueCustomer;
    return *this;
}
