#include "drink.h"

Drink::Drink(std::string name, double price, std::string size)
    : Product(name, price) {
    this->size = size;
}

std::string Drink::get_size() {
    return size;
}

void Drink::set_size(std::string size) {
    this->size = size;
}

std::ostream& operator<<(std::ostream& os, const Drink& drink) {
    os << "Drink: " << drink.name
       <<" ($" << drink.price << ") "
       << drink.size;
    return os;
}