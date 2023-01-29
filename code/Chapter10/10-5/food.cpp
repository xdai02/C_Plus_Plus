#include "food.h"

Food::Food(std::string name, double price, int calories)
    : Product(name, price) {
    this->calories = calories;
}

int Food::get_calories() {
    return calories;
}

void Food::set_calories(int calories) {
    this->calories = calories;
}

std::ostream& operator<<(std::ostream& os, const Food& food) {
    os << "Food: " << food.name
       <<" ($" << food.price << ") "
       << food.calories;
    return os;
}