#include <iostream>
#include <list>

using namespace std;

void printList(list<int> lst) {
    for(list<int>::iterator iter = lst.begin(); iter != lst.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
}

int main() {
    list<int> lst;

    lst.push_back(11);       // [11]
    lst.push_front(22);      // [22, 11]
    cout << lst.front() << endl;    // 22
    cout << lst.back() << endl;     // 11

    lst.insert(++lst.begin(), 3);   // [22, 3, 11]
    lst.insert(--lst.end(), 2);     // [22, 3, 2, 11]
    lst.push_back(2);               // [22, 3, 2, 11, 2]
    printList(lst);

    lst.pop_front();                // [3, 2, 11, 2]
    lst.sort();                     // [2, 2, 3, 11]
    lst.unique();                   // [2, 3, 11]
    printList(lst);

    list<int> lst2{0, 9, 2, 8};
    // [2, 3, 11, 0, 9, 2, 8]
    lst.splice(lst.end(), lst2, lst2.begin(), lst2.end());
    printList(lst);

    lst.sort();             // [0, 2, 2, 3, 8, 9, 11]
    printList(lst);

    list<int> lst3{1, 2, 8};
    lst.merge(lst3);        // [0, 1, 2, 2, 2, 3, 8, 8, 9, 11]
    printList(lst);

    return 0;
}