#include <iostream>

using namespace std;

int main()
{
    char c;
    cout << "Enter a character: ";
    cin >> c;

    if(c >= 'a' && c <= 'z')
    {
        printf("Lowercase\n");
    }
    else if(c >= 'A' && c <= 'Z')
    {
        printf("Uppercase\n");
    }
    else if(c >= '0' && c <= '9')
    {
        printf("Digit\n");
    }
    else
    {
        printf("Special character\n");
    }
    
    return 0;
}