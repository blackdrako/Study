#ifndef CHECK_H
#define CHECK_H
#include <product.h>
#include <list>

class check
{
private:
    std::list<product> listCheckProduct;
    long double fullPrice;
public:
    check();

    void add_listCheckProduct(product);

    inline long double get_fullPrice();
};

#endif // CHECK_H
