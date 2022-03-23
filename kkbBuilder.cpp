#include "kkbBuilder.h"

kkbBuilder::kkbBuilder(/* args */):_currentOrder(nullptr)
{
    this->startWork();
}

kkbBuilder::~kkbBuilder()
{
    this->stopWork();
}

void kkbBuilder::applyOrder(OrderInfo *order) {
    this->_currentOrder = order;
}

void kkbBuilder::buildCar() {
    this->buildStart();
    this->buildProcess();
    this->buildFinish();
}

void kkbBuilder::startWork() {
    if (_thread) stopWork();
    _thread = new std::thread(&kkbBuilder::workThread, this);
}

void kkbBuilder::stopWork() {
    if (_thread) {
        _thread->join();
        delete _thread;
        _thread = nullptr;
    }
}
void kkbBuilder::workThread() {
    if (_currentOrder && _workState == S_WAIT) {
        _workState = S_WORK;
        _mtx.lock();
        this->buildCar();
        _mtx.unlock();
    } else {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

