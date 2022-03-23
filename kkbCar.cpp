#include "kkbCar.h"

kkbCar::kkbCar(std::string _name, unsigned long _color, float _engine,\
     long _date, int _wheel = 4, int _seat = 4) 
     : name(_name), color(_color), \
     engine(_engine), date(_date), wheel(_wheel), seat(_seat)
{
}

kkbCar::~kkbCar()
{
    
}

void kkbCar::details() {
     std::cout < name << "Product Details" << std::endl;
     std::cout << "color : " << color << std::endl;
     
}
