#ifndef _CAT_H_
#define _CAT_H_

#include "animal.h"

class Cat : public Animal {
    public:
    virtual std::string sound() override;
};

#endif