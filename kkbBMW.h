#ifndef _KKB_BMW_H_
#define _KKB_BMW_H_
#include "kkbCar.h"

class kkbBMW : public kkbCar
{
private:
    /* data */
public:
    kkbBMW(/* args */);
    ~kkbBMW();

    void assemble(const kkbOrderInfo* order) override;
    void run() override;
    void didi() override;
};


#endif