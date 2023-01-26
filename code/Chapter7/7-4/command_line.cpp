#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

char *lower(char *s) {
    char *p = s;
    while (*p) {
        *p = tolower(*p);
        p++;
    }
    return s;
}

char *upper(char *s) {
    char *p = s;
    while (*p) {
        *p = toupper(*p);
        p++;
    }
    return s;
}

void usage(const char *program) {
    cout << "Usage: " << program << " [option] [string]" << endl;
    cout << "--lower: convert string to lower case" << endl;
    cout << "--upper: convert string to upper case" << endl;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        usage(argv[0]);
        return 1;
    }

    char *option = argv[1];
    char *string = argv[2];

    if (strcmp(option, "--lower") == 0) {
        cout << "Lower: " << lower(string) << endl;
    } else if (strcmp(option, "--upper") == 0) {
        cout << "Upper: " << upper(string) << endl;
    } else {
        usage(argv[0]);
        return 1;
    }

    return 0;
}