#include <iostream>
#include "food.h"
#include "drink.h"

using namespace std;

int main() {
    Food food("Cheeseburger", 5.45, 302);
    Drink drink("Coke", 3.7, "Large");

    cout << food << endl;
    cout << drink << endl;

    return 0;
}