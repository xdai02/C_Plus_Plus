#include <iostream>

using namespace std;

int main()
{
    int total;
    
    cout << "Enter total seconds: ";
    cin >> total;

    int hour = total / 3600;
    int min = total % 3600 / 60;
    int sec = total % 60;

    cout << hour << " hour(s) " << min << " minute(s) " << sec << " second(s)" << endl;

    return 0;
}