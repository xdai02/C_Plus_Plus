#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>

using namespace std;

int main() {
    FILE *fp = fopen("data3.txt", "r");
    if (!fp) {
        cerr << "File open failed." << endl;
    }

    char line[128];
    while (fgets(line, sizeof(line), fp) != NULL) {
        char *token = strtok(line, " \t\n");
        while (token != NULL) {
            // remove punctuations
            int i = strlen(token) - 1;
            while (!isalpha(token[i])) {
                i--;
            }
            token[i + 1] = '\0';

            cout << token << endl;
            token = strtok(NULL, " \t\n");
        }
    }

    fclose(fp);
    return 0;
}