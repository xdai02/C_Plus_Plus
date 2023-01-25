#include <iostream>

using namespace std;

int main()
{
    int n = 10;
    cout << "Enter " << n << " integers: ";

    int sum_square = 0;
    for(int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        if(num < 0)
        {
            continue;
        }

        sum_square += num * num;
    }

    cout << "Sum of squares of positive integers: "
         << sum_square << endl;
         
    return 0;
}