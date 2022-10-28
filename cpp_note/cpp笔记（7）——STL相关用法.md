# STL相关用法

## vector容器:

### vector构造函数

```C++
vector<T> v;//采用类模板实现，默认构造函数
vector(v.begin(),v.end());//将v[begin(),end())区间的元素拷贝给本身
vector(n, elem);//构造函数将n 个elem拷贝给本身
vector(const vector &vec);//拷贝构造函数
```

### vector赋值操作

```C++
//函数原型
vector& operator=(const vector *vec);
assign(begin,end);//vector.assign()给谁？
assign(n,elem);
```

### vector容量和大小

```C++
//函数原型
empty();//判断容器是否为空
capacity();//容器的容量，一般vector会扩大到比size大一点
size();//返回容器中的元素个数
resize(int num);//重新指定容器的长度为num，若容器边长。则以默认值填充新位置（用0 来填充）
		       //如果容器变短，则末尾超出容器长度的元素将被删除	
resize(int num, elem);//重新指定容器的长度为num，若容器变长，则以elem值填充新位置
					//如果容器变短，则末尾超出容器长度的元素将被删除。	
```

### vector的插入和删除

```C++
//函数原型
push_back(ele);
pop_back();//删除最后一个元素
insert(const_iterator pos,ele);//迭代器指向位置pos插入元素ele
	v1.insert(v1.begin(),100);//要有迭代器

insert(const_iterator pos,int count,ele);//迭代器指向的位置pos插入count个元素ele
	v1.insert(v1.begin(),2,100);

erase(const_iterator pos);//删除迭代器指向的元素
erase(const_iterator start,const_iterator end);//删除迭代器从start到end之间的元素
clear();//删除容器中所有元素
```

###  vector数据存取

```C++
//函数原型
at(int idx);//返回索引idx所指的数据
operator[];//返回容器idx所指的数据
front();//返回容器中的第一个数据元素
back();//返回容器中最后一个数据元素
#include<vector>
void test01(){
    vector<int>v1;
    for(int i=0;i < 10;i++){
        v1.push_back(i);
    }
    //利用[]方式访问将数组中的元素
    for(int i = 0; i < v1.size(); i++){
        cout<<v1[i]<<" ";
        
    }
    cout<<endl;
    //利用at的方式访问
    for(int i = 0; i < v1.size(); i++){
    	cout<<v1.at(i)<<" ";
        
    }
    cout<<endl;
    //获取第一个元素
    cout<<"第一个元素"<<v1.front()<<endl;
    //back同理
}
```

### vector互换容器

```C++
//函数原型
swap(vec);//将vec与本身的元素互换
```

```C++
//基本使用
void test01(){
	vector<int>v1,v2;
    for(int i = 0;i < 10;i++){
        v1.push_back(i);
    }
    for(int i = 10;i > 0;i--){
    	v2.push_back(i);
    }
    v1.swap(v2);//直接传进去
}
//巧用swap()可以大量空间
vector<int>(v).swap(v);
//vector<int>(v)匿名对象，当前行执行完就直接回收了
//swap(v)相当于直接互换指针指向，然后将器指向指向匿名对象指向的内存，这个v的内存就压缩了
```

### vector预留空间

- 减少vector在动态扩展容量时的扩展次数

```C++
//函数原型
reserve(int len);//容器预留len个元素的长度，预留位置不初始化，元素不可访问

```

```C++
//利用reserve来预留空间
v.reserve(100000);
//然后它的开辟次数就是1，直接一开始就开辟一个100000的空间
//统计开辟次数
int num = o;
int * p = NULL;
for(int i=0;i<100000;i++){
	v.push_back(i);
    if(p!=&v[0])
    {
        p = &v[0];//然后将这个指针指向那个的首地址；
        num++;//这里就是每一次开辟新的内存就会更新首地址，然后一旦首地址变化就记录下来
    }
}
```





### vector使用案例

#### vector存放内置数据类型

- 向容器中插入数据：使用push_back()函数（作用尾插数据，在数组尾部插入一个数据）

- ```c++
  #include<algorithm>
  #include<vector>
  void test01(){
      vector<int >v;// regard v as a number group
      v.push_back(10);
      v.push_back(20);
      v.push_back(30);
      v.push_back(40);
      vector<int>::iterator itBegin = v.begin();//起始迭代器，指向容器中的第一个元素
      vector<int>::iterator itend = v.end();//结束迭代器，指向容器的最后一个元素的下一位
      while(itBegin!=itend){
  		cout<<*itBegin<<endl;
          itBegin++;
      }
      //第二种的遍历，使用for循环（略）
      //第三种的遍历，for_each;
      for_each(v.begin(),v.end(),myprint)//myprint is a function .(only need insert the function name)
  ```

#### vector 存放自定义的数据类型

- ```C++
  #include<vector>
  #include<algorithm>
  class Person{
      public:
      Person(...){
          ....
      }
  	string _name;
      int _age;
  };
  void test01(){
      vector<Person> p;
      //vector<*Person> p;//这样也可以
      Person p1("",10);
      ..
          ..
          
      //向容器中添加数据
      v.push_back(p1);
      v.push_back(p2);
      v.push_back(p3);
      ..
      //输出
      for(vector<Person>::iterator it=v.begin();it!=v.end();it++){
          ....//里面的操作类似于指针。
      }
      
  }
  ```


#### Vector容器嵌套容器

1. 容器中嵌套容器，我们将所有数据进行遍历

   ```C++
   #include<vector>
   void test01(){
       vector<vector<int>>v;//在大容器vector中嵌套小容器是一个int类型的vector
       
       //创建小容器
       vector<int>v1;
       vector<int>v2;
       vector<int>v3;
       vector<int>v4;
       for(int i=0;i<4;i++){
           v1.push_back(i+1);
           v2.push_back(i+2);
           v3.push_back(i+3);
           v4.push_back(i+4);
       }
       //将小容器中的数据插入到大容器中
       v.push_back(v1);
       v.push_back(v2);
       v.push_back(v3);
       v.push_back(v4);
       //再通过大容器，把所又的数据遍历一遍
       for(vector<vector<int>>::iterator it = v.begin();it != v.end();it++){
           /*这里又一个问题就是，理解这个部分可以把嵌套的迭代器看成一个看成行指针（类比二维数组）  因为这个vector里面放的是vector的类型，所以又放了一个vector数组，所以这个而是一个指向小容器的行迭代器，解引用出来就是一个一级迭代器，类比于a[4][4]中的 ‘ *a ’ 就是一个指向第一行的指针 */
           //（*it）——————容器vector<int> 的迭代器
           for(vector<int>::iterator vit = (*it).begin();vir != (*it).end();vit++){
               cout<<*vit<<" ";
           } 
           cout<<endl;
       }
   }
   ```

   

# string 容器

### string 的基本概念

1. 本质：是一个类；

2. string 和char* 的区别：

   - char*是一个指针
   - string是一个类，类内部封装了char*，管理这个字符串，是一个char *型的容器。

3. 特点：

   - string类内部封装了很多成员方法

     🔸string管理char*所分配的内存，不用担心复制越界和取值越界等，由内部进行负责

### string构造函数

1. 构造函数原型；（再c++prime上可以查询）

### string赋值操作（待补充）

1. “ = ”的方法：

   ```C++
   //内部的=重载运算符
   string &operator=(const char* s);//char*类型字符串 赋值给当前的字符串
   str1="  ";
   string &operator=(const string &s);//把字符串s赋值给当前的字符串
   str1=str2;
   string &operator=(char c);//字符赋值给当前的字符串
   str='c';
   ```

2. str . assign（）方法

   ```C++
   string& assign(const char* s);//把字符串s赋值给当前的字符串
   string& assign(const char* s,int n);//把字符串s的前n个字符赋值给当前的字符串
   string& assign(const string &s);//把字符串s赋值给当前字符串
   string& assign(int n,char c);//用n个字符c赋值给当前字符串
   ```

### string字符串拼接

1. “ +=  ”的方法：

   ```C++
   string& operator+=(const char* str);//拼接字符常量
   string& operator+=(const char c);//拼接单个字符
   string& operator+=(const string& str);//拼接字符串
   ```

2. str . append（）

   ```C++
   append(const char *s);//接长
   append(const char*s,int n);//把字符串（常量）的前n个字符拼接到当前字符串
   append(const string &s);//
   append(const string &s ,int pos ,int n);//字符串s中从pos开始的n个字符连接到字符串结尾
   ```

### string查找和替换

1. find（）和rfind（）的区别：

   - rfind是从右往左，find是从左往右查，返回第一次出现的下标

2. 替换 replace（）

   <img src="C:\Users\夔whd\AppData\Roaming\Typora\typora-user-images\image-20220109112836934.png" alt="image-20220109112836934" style="zoom:80%;" />

### string字符串的查找

1. compare()

   - 相等返回0，>返回1，<返回-1。一般只用比较字符串是不是相等的

     ```C++
     //函数原型
     int compare (const string &s )const;
     int compare (const char* s)const;
     ```

### string字符存取

1. 通过“ [ ] ”

   ```C++
   char & operator[](int n);//函数原型 是传入一个序号，返回一个字符
   ```

2. 通过' at  '的方法（如果是改一个字符一般都是用 ' ' ）

   ```C++
   char& at(int n);//这个返回类型也是一个字符
   ```

### string中的插入与删除

1. 插入：

   ```C++
   string& insert(int pos, const char *s);
   
   string& insert(int pos, const string &str);
   //再指定位置插入n个字符 c
   string& insert(it pos,int n ,char c);
   
   ```

2. 删除

   ```C++
   //删除从pos往后数n个把他删掉，默认删到最后
   string& erase(int pos, int n=npos);//nops can be equal to -1.
   ```



### string字串

- 从字符串中获取想要的字串

  ```C++
  // function 原型
  string substr(int pos=0,int n = npos)const;//返回由pos到npos的区间范围的子串
  
  ```


# stack栈的相关用法

### 构造函数

stack<typename> s;

### 接口

push(),添加数据，

empty(void)，判断是不是为空

pop（void），出栈

top（void）返回栈顶的数据

size(void)返回栈的大小

# queue容器

### 基本概念：

只能访问到队头和队尾，不支持遍历的操作

<img src="C:\Users\夔whd\AppData\Roaming\Typora\typora-user-images\image-20220208104534008.png" alt="image-20220208104534008" style="zoom: 67%;" />

### 接口：

push()添加数据

front(void)，返回队头的数据

back(void)，返回队尾数据

empty（void），判断队列的是不是空

size(void), 返回栈的大小

# list容器（链表）

### list容器的构造函数：

1. push_back(datatype):添加数据
2. list<typename> ls(另一个list对象);//拷贝构造初始化
3. list<typename>ls (迭代器区间始，迭代器区间尾)//区间方式构造
4. list<typename>ls(n,elem)//n个数据

### 赋值&交换

<img src="C:\Users\夔whd\AppData\Roaming\Typora\typora-user-images\image-20220208105930974.png" alt="image-20220208105930974" style="zoom:80%;" />

### 容器的大小的操作

<img src="C:\Users\夔whd\AppData\Roaming\Typora\typora-user-images\image-20220208110248065.png" alt="image-20220208110248065" style="zoom:80%;" />

### 容器的插入和删除

<img src="C:\Users\夔whd\AppData\Roaming\Typora\typora-user-images\image-20220208110322797.png" alt="image-20220208110322797" style="zoom:80%;" />

### 数据存取

说明这里只能有两个因为和list容器的本身的性质有关，它只有双向的，不能随机访问

1. front(void);
2. back(void);

### 反转和排序

所有不支持随机访问迭代器的容器，不可以用标准算法，其内部会提供一些方法

1. 排序sort()

   - 如果是排序自定义的数据类型要自己指定排序的规则

   - 函数默认是升序排列若要降序排列就要使用外加函数

   - ```C++
     bool myCompare(int v1,int v2){
         return v1>v2;
     }
     //然后进行相关操作
     sort(myCompare);//直接传入函数名就可以了。
     ```

     

2. 反转reverse(void);

3. 排序案例

   - ```C++
     #include<iostream>
     #include<string>
     #includes<list>
     using namespace std;
     class Person{
         string m_name;
         int m_age;
         int m_height;
         public:
         Person(string name,int age,int height){
             m_name = name;
             m_age = age;
             m_height = height;
         }
         
     };
     //指定排序规则
     bool comparePerson(Person &p1,Person &p2){
         if(p1.m_age == p2.m_age){
             return p1.m_height>p2.m_height;
         }else{
             //按照年龄来升序
             return p1.m_age<p2.m_age;
         }
     }
     void test01(){
         ...
         //最后就直接
         L1.sort(comparePerson);
     }
     ```


# set/muitiset容器

### 基本概念：

- set不允许容器有重复的元素,所有的元素会在插入的时候自动排序
- multiset允许容器中有重复的元素

### set的构造函数

- ```C++
  set<typename>s1;//默认构造
  set<typename>s2(s1);//拷贝构造初始化
  ```

### 数据的插入

- insert（datatype）

### 大小和交换

- size(void)
- empty(void)
- swap(set)

### 插入和删除

注意会自动排序，所以第一个元素不是第一个插入的那个数据

<img src="C:\Users\夔whd\AppData\Roaming\Typora\typora-user-images\image-20220209110236230.png" alt="image-20220209110236230" style="zoom:80%;" />

### 查找和统计

![image-20220209110728027](C:\Users\夔whd\AppData\Roaming\Typora\typora-user-images\image-20220209110728027.png)

### set和muitiset的区别分析

- set插入数据的同时会返回插入结果，表示插入是否成功

- muitiset不会检测数据，因此可以插入重复数据

- ```C++
  //因为在源码方面set的insert返回的是一个对组，
  pair<iterator,bool> ret
  //所以就会在插入数据时判断是否重复
  ```

### 对组的创建

1. 功能描述：当需要使用一堆的数据组时

2. 创建方式：

   - pair<tyoe,type> p(value1, value2 );
   - pair<type, type> p = make_pair(value1, value2);

3. ```C++
   pair<string, int> p("Tom",20);
   p.first;//获取第一个数据
   p.second;//获取第二个数据。
   pair <string, int> p2 = make_pair("Tome",23);
   ```

set容器排序规则改变
