#include "kkbAudiBuilder.h"
#include "kkbAudi.h"

void  kkbAudiBuilder::buildStart() {
    std::cout << "start" << std::endl;
}


void kkbAudiBuilder::buildProcess() {
    kkbAudi* car = new kkbAudi();
    _currentOrder->car = car;
    car->assemble(_currentOrder);
}


void kkbAudiBuilder::buildFinish() {
    std::cout << "Finished" << std::endl;
    _workState = S_WAIT;
    _currentOrder = nullptr;
}