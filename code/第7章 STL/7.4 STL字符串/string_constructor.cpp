#include <iostream>
#include <string>

using namespace std;

int main() {
    string s1;				// Ĭ�ϳ�ʼ����Ϊ���ַ���
    string s2(s1);			// ֱ�ӳ�ʼ����s2��s1�ĸ���
    string s3 = s1;			// ������ʼ����s3��s1�ĸ������ȼ�s3(s1)
    string s4("hello");		// ֱ�ӳ�ʼ������ʼ��Ϊ����ֵ����
    string s5 = "hello";	// ������ʼ������ʼ��Ϊ����ֵ����
    string s6(10, 'x');		// ֱ�ӳ�ʼ������ʼ��Ϊ10���ַ�'x'
    
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;
    cout << "s4 = " << s4 << endl;
    cout << "s5 = " << s4 << endl;
    cout << "s6 = " << s4 << endl;
    
    return 0;
}