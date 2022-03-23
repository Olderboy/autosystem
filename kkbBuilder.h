#ifndef _KKB_BUILDER_H_
#define _KKB_BUILDER_H_
#include <string>
#include<thread>
#include<mutex>

enum STATE{
    S_WAIT,
    S_WORK,
    S_SLEEP,
};

class kkbOrderInfo;
class kkbBuilder
{
protected:
    std::string _name;
    kkbOrderInfo* _currentOrder;

    STATE _workState;
    std::thread* _thread;
    std::mutex _mtx;

public:
    kkbBuilder(char* name);
    ~kkbBuilder();

    inline const std::string& name(){return _name;}

    virtual void applyOrder(kkbOrderInfo* order);
    virtual void buildCar();

    virtual void startWork();
    virtual void stopWork();
    virtual void workThread();

    virtual bool isValide() {return _workState == S_WAIT; }
    
public:
    virtual void buildStart() = 0;
    virtual void buildProcess() = 0;
    virtual void buildFinish() = 0;

};



#endif