#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    double sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if(i % 2 == 1)
        {
            sum += 1.0 / i;
        }
        else
        {
            sum -= 1.0 / i;
        }
    }
    
    cout << "Sum = " << fixed << setprecision(2) << sum << endl;

    return 0;
}