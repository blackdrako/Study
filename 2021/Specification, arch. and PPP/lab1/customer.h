#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <check.h>

class customer
{
private:
    std::string nameCustomer;
    check customerCheck;
public:
    customer();

    void set_nameCustomer(std::string str);

    inline std::string get_nameCustomer();

};

#endif // CUSTOMER_H
