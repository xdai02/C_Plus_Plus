#include <iostream>

using namespace std;

int main()
{
    for(int year = 1970; year <= 2030; year++)
    {
        if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        {
            cout << year << " ";
        }
    }

    return 0;
}