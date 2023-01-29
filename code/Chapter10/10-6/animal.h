#ifndef _ANIMAL_H_
#define _ANIMAL_H_

#include <string>

class Animal {
    public:
    virtual std::string sound() = 0;
};

#endif