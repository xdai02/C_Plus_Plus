#ifndef _PRODUCT_H_
#define _PRODUCT_H_

#include <string>
#include "out_of_stock_exception.h"

class Product {
    private:
    std::string name;
    int stock;

    public:
    Product(std::string name, int stock);
    void purchase();
};

#endif