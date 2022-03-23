#ifndef _KKB_BENZ_BUILDER_H_
#define _KKB_BENZ_BUILDER_H_
#include "kkbBuilder.h"

class kkbBENZBuilder : public kkbBuilder
{
private:
    /* data */
public:
    kkbBENZBuilder(/* args */);
    ~kkbBENZBuilder();

public:
    void buildStart() override;
    void buildProcess() override;
    void buildFinish() override;
};


#endif