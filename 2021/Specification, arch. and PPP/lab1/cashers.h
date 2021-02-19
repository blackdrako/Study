#ifndef CASHERS_H
#define CASHERS_H
#include <check.h>
#include <queue>
#include <customer.h>

class cashers
{
private:
    std::queue<customer> queueCustomer;
public:
    cashers();
};

#endif // CASHERS_H
