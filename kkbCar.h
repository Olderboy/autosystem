#ifndef _KKB_CAR_H_
#define _KKB_CAR_H_
#include <string>
#include <map>
#include <iostream>
#include "kkbFactory.h"

class kkbCar
{
protected:
    std::string name;//名称
    unsigned long color;//颜色
    float engine;//发动机排量
    int wheel;//轮子
    int seat;//座位
    long date;//生产日期
    
public:
    kkbCar();
    virtual ~kkbCar();

    virtual void details();
    virtual void run() = 0;
    virtual void didi() = 0;
    virtual void assemble(const OrderInfo* orderinfo) = 0;

};




#endif