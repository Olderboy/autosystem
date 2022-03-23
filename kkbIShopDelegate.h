#ifndef _KKB_ISHOP_DELEGATE_H_
#define _KKB_ISHOP_DELEGATE_H_


class kkbIShopDelegate
{
public:
    virtual void registerShop(kkbShop* shop) = 0;
    virtual void addOrder(OrderInfo *order) = 0;
};

#endif