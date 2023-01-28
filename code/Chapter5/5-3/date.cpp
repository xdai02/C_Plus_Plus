#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

string format_date(int year=1970, int month=1, int day=1) {
    ostringstream oss;
    oss << setfill('0') << setw(4) << year << "/"
        << setw(2) << month << "/"
        << setw(2) << day;
    return oss.str();
}

int main() {
    cout << format_date(2022, 12, 16) << endl;
    cout << format_date(2022, 12) << endl;
    cout << format_date(2022) << endl;
    cout << format_date() << endl;

    return 0;
}