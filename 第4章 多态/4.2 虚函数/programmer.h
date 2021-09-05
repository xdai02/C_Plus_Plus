#ifndef _PROGRAMMER_H_
#define _PROGRAMMER_H_

#include <string>

class Programmer {
public:
    Programmer(std::string title = "programmer");
    virtual void work();
    
private:
    std::string title;
};

#endif