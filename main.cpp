#include<iostream>
#include<string>
#include "kkbFactory.h"


int main(){

    OrderInfo info1{
        "bmw", "525Li", 3.0f, 5, 5, 0x00ff0000
    };
    OrderInfo info2{
        "bmw", "x5", 3.0f, 5, 5, 0x00ff9999
    };

    OrderInfo info3{
        "benz", "glc300", 2.0f, 5, 5, 0x000000ff
    };
    OrderInfo info4{
        "benz", "g550", 6.0f, 5, 5, 0x00ffffff
    };
    OrderInfo info5{
        "audi", "A6L", 3.0f, 4, 4, 0x0000000
    };
    OrderInfo info6{
        "audi", "Q5L", 2.0f, 4, 4, 0x009f9f9f
    };

    kkbFactory::instance()->startWork();
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    return 0;
}