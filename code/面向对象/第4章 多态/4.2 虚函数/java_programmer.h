#ifndef _JAVA_PROGRAMMER_H_
#define _JAVA_PROGRAMMER_H_

#include "programmer.h"
#include <string>

class JavaProgrammer : public Programmer {
public:
    JavaProgrammer(std::string title = "Java Programmer");
    virtual void work() override;
};

#endif