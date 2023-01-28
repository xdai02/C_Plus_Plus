#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    FILE *fp = fopen("data2.txt", "w");

    for (int i = 0; i < 26; i++) {
        fputc('A' + i, fp);
    }

    fclose(fp);
    return 0;
}