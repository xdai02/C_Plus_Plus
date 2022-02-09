#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

template<class T>
class SortedArray {
public:
    SortedArray(int capacity = 1);
    SortedArray(T *arr, int capacity);
    ~SortedArray();

    string data();
    void add(T val);
    void remove(T val);

private:
    T *arr;
    int len;
    int capacity;
    void resize(int size);
};

template<class T>
SortedArray<T>::SortedArray(int capacity) {
    this->len = 0;
    this->capacity = capacity;
    this->arr = new T[capacity];
}

template<class T>
SortedArray<T>::SortedArray(T *arr, int len) {
    this->len = len;
    this->capacity = len;
    this->arr = new T[len];
    for(int i = 0; i < len; i++) {
        this->arr[i] = arr[i];
    }
}

template<class T>
SortedArray<T>::~SortedArray() {
    delete arr;
}

template<class T>
string SortedArray<T>::data() {
    if(len == 0) {
        return "[]";
    }

    sort(this->arr, this->arr + len);
    ostringstream out;
    out << "[";
    for(int i = 0; i < len; i++) {
        out << arr[i] << ", ";
    }
    out << "\b\b]";
    return out.str();
}

template<class T>
void SortedArray<T>::resize(int size) {
    T *temp = new T[size];
    for(int i = 0; i < len; i++) {
        temp[i] = arr[i];
    }
    delete arr;
    arr = temp;
}

template<class T>
void SortedArray<T>::add(T val) {
    if(len == capacity) {
        capacity *= 2;
        resize(capacity);
    }
    arr[len++] = val;
}

template<class T>
void SortedArray<T>::remove(T val) {
    for(int i = 0; i < len; i++) {
        if(arr[i] == val) {
            arr[i] = arr[len-1];
            len--;
            if(len <= capacity / 2) {
                capacity /= 2;
                resize(capacity);
            }
            break;
        }
    }
}

int main() {
    int arr[] = {7, 7, 3, 9, 7, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    SortedArray<int> sortedArray(arr, n);
    cout << sortedArray.data() << endl;

    sortedArray.add(28);
    sortedArray.add(12);
    cout << sortedArray.data() << endl;

    sortedArray.remove(7);
    sortedArray.remove(9);
    cout << sortedArray.data() << endl;

    return 0;
}