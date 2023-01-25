#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(NULL));          // set random seed

    // generate random number between 1 and 100
    int answer = rand() % 100 + 1;
    int num = 0;
    int cnt = 0;

    do
    {
        cout << "Guess a number: ";
        cin >> num;
        cnt++;
        
        if(num > answer)
        {
            cout << "Too high" << endl;
        }
        else if(num < answer)
        {
            cout << "Too low" << endl;
        }
    } while(num != answer);

    cout << "Correct! You guessed " << cnt << " times." << endl;
    return 0;
}