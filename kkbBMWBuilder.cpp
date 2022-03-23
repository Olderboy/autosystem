#include "kkbBMWBuilder.h"
#include <iostream>
#include "kkbFactory.h"
#include "kkbBMW.h"
kkbBMWBuilder::kkbBMWBuilder(/* args */):kkbBuilder("BMW")
{

}

kkbBMWBuilder::~kkbBMWBuilder()
{

}

void kkbBMWBuilder::buildStart(){
    std::cout << "BMW汽车制造开始！" << _currentOrder->shopid;
    std::cout << " - " << _currentOrder->brand;
    std::cout << " - " << _currentOrder->serial << std::endl;
}

void kkbBMWBuilder::buildProcess(){
    kkbBMW* car = new kkbBMW();
    _currentOrder->car = car;
    car->assemble(_currentOrder);
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    
}

void kkbBMWBuilder::buildFinish(){
    std::cout << "BMW汽车制造完成" << std::endl;
    kkbFactory::instance()->onOrderFinished(_currentOrder);

    _workState = S_WAIT;
    _currentOrder = nullptr;
}


