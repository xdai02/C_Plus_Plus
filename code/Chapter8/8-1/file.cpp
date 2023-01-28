#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    FILE *fp = fopen("data.txt", "r");
    if(!fp) {
        exit(1);
    }
    fclose(fp);
    return 0;
}