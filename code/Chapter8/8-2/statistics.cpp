#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    FILE *fp = fopen("statistics.cpp", "r");
    if (!fp) {
        cerr << "File open failed." << endl;
        exit(1);
    }

    int chars = 0;
    int lines = 0;

    while (!feof(fp)) {
        char c = fgetc(fp);
        if (c == '\n') {
            lines++;
        } else {
            chars++;
        }
    }

    cout << "Characters: " << chars << endl;
    cout << "Lines: " << lines << endl;

    fclose(fp);
    return 0;
}