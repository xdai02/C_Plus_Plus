#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int total = 821;
    int num = 10;
    double average = (double)total / num;
    cout << "Average = " << fixed << setprecision(2) << average << endl;
    return 0;
}