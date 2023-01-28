#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>

using namespace std;

char *strip(char *str) {
    int i = 0;
    int j = strlen(str) - 1;

    while (isspace(str[i]) && str[i] != '\0') {
        i++;
    }

    while (isspace(str[j]) && j >= 0) {
        j--;
    }

    int k = 0;
    while (i <= j) {
        str[k++] = str[i++];
    }
    str[k] = '\0';

    str = (char *)realloc(str, (k + 1) * sizeof(char));
    return str;
}

int main() {
    int len = 32;
    char *str = (char *)calloc(len + 1, sizeof(char));

    strcpy(str, "     Hello World! \n\t ");
    cout << "Before: [" << str << "]" << endl;

    str = strip(str);

    cout << "After: [" << str << "]" << endl;

    free(str);
    return 0;
}