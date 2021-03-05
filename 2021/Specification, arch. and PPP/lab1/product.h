#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
#include <iostream>

class product
{
private:
    std::string nameProduct;
    long double priceProduct;
public:
    product(std::string name,long double price);
    ~product();

    void set_nameProduct(std::string str);
    void set_priceProduct(long double price);

    inline std::string get_nameProduct(){return this->nameProduct;}
    inline long double get_priceProduct(){return this->priceProduct;}

    void write_full_infoProduct();
};

#endif // PRODUCT_H
