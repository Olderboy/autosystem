#ifndef _KKB_IAUTO_TEST_H_
#define _KKB_IAUTO_TEST_H_

class kkbCar;
class OrderInfo;
class kkbIAutoTest {
public:
    virtual void testRun(kkbCar* car) = 0;
    virtual void testDiDi(kkbCar *car) = 0;
    virtual bool testAll(OrderInfo *order) = 0;

};

#endif