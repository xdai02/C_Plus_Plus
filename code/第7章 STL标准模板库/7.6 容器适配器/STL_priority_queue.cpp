#include <iostream>
#include <queue>

using namespace std;

int main() {
    priority_queue<int> pq;
    pq.push(9);
    pq.push(2);
    pq.push(8);

    while(!pq.empty()) {
        cout << pq.top() << endl;
        pq.pop();
    }
    return 0;
}