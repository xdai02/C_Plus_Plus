#include "product.h"

Product::Product(std::string name, double price) {
    this->name = name;
    this->price = price;
}

std::string Product::get_name() {
    return name;
}

void Product::set_name(std::string name) {
    this->name = name;
}

double Product::get_price() {
    return price;
}

void Product::set_price(double price) {
    this->price = price;
}