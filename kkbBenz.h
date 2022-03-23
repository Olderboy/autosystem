#ifndef _KKB_Benz_H_
#define _KKB_Benz_H_
#include "kkbCar.h"

class kkbBenz : public kkbCar
{
private:
    /* data */
public:
    kkbBenz(/* args */);
    ~kkbBenz();

    void assemble(const kkbOrderInfo* order) override;
    void run() override;
    void didi() override;
};


#endif