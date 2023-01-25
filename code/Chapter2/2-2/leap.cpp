#include <iostream>

using namespace std;

int main()
{
    int year;
    cout << "Enter a year: ";
    cin >> year;

    /*
     * A year is a leap year if it is
     * 1. exactly divisible by 4, and not divisible by 100;
     * 2. or is exactly divisible by 400
     */
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        cout << "Leap year" << endl;
    }
    else
    {
        cout << "Common year" << endl;
    }

    return 0;
}