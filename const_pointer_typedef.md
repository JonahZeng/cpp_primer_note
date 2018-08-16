# 关于const、指针、迭代器
-------------------------------
## const指针和指向const对象的指针
1. const指针指的是该指针指向的地址固定，不可以用其他对象地址赋值；
```c++
double pi = 3.1415926;
double e = 2.736;
double* const p = &pi;
p = &e; //error, 不能对const指针重新赋值
*p = e; //ok const指针指向的对象是可以被修改的
```
2. 指向const对象的指针，c++强制指针类型为指向const对象指针
```c++
const double pi= 3.1415926;
double* p = &pi ;//error, 指向非const对象的指针不可以被初始化为const对象指针
const double* p = &pi ;//ok
```

## const_iterator和const iterator区别

1. const_iterator的作用是迭代器指向的对象只读，不可以被修改
```c++
vector<int> vec(5, 10);//初始化为5个10
vector<int>::const_iterator it = vec.begin();
for(;it != vec.end(); it++)
{
    cout<<*it<<endl;//ok, 读取
    *it = 2;//error 不可以修改const_iterator指向的对象
}
```
2. const iterator即iterator本身的值是不可修改的(不可以指向其他对象)，但是它指向的对象是可以读取和修改的
```c++
vector<string> vec(3, "hello");
const vector<string>::iterator it = vec.begin();
vector<string>::iterator const it = vec.begin();//两种写法都可以，作用一样，和const 指针不同（mingw测试是这样的）
it++; //error， const迭代器不可以修改指向其他对象
*it = string("world"); //ok
```

## const和typedef
考虑一下以下代码：
```c++
typedef string* pstring;
const pstring p= "hello world!";
```
请问，p是什么类型？字面上看，是`const string*`，事实上，p的类型是`string* const`，大部分人的错误认知来源于c语言中的`#define`;
在这里， pstring已经是指针类型了，const修饰的就是指针;
```c++
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
    typedef string* pstring;
    string tmpStr = string("hello world");
    string str_b("hello cpp");
    const pstring e = &tmpStr;
    e = &str_b;//error 
    return 0;
}

```
编译错误提示：
```bash
[z00438418][ZENGYANGQIAO-PC] $ g++ iterator_const.cpp
iterator_const.cpp: In function 'int main(int, char**)':
iterator_const.cpp:12:7: error: assignment of read-only variable 'e'
     e = &str_b;
       ^
```
这里就说明了，e这个指针一旦初始化，就不能更改指向其他对象
