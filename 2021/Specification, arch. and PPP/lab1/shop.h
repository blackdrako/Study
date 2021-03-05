#ifndef SHOP_H
#define SHOP_H
#include <string>
#include <cashers.h>
#include <product.h>
#include <customer.h>
#include <vector>
#include <list>
class shop
{
private:
    std::string nameShop;
    cashers shopCashers;
    std::list<product> listShopProduct;
    unsigned int count_shopCashers;
public:
    shop(cashers c);
    ~shop();

    //set
    void set_nameShop(std::string str);
    //get
    inline std::string get_nameShop(){return this->nameShop;}

    void jobs_Shop();
};

#endif // SHOP_H
