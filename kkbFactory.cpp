#include "kkbFactory.h"
#include "kkbBuilder.h"

kkbFactory* kkbFactory::instance() {
    if (_instance == nullptr) {
        _instance = new kkbFactory();
    }
    return _instance;

}

kkbFactory::kkbFactory(/* args */)
{
}

kkbFactory::~kkbFactory()
{
}

void kkbFactory::startWork() {
    _thread = new std::thread(&kkbFactory::workThread, this);
}

void kkbFactory::stopWork() {
    if (_thread) {
        _thread->join();
        delete _thread;
        _thread = nullptr;
    }
}

void kkbFactory::workThread() {
    std::cout << "开始处理订单" << std::endl;

    while (true) 
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        _mtx.lock();
        std::cout << "处理订单！ " << std::endl;
        this->dealOrder();
        _mtx.unlock();
    }
}

void kkbFactory::dealOrder() {
    if (!_pendingOrders.empty()) {
        auto order = _pendingOrders.front();

        //交给流水线
        std::cout << "待流水线处理，订单数 = " << _pendingOrders.size() << std::endl;

    }
}

void kkbFactory::registerShop(kkbShop *shop) {
    _shops[shop->id()] = shop;
}

void kkbFactory::addOrder(OrderInfo *order) {
    _pendingOrders.push(order);
    _order_states[order] = false;
}

//IBuilder
void kkbFactory::onOderFinished(OrderInfo *order) {
    auto orderData = orders.find(order);
    if (order)
}
void kkbFactory::dealOrder() {
    if (!_pendingOrders.empty()) {

    }
}
void kkbFactory::addBuilder(OrderInfo *order) 
void kkbFactory::reduceBuilder()
kkbBuilder* kkbFactory::getAvalideBuilder(OrderInfo *order)

    //IAutoTest
void kkbFactory::testRun(kkbCar* car) 
void kkbFactory::testDiDi(kkbCar *car) 
bool kkbFactory::testAll(OrderInfo *order)
{
    order->car->details();


} 


