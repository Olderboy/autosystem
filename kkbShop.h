#ifndef _KKB_SHOP_H_
#define _KKB_SHOP_H_
#include <string>
#include<queue>

class kkbOrderInfo;
class kkbShop
{
private:
    std::queue<kkbOrderInfo*> _orders;
    const std::string _shopid;

public:
    kkbShop(char* name);
    ~kkbShop();

public:
    virtual void applyBMWOrder();
    virtual void applyBENZOrder();
    virtual void applyAUDIOrder();
    virtual void onOrderFinish(kkbOrderInfo* order);

    inline const std::string& id(){ return _shopid; }
};


#endif