#include "product.h"

product::product(std::string name,long double price)
{
    this->nameProduct = name;
    this->priceProduct = price;
}

void product::set_nameProduct(std::string str){
    this->nameProduct = str;
}

void product::set_priceProduct(long double price){
    this->priceProduct = price;
}

void product::write_full_infoProduct(){
    std::cout << "Name product:" << this->nameProduct << std::endl;
    std::cout << "Price:" << this->priceProduct << std::endl;
}
