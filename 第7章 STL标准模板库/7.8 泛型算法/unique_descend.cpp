#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

ostream& operator<<(ostream& out, vector<string>& v) {
    for(vector<string>::iterator iter = v.begin(); iter != v.end(); iter++) {
        out << *iter << " ";
    }
    return out;
}

bool isLonger(const string& s1, const string& s2) {
    return s1.size() > s2.size();
}

int main() {
    vector<string> v = {
        "C++", "Java", "Python",
        "C++", "C", "JavaScript", 
        "Golang", "C++"
    };
    
    sort(v.begin(), v.end());
    cout << v << endl;
    
    sort(v.begin(), v.end(), isLonger);
    cout << v << endl;
    
    vector<string>::iterator endUnique = unique(v.begin(), v.end());
    v.erase(endUnique, v.end());
    cout << v << endl;
    return 0;
}