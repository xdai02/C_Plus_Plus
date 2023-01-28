#include <iostream>

using namespace std;

int moves = 0;

void hanoi(int n, char src, char mid, char dst) {
    if (n == 1) {
        cout << src << " -> " << dst << endl;
        moves++;
    } else {
        // move top n-1 disks from src to mid
        hanoi(n - 1, src, dst, mid);
        cout << src << " -> " << dst << endl;
        moves++;
        // move top n-1 disks from mid to dst
        hanoi(n - 1, mid, src, dst);
    }
}

int main() {
    hanoi(3, 'A', 'B', 'C');
    cout << "Moves: " << moves << endl;
    return 0;
}