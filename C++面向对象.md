**stack**

栈，又名堆栈，是一种运算受限的线性数据结构，栈只能在表尾进行插入和删除操作。

栈中的元素只能先进后出（FILO, First In Last Out）。最早进入栈的元素所存放的位置叫作栈底（bottom），最后进入栈的元素存放的位置叫作栈顶（top）。

![](./img/C7/7-6/1.png)

<img src="./img/C7/7-6/2.png" style="zoom:80%;" />

向一个栈插入新元素的操作称为入栈push（或进栈、压栈），从一个栈删除元素的操作称为出栈pop（或退栈、弹栈）。

![](./img/C7/7-6/3.png)

入栈操作就是把新元素放入栈中，只允许从栈顶一侧放入元素，新元素的位置将会成为新的栈顶。

最初，栈为空，栈顶的初始值为-1。每当向栈中添加元素时，栈顶指针加1。

![](./img/C7/7-6/4.png)

出栈操作就是把新元素从栈中弹出，只有栈顶元素才允许出栈，出栈元素的前一个元素将会成为新的栈顶。

从栈中移出元素，栈顶指针减1。数组中元素的删除并非真正意义上把元素从内存中清除，出栈只需对栈顶减1即可，后期向栈中添加元素时，新元素会将旧元素覆盖。

![](./img/C7/7-6/5.png)

| stack操作 | 描述                                  |
| --------- | ------------------------------------- |
| empty()   | 判断栈是否为空                        |
| size()    | 返回栈中元素个数                      |
| push()    | 入栈，调用底层容器的`push_back()`实现 |
| pop()     | 出栈                                  |
| top()     | 返回栈顶元素的引用                    |

---

【代码】stack

```c++
#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.top() << endl;

    while(!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}
```

> 运行结果

```
3
3
2
1
```

---



**deque**

双端队列是一种同时具有队列和栈的性质的数据结构，双端队列可以从其两端插入和删除元素。

![](./img/C7/7-6/6.png)

| deque操作    | 描述                |
| ------------ | ------------------- |
| empty()      | 判断deque是否为空   |
| size()       | 返回deque中元素个数 |
| front()      | 返回首元素引用      |
| back()       | 返回尾元素引用      |
| push_front() | 在头部添加一个元素  |
| push_back()  | 在尾部添加一个元素  |
| pop_front()  | 在头部删除一个元素  |
| pop_back()   | 在尾部删除一个元素  |
| clear()      | 清空deque           |

---

【代码】deque

```c++
#include <iostream>
#include <deque>

using namespace std;

int main() {
    deque<int> deq;
    
    deq.push_front(1);
    deq.push_front(2);
    deq.push_back(3);
    deq.push_back(4);
    cout << deq.front() << endl;
    cout << deq.back() << endl;

    deq.pop_back();
    deq.pop_front();
    cout << deq.front() << endl;
    cout << deq.back() << endl;

    return 0;
}
```

> 运行结果

```
2
4
1
3
```

---



**priority_queue**

普通的队列是一种先进先出（FIFO, First In First Out）的数据结构，元素在队尾添加，在队头删除。

在优先队列`priority_queue`中，元素被赋予优先级，当访问元素时，具有最高优先级的元素最先被访问。使用`priority_queue`需要包含头文件`<queue>`。

| priority_queue操作 | 描述               |
| ------------------ | ------------------ |
| empty()            | 判断队列是否为空   |
| size()             | 返回队列中元素个数 |
| top()              | 访问队头           |
| push()             | 插入元素           |
| pop()              | 弹出队头           |

---

【代码】priority_queue

```c++
#include <iostream>
#include <queue>

using namespace std;

int main() {
    priority_queue<int> pq;
    pq.push(9);
    pq.push(2);
    pq.push(8);

    while(!pq.empty()) {
        cout << pq.top() << endl;
        pq.pop();
    }
    return 0;
}
```

> 运行结果

```
9
8
2
```

---

<div style="page-break-after: always;"></div>

## 7.7 关联容器

**关联容器**

顺序容器的元素是按照在容器中的位置来保存和访问的，关联容器的元素按照关键字来保存和访问。关联容器支持高效地关键字查询和访问。所有关联容器都支持通用容器操作，但不支持顺序容器特有的操作，例如`push_front()`或`push_back()`。

`set`和`map`是两种关联容器，`set`中的元素只包含关键字，而`map`中的元素是键值对（key-value pair）。

| 关联容器           | 说明                              | 头文件            |
| ------------------ | --------------------------------- | ----------------- |
| set                | 只保存关键字的容器                | `<set>`           |
| multiset           | 关键字可以重复出现的set           | `<set>`           |
| unordered_set      | 用哈希函数组织的set               | `<unordered_set>` |
| unordered_multiset | 哈希组织的set，关键字可以重复出现 | `<unordered_set>` |
| map                | 保存键值对的容器                  | `<map>`           |
| multimap           | 关键字可重复出现的map             | `<map>`           |
| unordered_map      | 用哈希函数组织的map               | `<unordered_map>` |
| unordered_multimap | 哈希组织的map，关键字可以重复出现 | `<unordered_map>` |

`set`是关键字的集合，其底层实现使用的是红黑树，当想要查找一个值是否存在时可以使用。`set`是模板，使用时必须在模板参数中指定元素类型。

`map`是模板，使用时必须在模板参数中指定key和value的类型。`map`常称为关联数组或字典，但是其下标不必是整数，而是通过关键字来查找值。

`map`的元素都是pair类型，pair也是模板，定义在`<utility>`中，一个pair保存两个public的数据成员，分别叫first和second。

---

【代码】关键词提取

- summary.txt

```
Internet of Things allows billions of physical objects to be connected to collect and exchange data for offering various applications, such as environmental monitoring, infrastructure management, and home automation. On the other hand, IoT has unsupported features that are critical for some IoT applications, including smart traffic lights, home energy management and augmented reality. To support these features, fog computing is integrated into IoT to extend computing, storage and networking resources to the network edge. Unfortunately, it is confronted with various security and privacy risks, which raise serious concerns towards users. In this survey, we review the architecture and features of fog computing and study critical roles of fog nodes, including real-time services, transient storage, data dissemination and decentralized computation. We also examine fog-assisted IoT applications based on different roles of fog nodes.
```

- excludes.txt

```
the
a
an
is
this
that
of
at
in
on
for
and
it
with
to
we
I
into
which
these
those
are
be
as
has
have
or
```

- STL_set_map.cpp

```c++
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cctype>
#include <algorithm>

using namespace std;

string getSummary(string filename) {
    ifstream in(filename);
    string summary;
    string line;
    while(getline(in, line)) {
        summary += line;
    }
    in.close();
    return summary;
}

set<string> getExcludes(string filename) {
    ifstream in(filename);
    set<string> excludes;
    string token;
    while(in >> token) {
        excludes.insert(token);
    }
    in.close();
    return excludes;
}

int main() {
    string summary = getSummary("summary.txt");
    vector<string> tokens;
    
    istringstream in(summary);
    string token;
    while(in >> token) {
        // eliminate the trailing punctuation
        if(!isalpha(token.back())) {
            token.pop_back();
        }
        
        // convert to lower case
        transform(
            token.begin(), token.end(), 
            token.begin(), ::tolower
        );

        tokens.push_back(token);
    }

    set<string> excludes = getExcludes("excludes.txt");
    map<string, int> keywords;

    for(string token : tokens) {
        // not in excludes set
        if(excludes.find(token) == excludes.end()) {
            keywords[token]++;
        }
    }
    
    for(auto& p : keywords) {
        cout << p.first << ": " << p.second << endl;
    }
    
    return 0;
}
```

> 运行结果

```
allows: 1
also: 1
applications: 3
architecture: 1
augmented: 1
automation: 1
based: 1
billions: 1
collect: 1
computation: 1
computing: 3
concerns: 1
confronted: 1
connected: 1
critical: 2
data: 2
decentralized: 1
different: 1
dissemination: 1
edge: 1
energy: 1
environmental: 1
examine: 1
exchange: 1
extend: 1
features: 3
fog: 4
fog-assisted: 1
hand: 1
home: 2
including: 2
infrastructure: 1
integrated: 1
internet: 1
iot: 4
lights: 1
management: 2
monitoring: 1
network: 1
networking: 1
nodes: 2
objects: 1
offering: 1
other: 1
physical: 1
privacy: 1
raise: 1
real-time: 1
reality: 1
resources: 1
review: 1
risks: 1
roles: 2
security: 1
serious: 1
services: 1
smart: 1
some: 1
storage: 2
study: 1
such: 1
support: 1
survey: 1
things: 1
towards: 1
traffic: 1
transient: 1
unfortunately: 1
unsupported: 1
users: 1
various: 2
```

---

<div style="page-break-after: always;"></div>

## 7.8 泛型算法

**泛型算法（Generic Algorithm）**

标准库未给容器添加大量功能，而是提供一组独立于容器的泛型算法。它们实现了一些经典算法的公共接口，可用于不同类型的容器和元素。标准库算法不直接操作容器，而是遍历两个迭代器指定的元素范围。指针类似于内置数组上的迭代器，故泛型算法也可操作内置数组和指针。

大多数算法定义在`<algorithm>`中，另外一组数值算法定义在`<numeric>`中。

大多标准库算法都对一个范围内的元素操作，这个范围称为输入范围，接受输入范围的算法总是用前两个参数来表示输入范围。多数算法遍历输入范围的方式相似，但使用元素的方法不同，如是否读、是否写、是否重排等。



**只读算法**

只读算法只读取输入范围的元素，但不改变它们。使用只读算法，最好用`cbegin()`和`cend()`。

`find()`的作用是将范围中每一个元素与给定值比较，返回第一个等于给定值的元素的迭代器，如果没有匹配则返回该范围的尾后迭代器。`find()`会调用给定值类型的`==`运算符来比较。

```c++
template <class InputIterator, class T>
InputIterator find(
    InputIterator first, InputIterator last, const T& val
);
```

`count()`的作用是将范围中每一个元素与给定值比较，返回给定值在范围中出现的次数。

`accumulate()`定义于`<numeric>`，其作用是对范围中元素求和，再加上给定值，返回求值结果。`accumulate()`会调用给定值类型的`+`运算符来求和。

```c++
template <class InputIterator, class T>
T accumulate(InputIterator first, InputIterator last, T init);
```

`equal()`的作用是确定两个序列的值是否相同，若果所有元素都相等时返回true，否则false。函数接受有3个参数，前两个是第一个序列的输入范围，第三个参数是第二个范围的首迭代器。`equal()`会调用`==`运算符来比较，元素类型不必严格一致。

```c++
template <class InputIterator1, class InputIterator2>
bool equal(
    InputIterator1 first1, InputIterator1 last1, 
    InputIterator2 first2
);
```

---

【代码】只读算法

```c++
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    vector<int> v1 = {40, 9, 20, 34, 7, 34, 85, 9};
    vector<int> v2 = {40, 9, 20, 34, 7, 34, 85, 9};
    int key = 34;
    
    vector<int>::iterator iter = find(
        v1.begin(), v1.end(), key
    );
    if(iter != v1.end()) {
        cout << "key found in vector: " << *iter << endl;
    } else {
        cout << "key not found" << endl;
    }
    
    cout << key << " appears "
         << count(v1.begin(), v1.end(), key) << endl;
    cout << "sum = "
         << accumulate(v1.begin(), v1.end(), 0) << endl;
    cout << "v1 == v2? " << boolalpha
         << equal(v1.begin(), v1.end(), v2.begin()) << endl;
         
    return 0;
}
```

> 运行结果

```
key found in vector: 34
34 appears 2
sum = 238
v1 == v2? true
```

---



**写容器元素算法**

写容器元素算法可对序列中元素重新赋值，要求原序列大小不小于要写入的元素数目。

`fill()`的作用是用给定值填满输入范围，函数接受3个参数，前2个是输入范围，第3个是给定值。

```c++
template <class ForwardIterator, class T>
void fill(
    ForwardIterator first, ForwardIterator last, const T& val
);
```

`copy()`的作用是将输入范围的值拷贝到目标序列，返回目标序列的尾后迭代器。函数接受3个参数，前2个是输入范围，第3个是目标序列的起始位置。

```c++
template <class InputIterator, class OutputIterator>
OutputIterator copy(
    InputIterator first, InputIterator last,
    OutputIterator result
);
```

`replace()`的作用是将序列中所有等于给定值的元素换为另一个值，函数接受4个参数，前2个是输入范围，后2个分别是要搜索的值和新值。

```c++
template <class ForwardIterator, class T>
void replace(
    ForwardIterator first, ForwardIterator last, 
    const T& old_value, const T& new_value
);
```

---

【代码】写容器元素算法

```c++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

ostream& operator<<(ostream& out, vector<int>& v) {
    for(vector<int>::iterator iter = v.begin(); 
        iter != v.end(); 
        iter++
       ) {
        out << *iter << " ";
    }
    return out;
}

int main() {
    vector<int> v1 = {9, 2, 8, 8, 2, 1, 0, 1, 2};
    vector<int> v2(10);
    
    fill(v2.begin(), v2.end(), 0);
    cout << v2 << endl;

    copy(v1.begin(), v1.end(), v2.begin());
    cout << v2 << endl;

    replace(v2.begin(), v2.end(), 1, 7);
    cout << v2 << endl;
    return 0;
}
```

> 运行结果

```
0 0 0 0 0 0 0 0 0 0 
9 2 8 8 2 1 0 1 2 0
9 2 8 8 2 7 0 7 2 0
```

---



**重排容器元素算法**

重排容器元素算法可对容器中元素重新排列顺序。

`sort()`的作用是重排输入序列的元素使其有序，函数接受2个参数表示输入范围，函数会调用序列元素类型的`<`运算符。

标准库允许在执行算法时用自定义操作代替默认算符，而不需要在类型中重载。

```c++
template <class RandomAccessIterator>
void sort(
    RandomAccessIterator first, RandomAccessIterator last
);

template <class RandomAccessIterator, class Compare>
void sort(
    RandomAccessIterator first, RandomAccessIterator last, 
    Compare comp
);
```

谓词（predicate）是一个可调用的表达式，其返回值（true/false）可用作条件。按照参数的数量分为一元谓词和二元谓词。接受谓词的算法用该谓词代替默认的算符来操作元素。

`unique()`的作用是重排输入序列，消除相邻重复项，返回消除后的无相邻重复值的尾后迭代器。`unique()`不真正删除元素，只是将后面的不重复值前移来覆盖前面的重复值，真正删除元素需要使用容器操作。

```c++
template <class ForwardIterator>
ForwardIterator unique(
    ForwardIterator first, ForwardIterator last
);

template <class ForwardIterator, class BinaryPredicate>
ForwardIterator unique(
    ForwardIterator first, ForwardIterator last,
    BinaryPredicate pred
);
```

---

【代码】重排容器元素算法

```c++
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

ostream& operator<<(ostream& out, vector<string>& v) {
    for(vector<string>::iterator iter = v.begin();
        iter != v.end();
        iter++
       ) {
        out << *iter << " ";
    }
    return out;
}

bool isLonger(const string& s1, const string& s2) {
    return s1.size() > s2.size();
}

int main() {
    vector<string> v = {
        "C++", "Java", "Python",
        "C++", "C", "JavaScript", 
        "Golang", "C++"
    };
    
    sort(v.begin(), v.end());
    cout << v << endl;
    
    sort(v.begin(), v.end(), isLonger);
    cout << v << endl;
    
    vector<string>::iterator endUnique = unique(
        v.begin(), v.end()
    );
    v.erase(endUnique, v.end());
    cout << v << endl;
    return 0;
}
```

> 运行结果

```
C C++ C++ C++ Golang Java JavaScript Python 
JavaScript Golang Python Java C++ C++ C++ C
JavaScript Golang Python Java C++ C
```

---

