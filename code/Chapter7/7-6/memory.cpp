#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    void *p;
    int cnt = 0;

    // allocate 100MB memory each time
    while ((p = malloc(100 * 1024 * 1024))) {
        cnt++;
    }
    cout << "Allocated " << cnt * 100 << " MB memory" << endl;

    return 0;
}