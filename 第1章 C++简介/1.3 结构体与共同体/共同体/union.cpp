#include <iostream>

using namespace std;

typedef union {
	int n;
	char str[sizeof(int)];
} Data;

int main() {
	Data data;
	data.n = 1;		// 高字节00 00 00 01低字节
	
	// 大端：数据的高字节存储在低地址中，低字节在高地址中
	// 低地址 00 00 00 01 高地址
    // 小端：数据的低字节存储在低地址中，高字节在高地址中
	// 低地址 01 00 00 00 高地址
	if(data.str[sizeof(int)-1] == 1) {
		cout << "big endian" << endl;
	} else {
		cout << "little endian" << endl;
	}
	return 0;
}