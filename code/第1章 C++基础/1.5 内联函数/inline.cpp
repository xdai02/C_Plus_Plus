#include <iostream>

using namespace std;

inline int max(int num1, int num2) {
	return num1 > num2 ? num1 : num2;
}

int main() {
	cout << max(92, 28) << endl;
	return 0;
}