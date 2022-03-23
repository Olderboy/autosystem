#ifndef _KKB_AUTO_SYSTEM_H_
#define _KKB_AUTO_SYSTEM_H_
#include <thread>
#include <map>
#include <mutex>
#include <iostream>
#include "kkbIShopDelegate.h"
#include "kkbShop.h"
#include "kkbIBuilderDelegate.h"
#include "kkbIAutoTest.h"

class kkbCar;
struct OrderInfo
{
    std::string shopid; //店铺ID
    std::string brand; //品牌
    std::string serial; //系列
    float engine; //引擎
    float seat; //座位数
    int wheel;  //轮子
    long color; //颜色
    kkbCar *car; //汽车对象

    static OrderInfo * create(/*属性参数*/) {
        /*对Info进行构造*/
    }
};

class kkbFactory : public kkbIShopDelegate, 
                    public kkbIBuilderDelegate,
                    public kkbIAutoTest
{
private:
    static kkbFactory *_instance;
    std::thread *_thread;
    std::mutex _mtx;
    //店铺
    std::map<std::string, kkbShop*> _shops;
    //待处理订单
    std::queue<OrderInfo *> _pendingOrders;
    //存储订单状态
    std::map<OrderInfo*, bool> _order_states;
private:
    kkbFactory();
    ~kkbFactory();

public:
    //注册回调函数
    static kkbFactory *instance();

    void startWork();
    void stopWork();
    //工作线程函数
    void workThread();

    void dealOrder();

    //IShopDelegate
    void registerShop(kkbShop *shop);
    void addOrder(OrderInfo *order);

    //IBuilder
    virtual void onOderFinished(OrderInfo *order) = 0;
    virtual void dealOrder() = 0;
    virtual void addBuilder(OrderInfo *order) = 0;
    virtual void reduceBuilder() = 0;
    virtual kkbBuilder* getAvalideBuilder(OrderInfo *order) = 0;

    //IAutoTest
    virtual void testRun(kkbCar* car) = 0;
    virtual void testDiDi(kkbCar *car) = 0;
    virtual bool testAll(OrderInfo *order) = 0;

};



#endif