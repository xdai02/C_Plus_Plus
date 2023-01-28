#include <iostream>
#include "language.h"
#include "english.h"
#include "chinese.h"

using namespace std;

void show(Language& language) {
    language.translate();
}

int main() {
    English english("Hello!");
    show(english);

    Chinese chinese("��ã�");
    show(chinese);
    return 0;
}