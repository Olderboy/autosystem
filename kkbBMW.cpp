#include "kkbBMW.h"
#include <iostream>
#include "kkbFactory.h"
#include <ctime>

kkbBMW::kkbBMW(/* args */)
{
}

kkbBMW::~kkbBMW()
{
}

void kkbBMW::assemble(const kkbOrderInfo* order){
    this->name = order->brand + " " + order->serial;
    this->color = order->color;
    this->engine = order->engine;
    this->wheel = order->wheel;
    this->seat = order->seat;
    time_t now = time(0);
    this->date = ctime(&now);
}

void kkbBMW::run() {
    std::cout << "BMW Is Running" << std::endl;
}

void kkbBMW::didi() {
    std::cout << "BMW Is DIDI" << std::endl;
}