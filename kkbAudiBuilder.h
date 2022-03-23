#ifndef _KKB_AUDI_BUILDER_H_
#define _KKB_AUDI_BUILDER_H_
#include "kkbBuilder.h"

class kkbAudiBuilder : public kkbBuilder {

public:
    void buildStart();
    void buildProcess();
    void buildFinish();
};

#endif