#ifndef _PRODUCT_H_
#define _PRODUCT_H_

#include <string>

class Product {
    protected:
    std::string name;
    double price;

    public:
    Product(std::string name, double price);
    std::string get_name();
    void set_name(std::string name);
    double get_price();
    void set_price(double price);
};

#endif