#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    cout << "布尔：";
    cout << boolalpha << true << " " << false << endl;
    cout << "------------------------------" << endl;
    
    cout << "十进制：";
    cout << dec << 20 << " " << 1024 << endl;
    
    cout << "十六进制：";
    cout << showbase << hex << 20 << " " << 1024 << noshowbase << endl;
    
    cout << "八进制：";
    cout << oct << 20 << " " << 1024 << dec << endl;
    cout << "------------------------------" << endl;
    
    cout << "科学计数法：";
    cout << scientific << 100 * sqrt(2) << defaultfloat << endl;
    cout << "------------------------------" << endl;
    
    cout << "默认输出浮点数：";
    cout << 10.0 << endl;
    
    cout << "浮点数打印小数点：";
    cout << showpoint << 10.0 << noshowpoint << endl;
    cout << "------------------------------" << endl;
    
    cout << "精度：";
    cout << setprecision(3) << fixed << sqrt(2) << endl;
    cout << "------------------------------" << endl;
    
    cout << "宽度填充：";
    cout << setfill('0') << setw(4) << 2021 << "/"
         << setw(2) << 9 << "/"
         << setw(2) << 2 << endl;
    return 0;
}