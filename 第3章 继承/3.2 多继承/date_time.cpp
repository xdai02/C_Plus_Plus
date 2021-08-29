#include <iostream>
#include <string>

using namespace std;

class Date
{
public:
    Date(int year = 1970, int month = 1, int day = 1);
    string getDate();

private:
    int year;
    int month;
    int day;
};

Date::Date(int year, int month, int day)
    : year(year), month(month), day(day) {
}

string Date::getDate() {
    return to_string(year) + "/" + to_string(month) + "/" + to_string(day);
}

class Time
{
public:
    Time(int hour = 0, int minute = 0, int second = 0);
    string getTime();

private:
    int hour;
    int minute;
    int second;
};

Time::Time(int hour, int minute, int second)
    : hour(hour), minute(minute), second(second) {
}

string Time::getTime() {
    return to_string(hour) + ":" + to_string(minute) + ":" + to_string(second);
}

class DateTime : public Date, public Time {
public:
    DateTime(int year = 1970, int month = 1, int day = 1,
             int hour = 0, int minute = 0, int second = 0);
    string getDateTime();
};

DateTime::DateTime(int year, int month, int day,
                   int hour, int minute, int second)
    : Date(year, month, day),
      Time(hour, minute, second) {
}

string DateTime::getDateTime() {
    return getDate() + " " + getTime();
}

int main() {
    DateTime dt1;
    cout << dt1.getDateTime() << endl;
    DateTime dt2(2021, 8, 29, 15, 39, 50);
    cout << dt2.getDateTime() << endl;
    return 0;
}