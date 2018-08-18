# 容器类
-----------
## 顺序容器类对象构造方法
通常的，有5种基本构造方法，以vector示范：
```c++
vector<int> vec;//默认构造函数，构造一个空对象
vector<int> vec(10);//构造10个默认元素值的vector对象，要求元素是c++内置数据类型或者提供了默认构造函数的类类型
vector<int> vec(10,1);//构造包含10个相同元素值的vector对象，要求元素具有一个形参的构造函数
vector<int> vec1(vec);//复制构造函数，要求元素支持复制构造，要求vec和vec1类型相同

int arr[5] = {0,1,2,3,4};
vector<int> vec(arr, arr+5);//两个参数都是迭代器类型，构造的vector对象包含的是两个迭代器之间的元素
```
|容器型    |  特性       |
|:-------:|:-----------:|
|vector   |支持快速随机访问，修改|
|list     |支持快速插入，修改|
|deque    |双端队列|
|stack    |支持后进先出|
|queue    |先进先出|

### 顺序容器元素约束条件
* 元素必须支持赋值操作
* 元素必须支持复制

不支持以上2个基本条件的典型类型有：
1. 标准库中的I/O stream类型
2. 标准库的auto_ptr类型
3. 引用类型

__注意__, 部分元素类型虽然满足以上两个条件，但是容器类的部分操作不支持，也就是说可以构造这样的类型容器类，但部分操作不支持；
另一个注意点是没有默认构造函数的类型：
```c++
class boy
{
public:
	boy(int age);
	~boy();
private:
	int age;
}

vector<boy> boy_vec(10);//error 没有默认构造函数
vector<boy> boy_vec(10, 13);//ok
```
## 所有容器类型的迭代器支持的基本操作
|operator|意义|
|:-----:|:-------:|
|*it|迭代器解引用，获取指向元素的引用|
|it->member|等同(*it).member|
|it++  ++it|自增，指向下一个元素|
|it--  --it|自减，指向前一个元素|
|it_1 == it_2|如果it_1, it_2指向同一个容器内的同一个元素，则返回true|
|it_1 != it_2|和==相反|

## vector/deque 单独支持的迭代器操作
|operator|意义|
|:-------|:----:|
|iter+n, iter-n|往后n个位置元素的迭代器， 往前n个位置的元素迭代器|
|iter_1 -= iter_2, iter_1 += iter_2|复合操作，iter_1减iter_2的值，赋给iter_1|
|iter_1 - iter_2|迭代器相减， 获取位置距离差|
|<, <=, >, >=|当一个迭代器指向的元素位于另一个迭代器指向的元素之前，则这个迭代器小于另一个迭代器|

因为只有vector和deque提供快速随机访问,其他顺序容器内部实现不是连续的，所有只能实现++,--,==,!=这样的相邻操作；
反序输出list的一个例子：
```c++
list<int> list_age(10);
list<int>::size_type cnt=0;
for(list<int>::iterator it = list_age.begin(); it != list_age.end(); it++, cnt++)
{
    *it = cnt;
}
//-----revert output----
list<int>::iterator it = list_age.end();
it--;
for(;it != --list_age.begin(); --it)
    cout<<*it<<endl;
//------revert output , with reverse_iterator
list<int>::reverse_iterator it = list_age.rbegin();
for(;it != list_age.rend(); ++it)
    cout<<*it<<endl;
```

