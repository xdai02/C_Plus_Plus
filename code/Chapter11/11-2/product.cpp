#include "product.h"

Product::Product(std::string name, int stock) {
    this->name = name;
    this->stock = stock;
}

void Product::purchase() {
    if (stock == 0) {
        throw OutOfStockException(name + " is out of stock.");
    }
    stock--;
}