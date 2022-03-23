#include "kkbShop.h"

kkbShop::kkbShop(char *name):_shopid(name) {
    kkbFactory::instance()->registerShop(this);
}

kkbShop::~kkbShop() {

}

void kkbShop :: applyBMWOrder() {
    OrderInfo* order = OrderInfo::create();
    this->_orders.push(kkbFactory::instance());
    kkbFactory::instance()->addOrder(order);
} 

void  kkbShop :: applyBENZOrder() {

}

void kkbShop :: applyAUDIOrder() {

}

void kkbShop::onOrderFinish(OrderInfo *order) {

}