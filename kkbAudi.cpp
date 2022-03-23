#include "kkbAudi.h"

kkbAudi::kkbAudi(){

}


void kkbAudi::assemble(const OrderInfo *order) {
    this->name = order->brand;
    /*构造汽车对象的属性*/
}

void kkbAudi::run() {

    std::cout << "AUDI Is Run" << std::endl;
}

void kkbAudi::didi() {
    std::cout << "AUDI Is DIDI " << std::endl;
}