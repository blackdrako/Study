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
    ~check();

    void add_listCheckProduct(product);

    inline size_t get_SizeCheck(){return this->listCheckProduct.size();}
    inline long double get_fullPrice(){return this->fullPrice;}

    void write_checkProduct();
};

#endif // CHECK_H
