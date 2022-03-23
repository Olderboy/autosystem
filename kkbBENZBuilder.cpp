#include "kkbBENZBuilder.h"
#include <iostream>
#include "kkbFactory.h"
#include "kkbBenz.h"
kkbBENZBuilder::kkbBENZBuilder(/* args */):kkbBuilder("BENZ")
{

}

kkbBENZBuilder::~kkbBENZBuilder()
{

}

void kkbBENZBuilder::buildStart(){
    std::cout << "BENZ汽车制造开始！" << _currentOrder->shopid;
    std::cout << " - " << _currentOrder->brand;
    std::cout << " - " << _currentOrder->serial << std::endl;
}

void kkbBENZBuilder::buildProcess(){
    kkbBenz* car = new kkbBenz();
    _currentOrder->car = car;
    car->assemble(_currentOrder);
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    
}

void kkbBENZBuilder::buildFinish(){
    std::cout << "BENZ汽车制造完成" << std::endl;
    kkbFactory::instance()->onOrderFinished(_currentOrder);

    _workState = S_WAIT;
    _currentOrder = nullptr;
}


