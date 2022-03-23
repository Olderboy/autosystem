#ifndef _KKB_IBUILDER_DELEGATE_H_
#define _KKB_IBUILDER_DELEGATE_H_

class kkbBuilder;
class kkbOrderInfo;
class kkbIBuilderDelegate
{
public:
    //订单完成
    virtual void onOrderFinished(kkbOrderInfo* order) = 0;

    //处理订单
    virtual void dealOrder() = 0;

    //新增builder
    virtual kkbBuilder* addBuilder(kkbOrderInfo* order) = 0;

    //减少builder
    virtual void reduceBuilder() = 0;

    //可用builder
    virtual kkbBuilder* getAvalideBuilder(kkbOrderInfo* order) = 0;

};


#endif