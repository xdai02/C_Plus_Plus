#include <iostream>

using namespace std;

int main()
{
    int age;
    cout << "Enter your age: ";
    cin >> age;
    if(age > 0 && age < 18)
    {
        cout << "Minor" << endl;
    }
    return 0;
}