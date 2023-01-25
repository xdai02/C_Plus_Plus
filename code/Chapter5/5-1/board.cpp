#include <iostream>

using namespace std;

void print_board() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            cout << "   |";
        }
        cout << endl;

        if (i < 2) {
            cout << "---+---+---" << endl;
        }
    }
}

int main() {
    print_board();
    return 0;
}