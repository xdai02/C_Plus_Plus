#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
	if(!v.empty()) {
        out << "[";
        copy(v.begin(), v.end(), ostream_iterator<T>(out, ", "));
        out << "\b\b]";
    }
    return out;
}

int main() {
    vector<int> v1(10);			// ��10��Ԫ�أ�����0
    vector<int> v2{10};			// ��1��Ԫ�أ�ֵ��10
    vector<int> v3(10, 1);		// ��10��Ԫ�أ�����1
    vector<int> v4{10, 1};		// ��2��Ԫ�أ�10��1
    vector<string> v5{"hello"};	// ��1��Ԫ�أ����ַ���"hello"
    
    cout << "v1 = " << v1 << endl;
    cout << "v2 = " << v2 << endl;
    cout << "v3 = " << v3 << endl;
    cout << "v4 = " << v4 << endl;
    cout << "v5 = " << v5 << endl;
    return 0;
}