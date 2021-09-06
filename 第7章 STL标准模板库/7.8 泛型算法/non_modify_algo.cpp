#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    vector<int> v1 = {40, 9, 20, 34, 7, 34, 85, 9};
    vector<int> v2 = {40, 9, 20, 34, 7, 34, 85, 9};
    int key = 34;
    
    vector<int>::iterator iter = find(v1.begin(), v1.end(), key);
    if(iter != v1.end()) {
        cout << "key found in vector: " << *iter << endl;
    } else {
        cout << "key not found" << endl;
    }
    
    cout << key << " appears "
         << count(v1.begin(), v1.end(), key) << endl;
    cout << "sum = "
         << accumulate(v1.begin(), v1.end(), 0) << endl;
	cout << "v1 == v2? " << boolalpha
         << equal(v1.begin(), v1.end(), v2.begin()) << endl;
         
    return 0;
}