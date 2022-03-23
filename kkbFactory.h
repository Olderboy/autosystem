#ifndef _KKB_FACTORY_H_
#define _KKB_FACTORY_H_
#include <thread>
#include <mutex>
#include <map>
#include <queue>

#include "kkbIShopDelegate.h"
#include "kkbIBuilderDelegate.h"
#include "kkbIAutoTest.h"

class kkbCar;
class kkbBuilder;
struct kkbOrderInfo
{
    std::string shopid;//店铺ID
    std::string brand;//品牌
    std::string serial;//系列
    float engine;//引擎大小
    int seat;//座位数
    int wheel;//轮子数
    long color;//颜色
    kkbCar* car;//汽车对象

    static kkbOrderInfo* create(std::string shop, std::string brand, std::string serial, float engine, float seat, int wheel, long color){
        kkbOrderInfo* pInfo = new kkbOrderInfo();
        pInfo->shopid = shop;
        pInfo->brand = brand;
        pInfo->serial = serial;
        pInfo->engine = engine;
        pInfo->seat = seat;
        pInfo->wheel = wheel;
        pInfo->color = color;
        pInfo->car = nullptr;

        return pInfo;
    } 
};


class kkbFactory : public kkbIShopDelegate
                , public kkbIBuilderDelegate
                , public kkbIAutoTest
            
{
private:
    static kkbFactory* _instance;

    //店铺
    std::map<std::string, kkbShop*> _shops;
    //待处理订单
    std::queue<kkbOrderInfo*> _pendingOrders;
    //订单状态队列
    std::map<kkbOrderInfo*, bool> _orders;
    //builders
    std::vector<kkbBuilder*> _builders;

    std::thread* _thread;
    std::mutex _mtx;

public:
    kkbFactory(/* args */);
    ~kkbFactory();

public:
    static kkbFactory* instance();

    //启动工作线程
    void startWork();
    //停止工作线程
    void stopWork();
    //工作线程函数
    void workThread();

    //IShopDelegate
    void registerShop(kkbShop* shop);
    void addOrder(kkbOrderInfo* order);

    //IBuilder
    void onOrderFinished(kkbOrderInfo* order);
    void dealOrder();
    kkbBuilder* addBuilder(kkbOrderInfo* order);
    void reduceBuilder();
    kkbBuilder* getAvalideBuilder(kkbOrderInfo* order);

    //IAutoTest
    void testRun(kkbCar* car);
    void testDiDi(kkbCar* car);
    bool testAll(kkbOrderInfo* order);
};


#endif