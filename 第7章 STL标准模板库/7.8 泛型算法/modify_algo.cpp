#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

ostream& operator<<(ostream& out, vector<int>& v) {
    for(vector<int>::iterator iter = v.begin(); iter != v.end(); iter++) {
        out << *iter << " ";
    }
    return out;
}

int main() {
	vector<int> v1 = {9, 2, 8, 8, 2, 1, 0, 1, 2};
    vector<int> v2(10);
    
    fill(v2.begin(), v2.end(), 0);
    cout << v2 << endl;

    copy(v1.begin(), v1.end(), v2.begin());
    cout << v2 << endl;

    replace(v2.begin(), v2.end(), 1, 7);
    cout << v2 << endl;
    return 0;
}