#include "check.h"

check::check()
{
    this->fullPrice = 0;
}

void check::add_listCheckProduct(product p){
    this->listCheckProduct.push_back(p);
    this->fullPrice = this->fullPrice + p.get_priceProduct();
}

void check::write_checkProduct(){
    std::cout << "NAME:PRICE" << std::endl;
    for (product n : this->listCheckProduct){
        std::cout << n.get_nameProduct() << ":" << n.get_priceProduct() << std::endl;
    }
    std::cout << "FULL PRICE:" << this->fullPrice << std::endl;
}
