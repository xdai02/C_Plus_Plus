[TOC]

<div style="page-break-after: always;"></div>

## 4.2 虚函数

**虚函数**

虚函数是定义在基类中的函数，子类必须对其进行重写/覆盖（override），虚函数需要在类的成员函数前面加上`virtual`关键字。

重写/覆盖是指子类中存在重新定义的函数，其函数名、参数列表、返回值类型都与父类中被重写的函数一致。被重写的函数必须是虚函数。

子类若重写了父类的函数，那么子类将会隐藏其父类中被重写的函数。但是子类通过强制类型转换成父类后可以重新调用父类中被重写的函数。

---

【代码】虚函数

- programmer.h

```c++
#ifndef _PROGRAMMER_H_
#define _PROGRAMMER_H_

#include <string>

class Programmer {
public:
    Programmer(std::string title = "programmer");
    virtual void work();
    
private:
    std::string title;
};

#endif
```

- programmer.cpp

```c++
#include "programmer.h"
#include <iostream>

using namespace std;

Programmer::Programmer(string title) : title(title) {}

void Programmer::work() {
    cout << "programming" << endl;
}
```

- java_programmer.h

```c++
#ifndef _JAVA_PROGRAMMER_H_
#define _JAVA_PROGRAMMER_H_

#include "programmer.h"
#include <string>

class JavaProgrammer : public Programmer {
public:
    JavaProgrammer(std::string title = "Java Programmer");
    virtual void work() override;
};

#endif
```

- java_programmer.cpp

```c++
#include "java_programmer.h"
#include <iostream>

using namespace std;

JavaProgrammer::JavaProgrammer(string title) 
    : Programmer(title) {}

void JavaProgrammer::work() {
    cout << "Android Development" << endl;
}
```

- test_programmer.cpp

```c++
#include <iostream>
#include "programmer.h"
#include "java_programmer.h"

using namespace std;

int main() {
    JavaProgrammer javaProgrammer;
    javaProgrammer.work();
    Programmer programmer = (Programmer)javaProgrammer;
    programmer.work();
    return 0;
}
```

> 运行结果

```
Android Development
programming
```

---

<div style="page-break-after: always;"></div>

## 4.3 纯虚函数

**纯虚函数**

在虚函数后加上`= 0`后可以让这个函数变成纯虚函数，包含纯虚函数的类叫做抽象类（abstract class）或接口类（interface）。

抽象类不能被用于实例化对象，只是提供了所有的子类共有的部分。例如在动物园中，存在的都是“动物”具体的子类对象，并不存在“动物”对象，所以动物类不应该被独立创建成对象。

抽象类的作用是可以被子类继承，提供共性的属性和方法。父类提供的方法很难满足子类不同的需求，如果不定义该方法，则表示所有的子类都不具有该行为。如果定义该方法，所有的子类都在重写，那么这个方法在父类中是没有必要实现的，显得多余。

被`virtual`关键字修饰的方法称为纯虚函数。纯虚函数只有声明，没有实现。纯虚函数只能包含在抽象类中。产生继承关系后，子类必须重写父类中所有的纯虚函数，否则子类还是抽象类。

---

【代码】纯虚函数

- shape.h

```c++
#ifndef _SHAPE_H_
#define _SHAPE_H_

class Shape {
public:
    virtual double getArea() = 0;
};

#endif
```

- rectangle.h

```c++
#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include "shape.h"

class Rectangle : public Shape {
public:
    Rectangle(double length = 0, double width = 0);
    virtual double getArea() override;

private:
    double length;
    double width;
};

#endif
```

- rectangle.cpp

```c++
#include "rectangle.h"

Rectangle::Rectangle(double length, double width)
    : length(length), width(width) {}

double Rectangle::getArea() {
    return length * width;
}
```

- circle.h

```c++
#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include "shape.h"

class Circle : public Shape {
public:
    Circle(double raidus = 0);
    virtual double getArea() override;

private:
    double radius;
};

#endif
```

- circle.cpp

```c++
#include "circle.h"

Circle::Circle(double radius) : radius(radius) {}

double Circle::getArea() {
    return 3.14159 * radius * radius;
}
```

- test_shape.cpp

```c++
#include <iostream>
#include "rectangle.h"
#include "circle.h"

using namespace std;

int main() {
    Rectangle rectangle(7, 5);
    Circle circle(6);
    cout << "rectangle: " << rectangle.getArea() << endl;
    cout << "circle: " << circle.getArea() << endl;
    return 0;
}
```

> 运行结果

```
rectangle: 35
circle: 113.097
```

---



**接口（Interface）**

在面向对象中会使用抽象类为外部提供一个通用的、标准化的接口。

宏观上来讲，接口是一种标准。例如常见的USB接口，电脑通过USB接口连接各种外设设备，每一个接口不用关心连接的外设设备是什么，只要这个外设设备实现了USB的标准，就可以连接到电脑上。

<img src="./img/C4/4-3/1.png" style="zoom:67%;" />

从程序上来讲，接口代表了某种能力和约定。当父类的方法无法满足子类需求时，可实现接口扩充子类的能力，接口中方法的定义代表能力的具体要求。

使用接口可以进行对行为的约束和规则的制定，接口表示一组能力，那么一个类可以接受多种能力的约束。因此一个类可以实现多个接口，实现多个接口的时候，必须要把每一个接口中的方法都实现。

---

【代码】接口

- language.h

```c++
#ifndef _LANGUAGE_H_
#define _LANGUAGE_H_

class Language {
public:
    virtual void translate() = 0;
};

#endif
```

- english.h

```c++
#ifndef _ENGLISH_H_
#define _ENGLISH_H_

#include "language.h"
#include <string>

class English : public Language {
public:
    English(std::string content = "");
    virtual void translate() override;

private:
    std::string content;
};

#endif
```

- english.cpp

```c++
#include "english.h"
#include <iostream>
#include <string>

using namespace std;

English::English(string content) : content(content) {}

void English::translate() {
    cout << content << endl;
}
```

- chinese.h

```c++
#ifndef _CHINESE_H_
#define _CHINESE_H_

#include "language.h"
#include <string>

class Chinese : public Language {
public:
    Chinese(std::string content = "");
    virtual void translate() override;

private:
    std::string content;
};

#endif
```

- chinese.cpp

```c++
#include "chinese.h"
#include <iostream>
#include <string>

using namespace std;

Chinese::Chinese(string content) : content(content) {}

void Chinese::translate() {
    cout << content << endl;
}
```

- test_language.cpp

```c++
#include <iostream>
#include "language.h"
#include "english.h"
#include "chinese.h"

using namespace std;

void show(Language& language) {
    language.translate();
}

int main() {
    English english("Hello!");
    show(english);

    Chinese chinese("你好！");
    show(chinese);
    return 0;
}
```

> 运行结果

```
Hello!
你好
```

---

<div style="page-break-after: always;"></div>

# 第5章 异常

## 5.1 异常

**异常（Exception）**

异常就是程序在运行过程中出现的非正常的情况。异常本身是一个类，产生异常就是创建异常对象并抛出一个异常对象。C++处理异常的方法是中断处理。如果程序遇到了未经处理的异常，会导致这个程序无法进行编译或者运行。

C++异常处理涉及到三个关键字：

1. `throw`：当问题出现时，程序会抛出一个异常。
2. `try`：放置可能抛出异常的代码。
3. `catch`：捕获并处理异常。

![](./img/C5/5-1/1.png)

---

【代码】除以0

```c++
#include <iostream>

using namespace std;

int divide(int num1, int num2) {
    if(num2 == 0) {
        throw "division by zero";
    }
    return num1 / num2;
}

int main() {
    try {
        int result = divide(5, 0);
        cout << result << endl;
    } catch(const char *msg) {
        cerr << msg << endl;
    }

    return 0;
}
```

> 运行结果

```
division by zero
```

---

普通的异常会导致程序无法完成编译，这样的异常被称为非运行时异常（non-runtime exception），但是由于异常是发生在编译时期的，因此常常称为编译时异常。在运行中如果遇到了异常，会导致程序执行的强制停止，这样的异常被称为运行时异常。

<div style="page-break-after: always;"></div>

## 5.2 异常类

**异常类**

C++提供了一系列标准的异常，定义在`<exception>`中。

<img src="./img/C5/5-2/1.png" style="zoom: 60%;" />

| 异常                  | 描述                  |
| :-------------------- | :-------------------- |
| std::exception        | 所有标准C++异常的父类 |
| std::bad_alloc        | 通过new抛出           |
| std::bad_cast         | 通过dynamic_cast抛出  |
| std::bad_exception    | 处理无法预期的异常    |
| std::bad_typeid       | 通过typeid抛出        |
| std::logic_error      | 逻辑错误              |
| std::domain_error     | 使用了无效的定义域    |
| std::invalid_argument | 使用了无效的参数      |
| std::length_error     | 创建过长的std::string |
| std::out_of_range     | 访问定义外的元素      |
| std::runtime_error    | 运行时错误            |
| std::overflow_error   | 发生上溢              |
| std::underflow_error  | 发生下溢              |
| std::range_error      | 存储超出范围的值      |

`what()`是异常类提供的一个公共方法，它已被所有子异常类重载。

---

【代码】bad_alloc

```c++
#include <iostream>
#include <exception>

using namespace std;

int main() {
    try {
        char *p = new char[0xfffffffff];
        delete p;
    } catch(bad_alloc &e) {
        cerr << e.what() << endl;
    }
    return 0;
}
```

> 运行结果

```
std::bad_alloc
```

---

<div style="page-break-after: always;"></div>

## 5.3 自定义异常

**自定义异常**

系统中提供了很多的异常类型，但是异常类型提供地再多，也无法满足所有的需求。当需要的异常类型系统没有提供的时候，此时就需要自定义异常了。通过继承和重载`exception`类可以定义新的异常。

---

【代码】自定义异常

```c++
#include <iostream>
#include <string>
#include <exception>

using namespace std;

class AgeException : public exception {
public:
    AgeException(string msg) : msg(msg) {}
    
    virtual const char* what() const noexcept override {
        return msg.c_str();
    }
    
private:
    string msg;
};

int main() {
    try {
        int age;
        cout << "Enter age: ";
        cin >> age;
        if(age < 0 || age > 130) {
            throw AgeException("invalid age");
        }
    } catch(AgeException& e) {
        cout << e.what() << endl;
    }
    
    return 0;
}
```

> 运行结果

```
Enter age: -1
invalid age
```

---

<div style="page-break-after: always;"></div>

# 第6章 I/O库

## 6.1 标准I/O

**标准I/O**

C++不直接处理输入输出，而是通过标准库中的一组类来处理I/O。输入流`istream`提供输入，输出流`ostream`提供输出。

标准输入输出有以下特点：

1. `cin`是`istream`的对象，从标准输入读取数据。
2. `cout`是`ostream`的对象，向标准输出写数据。
3. `cerr`是`ostream`的对象，用于输出错误信息，写到标准错误。
4. `>>`运算符从`istream`对象读取输入。
5. `<<`运算符从`ostream`对象写输出。
6. `getline()`从给定的`istream`读取一行数据，存入`string`对象。



**I/O格式化**

每个`iostream`对象维护一个格式状态来控制I/O的细节，如进制、精度、宽度等。操纵符改变流的格式状态时，通常改变后的状态对所有后续I/O都生效。

标准库定义了一组操纵符用来修改流的格式状态：

| 操纵符          | 功能                                        |
| --------------- | ------------------------------------------- |
| boolalpha       | 将true和false输出为字符串                   |
| noboolalpha     | 将true和false输出为1和0                     |
| showbase        | 对整型值输出表示进制的前缀                  |
| noshowbase      | 不生成表示进制的前缀                        |
| showpoint       | 浮点数总是显示小数点                        |
| noshowpoint     | 只有浮点数包含小数部分才显示小数点          |
| showpos         | 非负数显示“+”                               |
| noshowpos       | 非负数不显示“+”                             |
| uppercase       | 在十六进制中打印“0X”，在科学计数法中打印“E” |
| nouppercase     | 在十六进制中打印“0x”，在科学计数法中打印“e” |
| dec             | 整型显示为十进制                            |
| hex             | 整型显示为十六进制                          |
| oct             | 整型显示为八进制                            |
| left            | 在值的左侧添加填充字符                      |
| right           | 在值的右侧添加填充字符                      |
| internal        | 在符号和值之间添加填充字符                  |
| fixed           | 浮点数显示为定点十进制                      |
| scientific      | 浮点数显示为科学计数法                      |
| unitbuf         | 每次输出操作后刷新缓冲区                    |
| nounitbuf       | 恢复正常的缓冲区刷新方式                    |
| skipws          | 输入运算符跳过空白符                        |
| noskipws        | 输入运算符不跳过空白符                      |
| flush           | 刷新`ostream`缓冲区                         |
| ends            | 插入空字符，然后刷新ostream缓冲区           |
| endl            | 插入换行符，然后刷新ostream缓冲区           |
| setfill(ch)     | 用ch填充空白                                |
| setprecision(n) | 将浮点精度设置为n                           |
| setw(n)         | 读或写值的宽度为n个字符                     |
| setbase(n)      | 将整数输出为n进制                           |

---

【代码】格式化输出

```c++
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    cout << "布尔：";
    cout << boolalpha << true << " " << false << endl;
    cout << "------------------------------" << endl;
    
    cout << "十进制：";
    cout << dec << 20 << " " << 1024 << endl;
    
    cout << "十六进制：";
    cout << showbase << hex 
         << 20 << " "<< 1024
         << noshowbase << endl;
    
    cout << "八进制：";
    cout << oct << 20 << " " << 1024 << dec << endl;
    cout << "------------------------------" << endl;
    
    cout << "科学计数法：";
    cout << scientific
         << 100 * sqrt(2)
         << defaultfloat << endl;
    cout << "------------------------------" << endl;
    
    cout << "默认输出浮点数：";
    cout << 10.0 << endl;
    
    cout << "浮点数打印小数点：";
    cout << showpoint << 10.0 << noshowpoint << endl;
    cout << "------------------------------" << endl;
    
    cout << "精度：";
    cout << setprecision(3) << fixed << sqrt(2) << endl;
    cout << "------------------------------" << endl;
    
    cout << "宽度填充：";
    cout << setfill('0') << setw(4) << 2021 << "/"
         << setw(2) << 9 << "/"
         << setw(2) << 2 << endl;
    return 0;
}
```

> 运行结果

```
布尔：true false
------------------------------
十进制：20 1024
十六进制：0x14 0x400
八进制：24 2000
------------------------------
科学计数法：1.414214e+02
------------------------------
默认输出浮点数：10
浮点数打印小数点：10.0000
------------------------------
精度：1.414
------------------------------
宽度填充：2021/09/02
```

---

<div style="page-break-after: always;"></div>

## 6.2 文件I/O

**文件I/O**

程序不仅要从控制台进行I/O，还需要读写文件和字符串。

标准库的I/O类型在3个头文件中：

1. `<iostream>`定义了读写流的基本类型。
2. `<fstream>`定义了读写文件的类型。
3. `<sstream>`定义了读写`string`对象的类型。

`<fstream>`中定义了3个I/O类来读写文件：

1. `ifstream`从给定文件读数据。
2. `ofstream`向给定文件写数据。
3. `fstream`可读写文件。



**文件打开模式**

每个流都有一个关联的文件模式，在打开文件时可以指定文件模式。

| 打开模式   | 作用                                            |
| ---------- | ----------------------------------------------- |
| ios::in    | 以读方式打开                                    |
| ios::out   | 以写方式打开                                    |
| ios::app   | 以追加方式打开                                  |
| ios::ate   | 打开文件定位到文件末尾                          |
| ios::trunc | 如果文件存在，其内容将被截断，即把文件长度设为0 |

---

【代码】文件I/O

```c++
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string name;
    int id;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter id: ";
    cin >> id;
    
    ofstream out("info.txt");
    out << name << " " << id << endl;
    out.close();
    
    ifstream in("info.txt");
    in >> name >> id;
    in.close();
    
    cout << "name = " << name << ", id = " << id << endl;
    return 0;
}
```

> 运行结果

```
Enter name: Terry
Enter id: 979489
name = Terry, id = 979489
```

---

<div style="page-break-after: always;"></div>

## 6.3 string流

**string流**

`<sstream>`定义了3个类来支持内存IO：

1. `istringstream`从`string`读数据。
2. `ostringstream`向`string`写数据。
3. `stringstream`可读写`string`。

---

【代码】string流

```c++
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    string line;
    cout << "convert a string to Python list format: ";
    getline(cin, line);

    ostringstream out;
    istringstream in(line);
    string token;

    out << "[";
    while(in >> token) {
        out << token << ", ";
    }
    out << "\b\b]";
cout << out.str() << endl;
    return 0;
}
```

> 运行结果

```
convert a string to Python list format: This is a test
[This, is, a, test]
```

---

<div style="page-break-after: always;"></div>

# 第7章 STL标准模板库

## 7.1 模板

**泛型编程（Generic Programming）**

面向对象编程（OOP）和泛型编程（GP）都能处理在编写程序时类型未知的情况，OOP能处理运行时获取类型的情况，GP能处理编译期可获取类型的情况。

模板是泛型编程的基础，泛型编程就是以一种独立于任何特定类型的方式编写代码。C++标准库的容器、迭代器、算法都是泛型编程的例子。



**函数模板**

通过定义一个通用的函数模板可以处理参数为多种类型的情形，而不是为每个类型都定义一个重载。模板定义使用`template`关键字，后跟模板参数列表。模板参数表示函数或类定义中用到的类型，使用模板时需要隐式或显式提供模板实参，将其绑定到模板参数。

---

【代码】函数模板

```c++
#include <iostream>
#include <string>

using namespace std;

template <typename T>
inline T getMax(const T& val1, const T& val2) {
    return val1 > val2 ? val1 : val2;
}

int main() {
    int iVal1 = 28;
    int iVal2 = 92;
    cout << getMax(iVal1, iVal2) << endl;

    double dVal1 = 3.14;
    double dVal2 = 3.71;
    cout << getMax(dVal1, dVal2) << endl;

    string sVal1 = "hello";
    string sVal2 = "world";
    cout << getMax(sVal1, sVal2) << endl;
    return 0;
}
```

> 运行结果

```
92
3.71
world
```

---

函数模板仅仅是函数的规范，本身并不会占用内存。当编译器遇到对模板函数的调用时，才会在内存中创建该函数的实例。



**类模板**

类模板用来生成类的蓝图，与函数模板不同的是，类模板在实例化时编译器无法为类模板推导模板参数类型，而是必须在模板名后用`<>`提供实参。根据显式提供的模板实参列表，编译器使用这些模板参数来实例化特定的类。

编译器从类模板实例化一个类时，会重写模板，将模板参数的每个实例替换为给定的模板实参。因此类模板的每个实例都是独立的类，使用不同模板实参实例化出的类之间没有关联，也没有特殊的访问权限。

---

【代码】类模板

```c++
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

template<class T>
class SortedArray {
public:
    SortedArray(int capacity = 1);
    SortedArray(T *arr, int capacity);
    ~SortedArray();

    string data();
    void add(T val);
    void remove(T val);

private:
    T *arr;
    int len;
    int capacity;
    void resize(int size);
};

template<class T>
SortedArray<T>::SortedArray(int capacity) {
    this->len = 0;
    this->capacity = capacity;
    this->arr = new T[capacity];
}

template<class T>
SortedArray<T>::SortedArray(T *arr, int len) {
    this->len = len;
    this->capacity = len;
    this->arr = new T[len];
    for(int i = 0; i < len; i++) {
        this->arr[i] = arr[i];
    }
}

template<class T>
SortedArray<T>::~SortedArray() {
    delete arr;
}

template<class T>
string SortedArray<T>::data() {
    if(len == 0) {
        return "[]";
    }

    sort(this->arr, this->arr + len);
    ostringstream out;
    out << "[";
    for(int i = 0; i < len; i++) {
        out << arr[i] << ", ";
    }
    out << "\b\b]";
    return out.str();
}

template<class T>
void SortedArray<T>::resize(int size) {
    T *temp = new T[size];
    for(int i = 0; i < len; i++) {
        temp[i] = arr[i];
    }
    delete arr;
    arr = temp;
}

template<class T>
void SortedArray<T>::add(T val) {
    if(len == capacity) {
        capacity *= 2;
        resize(capacity);
    }
    arr[len++] = val;
}

template<class T>
void SortedArray<T>::remove(T val) {
    for(int i = 0; i < len; i++) {
        if(arr[i] == val) {
            arr[i] = arr[len-1];
            len--;
            if(len <= capacity / 2) {
                capacity /= 2;
                resize(capacity);
            }
            break;
        }
    }
}

int main() {
    int arr[] = {7, 7, 3, 9, 7, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    SortedArray<int> sortedArray(arr, n);
    cout << sortedArray.data() << endl;

    sortedArray.add(28);
    sortedArray.add(12);
    cout << sortedArray.data() << endl;

    sortedArray.remove(7);
    sortedArray.remove(9);
    cout << sortedArray.data() << endl;

    return 0;
}
```

> 运行结果

```
[1, 3, 3, 7, 7, 7, 9] 
[1, 3, 3, 7, 7, 7, 9, 12, 28]
[1, 3, 3, 7, 7, 12, 28]
```

---

<div style="page-break-after: always;"></div>

## 7.2 容器

**容器（Container）**

容器是特定类型对象的集合，容器分为顺序容器和关联容器：

1. 顺序容器：元素的顺序与其加入容器的位置对应。
2. 关联容器：元素的顺序由其关联的关键字决定，关联容器分为有序关联容器和无序关联容器。

所有容器类共享公有接口，不同容器按不同方式扩展。

C++新标准容器的性能比旧版本快很多，其性能与最精心优化过的同类数据结构一样好。现代C++程序应该使用标准库容器，而不是更原始的数据结构。



**顺序容器**

每个容器都定义于一个头文件中，文件名与容器名相同。容器都定义为模板类，顺序容器几乎可以保存任意类型的元素，还可以在容器中保存容器。

顺序容器包括`array`、`vector`、`string`、`deque`、`list`和`forward_list`。

| 容器         | 描述                                                         |
| ------------ | ------------------------------------------------------------ |
| array        | 固定大小数组，支持快速随机访问，不能添加或删除元素           |
| vector       | 可变大小数组，支持快速随机访问，在尾部之外的位置插入或删除元素可能很慢 |
| string       | 与`vector`相似的容器，但专门用于保存字符，随机访问快，在尾部插入或删除速度快 |
| deque        | 双端队列，支持快速随机访问，在头尾位置插入或删除速度很快     |
| list         | 双向链表，支持双向顺序访问，在任何位置插入或删除都很快       |
| forward_list | 单项链表，只支持单向顺序访问，在任何位置插入或删除都很快     |

`array`和内置数组一样大小固定，但操作更安全。除固定大小的`array`外，其它容器都提供高效灵活的内存管理，可以添加、删除、扩展和收缩容器的大小。

`vector`和`string`将元素存储在连续空间中，故通过下标的随机访问很快。在尾部添加元素很快，但中间和头部插入或删除很慢。添加元素可能造成空间的重新分配和元素拷贝。

`deque`支持快速随机访问，在两端插入或删除很快，但在中间插入或删除元素很慢。

`list`和`forward_list`的设计目的是让任何位置的插入或删除都快速高效且不需重新分配内存，但是不支持随机访问，为访问一个元素需要遍历整个链表。



**迭代器（Iterator）**

迭代器比下标访问更通用，所有标准库容器都支持迭代器，但只有几种支持下标。迭代器提供了对容器对象的间接访问，类似于指针。`begin()`方法返回指向首元素的迭代器，`end()`方法返回指向尾元素下一位置（尾后）的迭代器。如果容器为空，则`begin()`和`end()`返回的都是尾后迭代器。

任何可能改变容器容量的操作都会使容器的迭代器失效。

| 迭代器                 | 描述                           |
| ---------------------- | ------------------------------ |
| iterator               | 容器的迭代器                   |
| begin()                | 返回指向首元素的迭代器         |
| end()                  | 返回尾后迭代器                 |
| const_iterator         | 只读迭代器                     |
| cbegin()               | 返回指向首元素的只读迭代器     |
| cend()                 | 返回尾后只读迭代器             |
| reverse_iterator       | 按逆序寻址元素的迭代器         |
| const_reverse_iterator | 只读逆序迭代器                 |
| rbegin()               | 返回指向尾元素的逆序迭代器     |
| rend()                 | 返回首前逆序迭代器             |
| crbegin()              | 返回指向尾元素的只读逆序迭代器 |
| crend()                | 返回首前只读逆序迭代器         |

迭代器可以进行算术运算，将迭代器与整数相加减可以得到向前或向后若干位置的迭代器。使用关系运算符`<`、`<=`、`>`、`>=`和`==`可以对迭代器所指位置比较大小。将两个迭代器相减，结果是两个迭代器的距离。

---

【代码】迭代器

```c++
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s = "hello world";

    string::iterator iter = s.begin();
    cout << "[";
    while(iter != s.end()) {
        cout << *iter << ", ";
        iter++;
    }
    cout << "\b\b]" << endl;

    return 0;
}
```

> 运行结果

```
[h, e, l, l, o,  , w, o, r, l, d]
```

---

<div style="page-break-after: always;"></div>

## 7.3 STL数组

**array**

`array`容器是C++11标准中新增的序列容器，它在普通数组的基础上，添加了一些成员函数和全局函数。在使用上，它比普通数组更安全，且效率并没有因此变差。和其它容器不同，`array`的大小是固定的，无法动态的扩展或收缩。与内置数组不同的是，`array`允许做整个容器的拷贝和赋值，要求两个`array`大小和元素类型都一样。

`array`以类模板的形式定义在`<array>`头文件，`array`具有固定大小，其大小也是类型的一部分，定义时模板参数包含元素类型和大小。

| 成员函数        | 功能                                                         |
| --------------- | ------------------------------------------------------------ |
| size()          | 返回容器中当前元素的数量，其值始终等于初始化array类的第二个模板参数N |
| max_size()      | 返回容器可容纳元素的最大数量，其值始终等于初始化array类的第二个模板参数N |
| empty()         | 判断容器是否为空                                             |
| at(n)           | 返回容器中第n个元素的引用，该函数自动检查n是否在有效的范围内，如果不是则抛出`out_of_range`异常 |
| front()         | 返回容器中第一个元素的直接引用，不适用于空array容器          |
| back()          | 返回容器中最后一个元素的直接应用，不适用于空array容器        |
| data()          | 返回一个指向容器首个元素的指针                               |
| fill(val)       | 将val赋值给容器中的每个元素                                  |
| arr1.swap(arr2) | 交换arr1和arr2容器中的所有元素，前提是它们具有相同的长度和类型 |

---

【代码】array

```c++
#include <iostream>
#include <array>

using namespace std;

int main() {
    array<int, 10> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "size = " << arr.size() << endl;
    array<int, 10>::iterator begin = arr.begin();
    array<int, 10>::iterator end = arr.end();
    while(begin != end) {
        cout << *begin << " ";
        begin++;
    }
    cout << endl;
    return 0;
}
```

> 运行结果

```
size = 10
0 1 2 3 4 5 6 7 8 9
```

---



**vector**

`vector`表示对象的集合，由于`vector`容纳其它的对象，所以是一种容器。使用`vector`需要包含头文件`<vector>`。`vector`是一个类模板，模板可以看作编译器生成类或函数的一份说明。

`vector`的初始化包括直接初始化、拷贝初始化和列表初始化。

| 初始化                       | 描述                                           |
| ---------------------------- | ---------------------------------------------- |
| vector<T> v                  | 创建一个空的vector                             |
| vector<T> v2(v1)             | 用v1中所有元素的副本创建v2                     |
| vector<T> v2 = v1            | 等价于v2(v1)                                   |
| vector<T> v(n, val)          | v中包含了n个值为val的元素                      |
| vector<T> v(n)               | v中包含了n个值为默认初始化的元素               |
| vector<T> v{a, b, c, ...}    | 用列表元素初始化v                              |
| vector<T> v = {a, b, c, ...} | 等价于v{a, b, c, ...}                          |
| vector<T> v (begin, end)     | 根据迭代器范围[begin, end)复制到另一个vector中 |

---

【代码】vector构造函数

```c++
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
    if(!v.empty()) {
        out << "[";
        copy(v.begin(), v.end(), ostream_iterator<T>(out, ", "));
        out << "\b\b]";
    }
    return out;
}

int main() {
    vector<int> v1(10);         // 有10个元素，都是0
    vector<int> v2{10};         // 有1个元素，值是10
    vector<int> v3(10, 1);      // 有10个元素，都是1
    vector<int> v4{10, 1};      // 有2个元素，10和1
    vector<string> v5{"hello"}; // 有1个元素，是字符串"hello"
    
    cout << "v1 = " << v1 << endl;
    cout << "v2 = " << v2 << endl;
    cout << "v3 = " << v3 << endl;
    cout << "v4 = " << v4 << endl;
    cout << "v5 = " << v5 << endl;
    return 0;
}
```

> 运行结果

```
v1 = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0] 
v2 = [10] 
v3 = [1, 1, 1, 1, 1, 1, 1, 1, 1, 1] 
v4 = [10, 1]
v5 = [hello]
```

---



**vector操作**

| vector操作          | 描述                                                         |
| ------------------- | ------------------------------------------------------------ |
| v.empty()           | 判断vector是否为空                                           |
| v.size()            | 返回vector元素个数                                           |
| v[n]                | 返回vector中第n个元素的引用                                  |
| v1 = v2             | 用v2中的元素拷贝替换v1中的元素                               |
| v1 == v2、v1 != v2  | v1和v2相等当且仅当它们的元素个数相同，并且对应位置元素都相同 |
| v.push_back(val)    | 向vector尾部添加一个元素                                     |
| v.insert(iter, val) | 向迭代器指向元素前添加一个元素                               |
| v.pop_back()        | 删除vector最后一个元素                                       |
| v.erase(iter)       | 删除迭代器指向元素                                           |
| v.erase(begin, end) | 删除迭代器返回[begin, end)范围元素                           |
| v.clear()           | 清空vector                                                   |
| v.swap(vector &)    | 交换两个同类型vector数据                                     |
| v.assign(n, val)    | 设置vector中前n个元素值为val                                 |

`vector`不能使用下标添加元素，否则会造成缓冲区溢出，确保下标合法的一种有效手段就是尽可能使用`for-each`循环。如果循环体内部包含向`vector`添加元素的语句，则不能使用`for-each`循环。

---

【代码】vector

```c++
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v;
    for(int i = 0; i < 10; i++) {
        v.push_back(i * i);
}

    for(int& item : v) {
        cout << item << " ";
    }
    cout << endl;
    return 0;
}
```

> 运行结果

```
0 1 4 9 16 25 36 49 64 81
```

---

<div style="page-break-after: always;"></div>

## 7.4 STL字符串

**string**

`string`是标准库中的类型，表示可变长字符序列，使用需要包含头文件`<string>`。

`string`的初始化分为：

1. 直接初始化：使用括号初始化，调用构造函数。
2. 拷贝初始化：使用赋值初始化，调用重载的赋值运算符。

---

【代码】string初始化

```c++
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s1;              // 默认初始化，为空字符串
    string s2(s1);          // 直接初始化，s2是s1的副本
    string s3 = s1;         // 拷贝初始化，s3是s1的副本，等价s3(s1)
    string s4("hello");     // 直接初始化，初始化为字面值常量
    string s5 = "hello";    // 拷贝初始化，初始化为字面值常量，等价于s5("hello")
    string s6(10, 'x');     // 直接初始化，初始化为10个字符'x'
    
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;
    cout << "s4 = " << s4 << endl;
    cout << "s5 = " << s4 << endl;
    cout << "s6 = " << s4 << endl;
    
    return 0;
}
```

> 运行结果

```
s1 = 
s2 =
s3 =
s4 = hello
s5 = hello
s6 = hello
```

---



**string操作**

| string操作             | 描述                                                         |
| ---------------------- | ------------------------------------------------------------ |
| out << s               | 将s写到输出流out中                                           |
| in >> s                | 从输入流in中读取字符串赋给s，字符串以空白符分割              |
| getline(in, s)         | 从输入流in中读取一行赋给s                                    |
| s.empty()              | 判断s是否为空                                                |
| s.size()               | 返回s中字符个数                                              |
| s[n]                   | 返回s中第n个字符的引用                                       |
| s1 + s2                | 返回s1和s2连接后的结果                                       |
| s1 = s2                | 用s2的副本替换s1                                             |
| s1 == s2、s1 != s2     | 判断s1和s2是否相等                                           |
| <、<=、>、>=           | 字典序比较，对大小写敏感                                     |
| s1.append(s2)          | 尾部插入                                                     |
| s1.insert(pos, s2)     | 在第pos个位置插入s2                                          |
| s.erase(pos, n)        | 从第pos个位置删除n个字符                                     |
| s1.replace(pos, n, s2) | 从第pos个位置开始替换n个字符为s2                             |
| s.substr(pos, n)       | 返回一个string，包含s中从pos开始的n个字符的拷贝。pos的默认值为0，n的默认值为s.size() - pos。 |
| s1.find(s2)            | 查找s1中s2第一次出现的位置                                   |
| s1.rfind(s2)           | 查找s1中s2最后一次出现的位置                                 |

---

【代码】string

```c++
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s("Hello");

    s.append("world");          // Helloworld
    s.insert(s.size(), "!");    // Helloworld!

    s.replace(1, 4, "i");       // Hiworld!
    s.erase(2, 5);              // Hi!
    s.insert(2, " C++");        // Hi C++!

    cout << s << endl;

    cout << s.substr(3, 3) << endl;
    cout << s.substr(3) << endl;
    cout << s.find("C++") << endl;

    return 0;
}
```

> 运行结果

```
Hi C++!
C++
C++!
3
```

---

<div style="page-break-after: always;"></div>

## 7.5 STL链表

**list**

`list`双向链表是一种序列式容器，`list`中的元素通过指针连成逻辑意义上的线性表。由于`list`中元素结点并不要求在一段连续的内存中，因此`list`是不支持快速随机存取的，迭代器只能通过`++`或`--`移动到后继或前驱结点处，而不能使用`+n`或`-n`的操作。

![](./img/C7/7-5/1.png)

| list操作                | 描述                                                         |
| ----------------------- | ------------------------------------------------------------ |
| list<T> lst             | 创建空的list                                                 |
| list<T> lst(n)          | 创建含有n个元素的list                                        |
| list<T> lst(n, val)     | 创建n个值为val的list                                         |
| list<T> lst1(lst2)      | 使用lst2初始化lst1                                           |
| list<T> lst(begin, end) | 根据迭代器返回初始化list                                     |
| lst.size()              | 返回list元素个数                                             |
| lst.clear()             | 删除所有元素                                                 |
| lst.empty()             | 判断list是否为空                                             |
| lst.front()             | 返回第一个元素                                               |
| lst.back()              | 返回最后一个元素                                             |
| lst.insert()            | 插入一个元素                                                 |
| lst.erase()             | 删除一个元素                                                 |
| lst.push_front()        | 在头部添加一个元素                                           |
| lst.push_back()         | 在尾部添加一个元素                                           |
| lst.pop_front()         | 删除第一个元素                                               |
| lst.pop_back()          | 删除最后一个元素                                             |
| lst.remove()            | 删除元素                                                     |
| lst.reverse()           | 反转list                                                     |
| lst.sort()              | 排序                                                         |
| lst.unique()            | 去除相邻的重复元素（只留一个），函数并不是把重复的元素删除，而是全部放到数组尾部，返回去重后的尾地址。`unique()`中不自带`sort()`，因此需要先使用`sort()`进行排序 |
| lst.swap()              | 交换两个list                                                 |
| lst.splice()            | 合并两个list                                                 |
| lst.merge()             | 合并两个有序list                                             |

---

【代码】list

```c++
#include <iostream>
#include <list>

using namespace std;

void printList(list<int> lst) {
    for(list<int>::iterator iter = lst.begin(); iter != lst.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
}

int main() {
    list<int> lst;

    lst.push_back(11);       // [11]
    lst.push_front(22);      // [22, 11]
    cout << lst.front() << endl;    // 22
    cout << lst.back() << endl;     // 11

    lst.insert(++lst.begin(), 3);   // [22, 3, 11]
    lst.insert(--lst.end(), 2);     // [22, 3, 2, 11]
    lst.push_back(2);               // [22, 3, 2, 11, 2]
    printList(lst);

    lst.pop_front();                // [3, 2, 11, 2]
    lst.sort();                     // [2, 2, 3, 11]
    lst.unique();                   // [2, 3, 11]
    printList(lst);

    list<int> lst2{0, 9, 2, 8};
    // [2, 3, 11, 0, 9, 2, 8]
    lst.splice(lst.end(), lst2, lst2.begin(), lst2.end());
    printList(lst);

    lst.sort();             // [0, 2, 2, 3, 8, 9, 11]
    printList(lst);

    list<int> lst3{1, 2, 8};
    lst.merge(lst3);        // [0, 1, 2, 2, 2, 3, 8, 8, 9, 11]
    printList(lst);

    return 0;
}
```

> 运行结果

```
22
11
22 3 2 11 2
2 3 11
2 3 11 0 9 2 8
0 2 2 3 8 9 11
0 1 2 2 2 3 8 8 9 11
```

---



**forward_list**

`forward_list`和`list`的区别在于前者是单向链表，每个元素内部只有一个链接指向下一个元素，因此在存储方面`list`会消耗更多的空间。

![](./img/C7/7-5/2.png)

`forward_list`不支持反向迭代器，并且没有指向尾元素的迭代器，因此不提供`back()`、`push_back()`、`pop_back()`等操作。

<div style="page-break-after: always;"></div>

## 7.6 容器适配器

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
