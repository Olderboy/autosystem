#include "kkbFactory.h"
#include <iostream>
#include "kkbShop.h"
#include "kkbCar.h"
#include "kkbBuilder.h"
#include "kkbBMWBuilder.h"
#include "kkbBENZBuilder.h"
#include "kkbAudiBuilder.h"

kkbFactory* kkbFactory::_instance = nullptr;
kkbFactory* kkbFactory::instance(){
    if(_instance == nullptr){
        _instance = new kkbFactory();
    }

    return _instance;
}

kkbFactory::kkbFactory():_thread(nullptr)
{
    this->startWork();
}

kkbFactory::~kkbFactory()
{
    this->stopWork();
    for(auto builder : _builders){
        delete builder;
    }
}

void kkbFactory::startWork(){
    _thread = new std::thread(&kkbFactory::workThread, this);

    _builders.push_back(new kkbAudiBuilder());
    // _builders.push_back(new kkbBENZBuilder());
    // _builders.push_back(new kkbBMWBuilder());
}

void kkbFactory::stopWork(){
    if(_thread){
        _thread->join();
        delete _thread;
        _thread = nullptr;
    }
}

//工作线程函数
void kkbFactory::workThread(){
    std::cout << "开始处理订单" << std::endl;

    while (true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        _mtx.lock();
        // std::cout << "处理订单！" << std::endl;        
        this->dealOrder();
        _mtx.unlock();
    }

}

void kkbFactory::registerShop(kkbShop* shop){
    _shops[shop->id()] = shop;
}

void kkbFactory::addOrder(kkbOrderInfo* order){
    _mtx.lock();
    _pendingOrders.push(order);
    _orders[order] = false;
    _mtx.unlock();
}


//IBuilder
void kkbFactory::onOrderFinished(kkbOrderInfo* order){
    auto orderData = _orders.find(order);
    if(orderData != _orders.end()){
        orderData->second = true;
    }

    if(this->testAll(order)){
        auto shop = _shops.find(order->shopid);
        if(shop != _shops.end()){
            shop->second->onOrderFinish(order);
        }
    }
}
void kkbFactory::dealOrder(){
    if(!_pendingOrders.empty()){
        auto order = _pendingOrders.front();
        //交给流水线处理
        std::cout << "待流水线处理, 订单数 = " << _pendingOrders.size() << std::endl;
        kkbBuilder* builder = this->getAvalideBuilder(order);
        if(builder){
            builder->applyOrder(order);
            _pendingOrders.pop();
        }else{
            std::cout << "没有可用Builder，当前订单数：" << _pendingOrders.size();
            std::cout << " 当前builder数：" << _builders.size() << std::endl;
        }
    }
}

kkbBuilder* kkbFactory::addBuilder(kkbOrderInfo* order){
    kkbBuilder* builder = nullptr;

    if(order->brand == "AUDI"){
        builder = new kkbAudiBuilder();
    }else if(order->brand == "BENZ"){
        builder = new kkbBENZBuilder();
    }else if(order->brand == "BMW"){
        builder = new kkbBMWBuilder();
    }

    this->_builders.push_back(builder);
    return builder;
}

void kkbFactory::reduceBuilder(){

}

kkbBuilder* kkbFactory::getAvalideBuilder(kkbOrderInfo* order){
    if(_builders.empty()){
        return this->addBuilder(order);
    }else{
        for(auto builder : _builders){
            if(builder->name() == order->brand){
                if(builder->isValide()){
                    return builder;
                }else{
                    std::cout << "当前流水线正在处理，请稍后！\n";
                }
            }else{
                return this->addBuilder(order);
            }
        }
    }

    return nullptr;
}

//IAutoTest
void kkbFactory::testRun(kkbCar* car){
    car->run();
}
void kkbFactory::testDiDi(kkbCar* car){
    car->didi();
}

bool kkbFactory::testAll(kkbOrderInfo* order){
    order->car->details();
    this->testRun(order->car);
    this->testDiDi(order->car);

    return true;
}