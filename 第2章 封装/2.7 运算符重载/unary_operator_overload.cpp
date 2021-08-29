#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Time {
public:
    Time(int hour, int minute, int second);
    void display();
    Time operator++();      // 前置++
    Time operator++(int);   // 后置++

private:
    int hour;
    int minute;
    int second;
};

Time::Time(int hour, int minute, int second) 
    : hour(hour), minute(minute), second(second) {
}

void Time::display() {
    cout << setfill('0')
         << setw(2) << hour << ":"
         << setw(2) << minute << ":"
         << setw(2) << second << endl;
}

// 前置++
Time Time::operator++() {
    second++;
    if(second == 60) {
        second %= 60;
        minute++;
        if(minute == 60) {
            minute %= 60;
            hour++;
            if(hour == 24) {
                hour = 0;
            }
        }
    }
    return Time(hour, minute, second);
}

// 后置++
Time Time::operator++(int) {
    // 保存原始值
    Time time(hour, minute, second);
    second++;
    if(second == 60) {
        second %= 60;
        minute++;
        if(minute == 60) {
            minute %= 60;
            hour++;
            if(hour == 24) {
                hour = 0;
            }
        }
    }
    return time;    // 返回原始值
}

int main() {
    Time time(9, 21, 58);
    time.display();

    ++time;
    time.display();

    time++;
    time.display();
    return 0;
}