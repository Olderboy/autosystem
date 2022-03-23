#ifndef _KKB_BMW_H_
#define _KKB_BMW_H_
#include "kkbCar.h"

class kkbBMW : public kkbCar
{
private:
    std::string model;
public:
    kkbBMW(/* args */);
    ~kkbBMW();
};



#endif