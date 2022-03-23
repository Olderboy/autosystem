#ifndef _KKB_CAR_H_
#define _KKB_CAR_H_
#include<string>

class kkbOrderInfo;
class kkbCar
{
protected:
    std::string name;
    unsigned long color;
    float engine;
    int wheel;
    int seat;
    std::string date;//生产日期

public:
    kkbCar(/* args */);
    virtual ~kkbCar();

    virtual void assemble(const kkbOrderInfo* order) = 0;
    virtual void run() = 0;
    virtual void didi() = 0;
    virtual void details();
};


#endif