#include <iostream>
#include <string>

using namespace std;

int main() {
    string s1;				// 默认初始化，为空字符串
    string s2(s1);			// 直接初始化，s2是s1的副本
    string s3 = s1;			// 拷贝初始化，s3是s1的副本，等价s3(s1)
    string s4("hello");		// 直接初始化，初始化为字面值常量
    string s5 = "hello";	// 拷贝初始化，初始化为字面值常量，等价于s5("hello")
    string s6(10, 'x');		// 直接初始化，初始化为10个字符'x'
    
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;
    cout << "s4 = " << s4 << endl;
    cout << "s5 = " << s4 << endl;
    cout << "s6 = " << s4 << endl;
    
    return 0;
}