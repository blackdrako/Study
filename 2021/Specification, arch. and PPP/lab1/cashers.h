#ifndef CASHERS_H
#define CASHERS_H
#include <check.h>
#include <queue>
#include <customer.h>
#include <string.h>

class cashers
{
private:
    std::string nameCashers;
    std::queue<customer> queueCustomer;
public:
    cashers();

    void set_nameCashers(std::string str);

    inline std::string get_nameCashers();

    void add_customerINCashers(customer);

    void kill_customerINCashers();
};

#endif // CASHERS_H
