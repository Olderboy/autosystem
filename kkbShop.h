#ifndef _KKB_SHOP_H_
#define _KKB_SHOP_H_
#include <string>
#include <queue>
#include "kkbFactory.h"

class kkbShop{
private:
    const std::string _shopid; 
    std::queue<kkbFactory *> _orders;
public:
    kkbShop(char *name);
    virtual ~kkbShop() {};

public:
    virtual void applyBMWOrder();
    virtual void applyBENZOrder();
    virtual void applyAUDIOrder();     

    void onOrderFinish(OrderInfo *order);

    inline const std::string& id(){return _shopid;}
};

#endif