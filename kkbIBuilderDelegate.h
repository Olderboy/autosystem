#ifndef _KKB_IBUILDER_DELEGATE_H_
#define _KKB_IBUILDER_DELEGATE_H_


class OrderInfo;
class kkbBuilder;
class kkbIBuilderDelegate
{
public:
    //订单完成
    virtual void onOderFinished(OrderInfo *order) = 0;

    //处理订单
    virtual void dealOrder() = 0;

    //新增builder
    virtual void addBuilder(OrderInfo *order) = 0;

    //减少builder
    virtual void reduceBuilder() = 0;

    //可用builder
    virtual kkbBuilder* getAvalideBuilder(OrderInfo *order) = 0;

};

#endif