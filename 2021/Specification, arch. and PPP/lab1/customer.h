#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <check.h>

class customer
{
private:
    std::string nameCustomer;
    check customerCheck;
public:
    customer(std::string,check);

    void set_nameCustomer(std::string str);

    inline std::string get_nameCustomer(){return this->nameCustomer;}

    void write_check();

};

#endif // CUSTOMER_H
