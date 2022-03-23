#ifndef _KKB_AUDI_H_
#define _KKB_AUDI_H_
#include "kkbCar.h"

class kkbAudi: public kkbCar {
private:

public:
    kkbAudi();
    ~kkbAudi();
    virtual void run() = 0;
    virtual void didi() = 0;
    virtual void assemble(const OrderInfo* orderinfo) = 0;
};

#endif