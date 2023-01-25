#include <iostream>
#include <string>

using namespace std;

int main() {
    string s = "Hello World!";
    cout << "length(): " << s.length() << endl;
    cout << "substr(): " << s.substr(0, 5) << endl;
    cout << "find(): " << s.find("World") << endl;

    s.push_back('!');
    cout << "push_back(): " << s << endl;

    s.pop_back();
    cout << "pop_back(): " << s << endl;

    s.append("Hello World!");
    cout << "append(): " << s << endl;

    s.insert(12, " ");
    cout << "insert(): " << s << endl;

    s.erase(13, 6);
    cout << "erase(): " << s << endl;

    s.replace(13, 5, "C++");
    cout << "replace(): " << s << endl;

    return 0;
}