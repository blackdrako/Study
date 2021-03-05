#include "customer.h"

customer::customer(std::string str,check c)
{
    this->nameCustomer = str;
    this->customerCheck = c;
}

void customer::set_nameCustomer(std::string str){
    this->nameCustomer = str;
}

void customer::write_check(){

}
