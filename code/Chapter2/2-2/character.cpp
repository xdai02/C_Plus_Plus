#include <iostream>

using namespace std;

int main()
{
    char c;
    cout << "Enter a character: ";
    cin >> c;

    if(c >= 'a' && c <= 'z')
    {
        cout << "Lowercase" << endl;
    }
    else if(c >= 'A' && c <= 'Z')
    {
        cout << "Uppercase" << endl;
    }
    else if(c >= '0' && c <= '9')
    {
        cout << "Digit" << endl;
    }
    else
    {
        cout << "Special character" << endl;
    }
    
    return 0;
}