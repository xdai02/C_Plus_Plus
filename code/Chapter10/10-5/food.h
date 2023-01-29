#ifndef _FOOG_H_
#define _FOOD_H_

#include <iostream>
#include <string>
#include "product.h"

class Food : public Product {
    private:
    int calories;

    public:
    Food(std::string name, double price, int calories);
    int get_calories();
    void set_calories(int calories);
    friend std::ostream& operator<<(std::ostream& os,
                                    const Food& food);
};

#endif