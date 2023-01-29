#include <iostream>
#include "product.h"
#include "out_of_stock_exception.h"

using namespace std;

int main() {
    Product product("Cheeseburger", 50);

    try {
        for (int i = 0; i < 60; i++) {
            product.purchase();
        }
    } catch (OutOfStockException &e) {
        cerr << e.what() << endl;
    }

    return 0;
}