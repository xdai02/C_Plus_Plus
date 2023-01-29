#ifndef _DRINK_H_
#define _DRINK_H_

#include <iostream>
#include <string>
#include "product.h"

class Drink : public Product {
    private:
    std::string size;

    public:
    Drink(std::string name, double price, std::string size);
    std::string get_size();
    void set_size(std::string size);
    friend std::ostream& operator<<(std::ostream& os,
                                    const Drink& drink);
};

#endif