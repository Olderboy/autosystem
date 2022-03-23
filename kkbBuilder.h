#ifndef _KKB_BUILDER_H_
#define _KKB_BUILDER_H_
#include <string>
#include "kkbCar.h"

enum STATE {
    S_WAIT,
    S_WORK
};

class kkbBuilder
{
protected:
    std::string _name;
    OrderInfo *_currentOrder;
    STATE _workState;
    std::thread* _thread;
    std::mutex _mtx;
public:
    kkbBuilder();
    ~kkbBuilder();

    virtual void applyOrder(OrderInfo *order);
    virtual void buildCar();

    virtual void startWork();
    virtual void stopWork();
    virtual void workThread();
    virtual void buildStart() = 0;
    virtual void buildProcess() = 0;
    virtual void buildFinish() = 0;

};


#endif