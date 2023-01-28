#ifndef _CHINESE_H_
#define _CHINESE_H_

#include "language.h"
#include <string>

class Chinese : public Language {
public:
    Chinese(std::string content = "");
    virtual void translate() override;

private:
    std::string content;
};

#endif