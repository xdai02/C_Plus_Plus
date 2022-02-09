#ifndef _ENGLISH_H_
#define _ENGLISH_H_

#include "language.h"
#include <string>

class English : public Language {
public:
    English(std::string content = "");
    virtual void translate() override;

private:
    std::string content;
};

#endif