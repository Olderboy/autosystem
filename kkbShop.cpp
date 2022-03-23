#include "kkbShop.h"
#include "kkbFactory.h"
#include <iostream>

kkbShop::kkbShop(char* name):_shopid(name)
{
    kkbFactory::instance()->registerShop(this);
}

kkbShop::~kkbShop()
{
}

void kkbShop::applyBMWOrder(){
    kkbOrderInfo* order = kkbOrderInfo::create(_shopid, "BMW", "740", 8.0f, 4, 4, 0xffffff);
    this->_orders.push(order);
    kkbFactory::instance()->addOrder(order);
}

void kkbShop::applyBENZOrder(){
    kkbOrderInfo* order = kkbOrderInfo::create(_shopid, "BENZ", "s500", 12.0f, 4, 4, 0xffffff);
    this->_orders.push(order);
    kkbFactory::instance()->addOrder(order);
}

void kkbShop::applyAUDIOrder(){
    kkbOrderInfo* order = kkbOrderInfo::create(_shopid, "AUDI", "A6L", 3.0f, 5, 5, 0xffffff);
    this->_orders.push(order);
    kkbFactory::instance()->addOrder(order);
}

void kkbShop::onOrderFinish(kkbOrderInfo* order){
    std::cout << "Order Finished [ car : " << order->car << " shop : " << this->_shopid << "]\n";
}