#ifndef _KKB_ISHOP_DELEGATE_H_
#define _KKB_ISHOP_DELEGATE_H_

class kkbShop;
class kkbOrderInfo;
class kkbIShopDelegate
{
public:
    virtual void registerShop(kkbShop* shop) = 0;
    virtual void addOrder(kkbOrderInfo* order) = 0;
};

#endif