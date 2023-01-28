#include <iostream>
#include <string>

using namespace std;

void tell_story() {
    string story;
    story += "从前有座山，山里有座庙\n";
    story += "庙里有个老和尚\n";
    story += "老和尚在对小和尚讲故事：\n";
    cout << story;

    tell_story();
}

int main() {
    tell_story();
    return 0;
}