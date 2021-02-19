#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>

class product
{
private:
    std::string nameProduct;
    long double priceProduct;
public:
    product();
    ~product();

    void set_nameProduct();
    void set_priceProduct();

    inline std::string get_nameProduct();
    inline long double get_priceProduct();

    void write_full_infoProduct();
};

#endif // PRODUCT_H
