#ifndef _KKB_BMW_BUILDER_H_
#define _KKB_BMW_BUILDER_H_
#include "kkbBuilder.h"

class kkbBMWBuilder : public kkbBuilder
{
private:
    /* data */
public:
    kkbBMWBuilder(/* args */);
    ~kkbBMWBuilder();

public:
    void buildStart() override;
    void buildProcess() override;
    void buildFinish() override;
};


#endif