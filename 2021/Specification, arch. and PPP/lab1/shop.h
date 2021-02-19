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
    std::vector<cashers> shopCashers;
    std::list<product> listShopProduct;
public:
    shop();
    ~shop();

    //set
    void set_nameShop(std::string str);
    //get
    inline std::string get_nameShop();
};

#endif // SHOP_H
