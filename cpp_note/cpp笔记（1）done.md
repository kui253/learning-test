

## ◻指针模块（问题）

### 指针的相关概念

#### 指针运算（*）

其实质上是个寻址的过程，去寻找以ptr为地址的目的地的内容。

这里的ptr是存储空间的地址，而这个地址是要在内存空间内合法获得的

🔴int*是定义指针所指向的类型，当你拿到起始单元的地址后，你要取出多少的字节来存储，这就是指针指向类型的作用。

<img src="C:\Users\夔whd\AppData\Roaming\Typora\typora-user-images\image-20211021230831090.png" alt="image-20211021230831090" style="zoom: 67%;" />

#### 地址运算（&）

就是计算一个变量或对象的地址并将其返回回来，可以将其赋值给指针。

### 动态内存分配

#### 动态申请内存操作符 new

- new 类型名T（初始化参数列表）

- ```c++
  //举例
  type_name*pointer_name= new type_name[num_elements]//这个[]是创建数组指针时采用
  type_name*pointer_name= new type_name[num_elements][num_elements]//维的长度（二维）
      eg.char(*fp)[3];  fp=new char[2][3];
  delete pointer_name//这个是对普通指针版本
  delete [] pointer_name//这个是对数组版本
  ```

  🔸PS.多维数组的首地址不是简单的指向数据对象的指针，是一个指向数组的指针。

  ​          eg、一个二维数组的首地址是一个指向一维数组的指针，既是指向行的指针。

  ​           <img src="C:\Users\夔whd\AppData\Roaming\Typora\typora-user-images\image-20211021170040969.png" alt="image-20211021170040969" style="zoom: 25%;" />

- 功能：在程序执行期间，申请用于存放T类型对象的内存空间，并依初值列表赋以初值。

- 结果值：成功：T类型的指针，指向新分配的内存；失败：抛出异常。

#### 使用new运算符初始化：

1. 如果要为内置的标量类型（如int or double）分配储存空间并初始化，可以在类型后面加上初值，并用（）括起。

   - ```c++
     int *pi=new int (6)//也可以使用大括号
     ```

2. 如果要初始化常规结构或数组，需要使用大括号的列表进行初始化

   - ```c++
     struct where {double x, double y,double z}
     where *one =new where{1.1,1.2,1.3}
     
     int* ar=new int[4]{2,4,6,8}
     ```

#### 定位new运算符：

1. 说明：new负责在堆（heap）中找一个足以能够满足要求的内存块。能够指定要使用的位置。

   ​           要使用定位new特性，首先需要包含头文件new🔸然后将new运算符用于提供了所需地址的参数。

2. 使用：

   - ```c++
     //在堆中分配新内存
     int *p3;
     p3=new int[20];//在heap中开辟一个数组来存储。
     ```

   - ```c++
     //在数组中分配位置。
     char buffer[50];
     int *p4;
     p4=new (buffer)int [20];//在buffer内存中分配一部分int内存（相当于将一个数组放入buffer数组中）。并且给新的数据分配时，可以重写入buffer的值。
     ```

3. 注意：

   - 使用定位new运算符分配的内存不能使用delete来释放。buffer指定的内存是静态内存而delete只能用于这样的指针：🔸指向常规new运算符分配的堆内存🔸而buffer不归delete管

#### 释放内存操作符delete

- delete 指针p
- 功能：释放指针p所指向的内存。p必须是new操作的返回值。

```c++
#include <iostream>
using namespace std;
int main() {
cout << "Step one: " << endl;
Point *ptr1 = new Point; //🔸调用默认构造函数（之前有个类我删了）
delete ptr1; //删除对象，自动调用析构函数。🔸这里删除的是其指向的对象而不是ptr1这个指针，所以后面还可以对这个指针赋值🔸
cout << "Step two: " << endl;
ptr1 = new Point(1,2);
delete ptr1;
return 0;
}
```



```c++
#include < iostream>
using namespace std;
int main() 
{
int (*cp)[9][8] = new int[7][9][8];//🔸定义一个2维数组，它有[7]个元素，类似上面的
for (int i = 0;i < 7;i++)
    for (int j= 0;j < 9;j++)
        for (int k = 0;k < 8; k++)
            *(*(*(cp + i) +j)+k)=(i*100 +j*10 + k);//🔸这里的*运算实质上是数组运算，它等价于数组形式
for (inti =0;¡ < 7;i++){                           
    for(intj= 0;j < 9;j++){
        for (intk = 0;k < 8; k++)
            cout << cp[i][j][k]<<" ";
        cout << endl;
    }
    cout < < endl;
}
delete[] cp;
return 0;
}
```

### 字符串指针:

- <img src="C:\Users\夔whd\AppData\Roaming\Typora\typora-user-images\image-20211130080159496.png" alt="image-20211130080159496" style="zoom:67%;" />

- ![3](C:\Users\夔whd\AppData\Roaming\Typora\typora-user-images\image-20211130080227098.png)

- ![image-20211130080250189](C:\Users\夔whd\AppData\Roaming\Typora\typora-user-images\image-20211130080250189.png)

- 🔸字符串指针的赋值：如果是要赋值给一个新定义的数组，那要再数组的最后面加上结束符（\0）。

### 指针数组：

#### 指针数组的定义：

```c++
int a[3][4],(*p)[4];
p=a;//这样p就是指向a的指针。
```

#### 指针运算法则：

```c++
*(pt+1)[2] ＝*((pt+1)[2])＝*(*(pt+1+2))＝*(*(pt+3))=pt[3][0]//中括号相当于是将其中的值加在指针内部。
```

<img src="C:\Users\夔whd\AppData\Roaming\Typora\typora-user-images\image-20211130075731920.png" alt="image-20211130075731920" style="zoom:67%;" />



```c++
a[1]=*(a+1)/ *(a+1)+2=&a[1][2]/ *(*(a+1)+2)=a[1][2]

**(a+1)=*(a[1])=*(*(a+1)+0)=a[1][0]

(*(a+1))[1]=*(*(a+1)+1)=a[1][1]
    
*(a+1)[1]=*((a+1)[1])=*(*((a+1)+1))=**(a+2)=a[2][0]

```

<img src="C:\Users\夔whd\AppData\Roaming\Typora\typora-user-images\image-20211130080003759.png" alt="image-20211130080003759" style="zoom:67%;" />

- 🔸为什么会这样来访问，因为数组的存储形式是连续的所以它的地址是一一相邻的，所以可以通过直接增加列指针的值来访问每一个元素

- 🔸注意传入的指针级数要对应，不能一级对两级

  ```c++
  int peakpoint(int* s, int i, int j) {/*所以这里只需要在函数原型里定义一个一级指针的形参就可以 了，否则会报错*/
      int MAX = 0, max = 0,flag=1;
      
      for (int i1 = 0; i1 < ROW; i1++)
      {
      //然后再这里访问定义的数组的每个元素是要使用相乘的形式不能使用最开始的数组形式。              
          if ( flag) 
          {
              for (int j1 = 1; j1 < COL; j1++)
              {
                  if (*(s+i1*5 + max) < *(s+i1*5 + j1)) max = j1;
              }
              flag = 0;
          }
      
      
          if (*(s + MAX * 5 + max) < *(s + i1* 5 + max))
          {
              MAX = i1;
          }
          
      }
      if (i == MAX && j == max)
          return 1;
      else
          return 0;
  }
  /**********  End  **********/
  
  void main(void)
  {
      int s[ROW][COL] = { {7,2,9,4,6},{5,6,1,8,3},{9,8,6,3,9},{5,1,9,7,2} };
  
      int i, j;
  
      for (i = 0; i < ROW; i++)
          for (j = 0; j < COL; j++)
              if (peakpoint(&s[0][0], i, j)) {//这里的传入的是一个一级指针
                  cout << "峰点的坐标之一=(" << i + 1 << ',' << j + 1 << ')' << endl;
                  cout << "峰点的坐标之值=" << s[i][j] << endl;
                  return;
              }
  
  ```

  

### 结构体指针：

#### 形式：

```c++
struct student 
{
   	string name ;
   	int age ;
    double weight;
}
student s={xxx,10,10.0}
student *p=&s;//就是将结构体s的地址赋值p，p就是一个指向结构体的指针
```

#### 访问方式:

- 使用->来访问里面的属性。

#### 结构体做函数的参数：

1. ```c++
   void printStudent(student stu)//值传递。
   void printStudent(student* stu)//指针左形参。
   {
      //在这里面就要直接使用->来改变结构体里面的变量。
       stu->name;
       ....
   }
   //在使用的时候就是直接用&
   printStudent(&s)//把地址传输给函数就可以了。
   ```

2. 优点：可以大大的节约内存。不用直接复制一个副本过去。

#### const在结构体里的使用：

- 防止在函数里面将结构体的数据修改，确保结构体里的数据的完整性。

  ```c++
  struct student s;
  void printStudent(const student *stu)
  {
      //这样你在函数中使用stu->时就会直接报错。
  }
  ```

  

### 指针作函数参数（类似引用）

#### 作用

1. 需要数据双向传递时（引用也可以达到此效果）
2. 用指针作为函数的参数，可以使被调函数通过形参指针存取主调函数中实参指针指向的数据，实现数据的双向传递
3. 需要传递一组数据，只传首地址运行效率比较高
4. 实参是数组名时形参可以是指针

```c++
#include<iostream> 
using namespace std;
void splitFloat(float x, int *intPart, float *fracPart) {//通过指针连接值所在的地址，然后（*）取其中的值，直接操作的是实                                                            参是值
   *intPart = static_cast(x); //取x的整数部分
   *fracPart = x - *intPart; //取x的小数部分
}
int main() {
  cout << "Enter 3 float point numbers:" << endl;
  for(int i = 0; i < 3; i++) {
    float x, f;//🔸PS.float 类型不能直接比较大小，应为float类型是近似储存的，可能是在后面的位数的不一样的。如果要比较
    int n;     //🔸那就拿两个做差，误差在多少位时就可以说是相等
    cin >> x;
    splitFloat(x, &n, &f);	//变量地址作为实参🔸这也说明&与指针的参数是几乎等价的。
    cout << "Integer Part = " << n << " Fraction Part = " << f << endl;
  }
  return 0;
}
```

#### 指针数组作函数参数：

```c++
//对于一个数组arr
int sum_arr(int * arr, int n)
 //这里的*arr也可写成arr[]。这两者只有在指针数组做参数时才等价
```



### 指针类型的函数

#### 注意：

🔸在没有接收指针为参数的函数中，我们不能在把函数中定义形参指针付给外部指针然后修改外部指针，这是一项很危险的操作

```c++
int main(){
int* function();
int* ptr= function();
 *ptr=5; //🔸危险的访问!ptr在函数中得到一个形参指针，但函数结束后地址内存就被释放了，通过外部在访问其中的地址并赋值是非法的
return 0;//🔸但如果的用new来分配内存，可以不用担心，因为new只有delete才可以释放，所以函数结束后不会消失。
}
int* function(){
int local=0; //非静态局部变量作用域和寿命都仅限于本函数体内return &local;
}//函数运行结束时,变量local被释放
```



```c++
#include < iostream>
using namespace std;
int main(){
   int array[10]; //主函数中定义的数组，
   int* search(int* a, int num);
   for(inti=0; i<10; i++)
   cin> > array[i];
   int* zeroptr= search(array, 10); //将主函数中数组的首地址传给子函数，函数通过*来取得地址中的值
 return 0;
}
int* search(int* a, int num){ //指针a指向主函数中定义的数组for(int i=0; i<num; i++)
if(a[i]==0) .
return &a[i]; //返回的地址指向的元素是在主函数中定义的
}//函数运行结束时, a[i]的地址仍有效

```

### 指向函数的指针

#### 函数指针的定义

##### 定义类型

存储类型  数据类型（*函数指针名）（）；括号里一般是int 、double、string这些关键字，不带参数n k什么的

🔸PS.通常，要声明函数的指针，可以首先编写这种函数的原型，然后用（*pf）替换函数名。这样pf就是函数指针了。正确声明后

​      就可以将相应的函数的地址赋值给它

<img src="C:\Users\夔whd\AppData\Roaming\Typora\typora-user-images\image-20220326140514419.png" alt="image-20220326140514419" style="zoom: 80%;" />

```c++
double pam(int);
double (*pf)(int);//这里是创建了函数的指针
pf=pam;//🔸PS.pam()的特征标必须和返回类型与pf相同。否则报错。
```



##### 含义

函数指针指向的是程序代码存储区

##### 作用（实现函数回调）

- 通过函数指针调用的函数

  ​    例如将函数的指针作为参数传递给一个函数，使得在处理相似事件的时候可以灵活的使用不同的方法。

- 调用者不关心谁是被调用者

  ​    需知道存在一个具有特定原型和限制条件的被调用函数。

```c++
#include <iostream>
using namespace std;
int compute(int a, int b, int(*func)(int, int))//🔸PS.这个函数将一个函数指针作参数，实现后面的函数回调，可以直接使用
{ return func(a, b);}
int max(int a, int b) // 求最大值
{ return ((a > b) ? a: b);}
int min(int a, int b) // 求最小值
{ return ((a < b) ? a: b);}
int sum(int a, int b) // 求和
{ return a + b;}
int main()
{
int a, b, res;
cout << "请输入整数a："; cin >> a;
cout << "请输入整数b："; cin >> b;
res = compute(a, b, & max); //🔸也可以直接写函数的函数名，不加地址运算符，因为函数名也是函数的地址
cout << "Max of " << a << " and " << b << " is " << res << endl;
res = compute(a, b, & min);
cout << "Min of " << a << " and " << b << " is " << res << endl;
res = compute(a, b, & sum);
cout << "Sum of " << a << " and " << b << " is " << res << endl;
}


```

## 数组与指针的相关辨析：

### 指针数组（eg.  int   * f[2]）

- 说明：这里的f是一个指针数组，f[0]、f[1]都是一个指针，此时 f 就是一个二级指针

  ```C++
  //这里可以直接赋值
  int *f1[2];
  int **f3 = f1;//（编译器不会报错，且可以成功运行）这就说明f是一个二级指针。
  ```

  ![image-20220108082217309](C:\Users\夔whd\AppData\Roaming\Typora\typora-user-images\image-20220108082217309.png)

- 可以看到f1解引用（可以理解为取值操作）得到的是 f1[0] （这也是一个指针）说明 f1 中储存的就是f1[0] 的地址，其他同理可推

  <img src="C:\Users\夔whd\AppData\Roaming\Typora\typora-user-images\image-20220108083411207.png" alt="image-20220108083411207" style="zoom:80%;" />

### 数组指针（eg. int  (*f)[2]  ）

- 说明：int (*f)[2] 多维数组的首地址不是简单的指向数据对象的指针，是一个指向数组的指针。

  ​		理解：相当于是将f解引用后是取其第2个元素是一个int类型，但它不是一个二级指针

  一个二维数组的首地址是一个指向一维数组的指针，既是指向行的指针。

  <img src="C:\Users\夔whd\AppData\Roaming\Typora\typora-user-images\image-20211021170040969.png" alt="image-20211021170040969" style="zoom: 25%;" />

  定义了一个名为fp的指针变量，该指针指向一个3元数组，fp是一个指针变量，可以重新赋值；

- 这也是二维数组名的本质：

  - 当对一个（上面的例子）a 它是指向第一行第一个元素的指针，然后a+1就是指向第二行的指针（相当于行数加1）对它解引用（*a 或 *（a+1））就相当于a[0]、a[1]，然后在给它解引用（   e.g.: *（（ *a +0））或

  ​       *（ *（a+1）+0）这就相当于a【0】【0】、a【1】【0】)

  - 然后它还可以这样访问：(*(a + 1))[1]，这个意思就是先对a+1解引用后再取（a+1）指向这一行（因为这一行是一个一维数组）的内容中的第二个元素

  -  🔸🔸注意：不能   *(a + 1)[1]，因为运算符（）的优先级比 [  ]的高，但是 [  ]运算符的优先级比 *的高，所以它会先对（a+1）还未解引用就取它的第二个元素，直接是一个随机数据，因为 a+1是一个指向行的指针，它本身没有第二个元素。

    ![image-20220108100350679](C:\Users\夔whd\AppData\Roaming\Typora\typora-user-images\image-20220108100350679.png)

  

### 关于为什么‘  数组名  ’和 ‘  &数组名  ’得到的是一个东西

- 说明：对于一个数组char s[0]。

  在说明这个事之前，有必要看一下汇编代码，用GDB查看后发现：

  - 对于char s[0]来说，汇编代码用了lea指令，lea  0x04(%rax),  %rdx
  - 对于char*s来说，汇编代码用了mov指令，mov 0x04(%rax),  %rdx

  🔸lea全称load effective address，是把地址放进去，而mov则是把地址里的内容放进去。

  🔸访问成员数组名其实得到的是数组的相对地址，而访问成员指针其实是相对地址里的内容（所以成员指针取地址后和数组名是一个东西）

  🔸对于数组 char s[10]来说，数组名 s 和 &s 都是一样的，而对于一个二维数组，a[2] [2]，*a与 a （默认指向第一个元素？）得到的是一个东西（repeat: 这里的a是一个行向量指针,a[0]、a[1]分别是指向第一第二行（首元素）的指针）

  ```C++
  cout <<"a+1:"<< a + 1 << "\t*a+1:" << *a + 1 << "\t*(a+1):"<<*(a+1) << endl;
  ```

  ![image-20220108101232276](C:\Users\夔whd\AppData\Roaming\Typora\typora-user-images\image-20220108101232276.png)

​	



## ◻Tips小结

#### 🔻const 的位置与作用

🔸1、const int * pointer=&xxx 

🔸2、int*const pointer =&xxx

<img src="C:\Users\夔whd\AppData\Roaming\Typora\typora-user-images\image-20211021145904156.png" alt="image-20211021145904156" style="zoom:25%;" />

#### 🔻指针数组存储二维数组

```c++
#include<iostream>
using namespace std;
int main(){
    int line1[]={1,0,0};
    int line2[]={0,1,0};
    int line3[]={0,0,1};
    //定义整型数组指针并初始化
    int *pLine[3]={line1,line2,line3};//🔸请实与无*的数组差不多，
    cout<<"Matrix test:"<<endl;
    //输出矩阵
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)
            cout<<pLine[i][j]<<" ";   
        cout<<endl
    }
    return 0;
}
```

#### 🔻有返回值的函数递归(一般为单变量)

```c++
//举例一个int类型的函数
int function_1(int x)
{
    int m;
    if(x==0)
        return 1;//这里相当于定义function_1(0)的值。
    m=5* function_1(x-1);
    return m;
}
```

#### 🔻数据类型的自动转换

1. 若参与运算的量的类型不同，则首先需要将其转换成同一类型，然后再运算。

2. 转换按数据长度增加的方向进行，以保证精度不降低。

     eg.int类型和long类型运算时，先把int类型转换成long型后再进行运算。

## 

## ◻字符串

#### 用字符数组存储字符串（C风格字符串）

- 例如

​       char str[8] = { 'p', 'r', 'o', 'g', 'r', 'a', 'm', '\0' };🔸//' ' 与" "的区别是前者是某个字符串的ASCII码，后者是字符。

​       char str[8] = "program";

​       char str[] = "program";这也是字符串。

|  p   |  r   |  o   |  g   |  r   |  a   |  m   |  \0  |
| :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: |

🔸PS.字符串最后一定是以\0结尾。

- ​	注意这样声明的char可以直接用cout 加数组名来输出，但是要是赋值就要使用strcpy（）

```c++
#include<iostream>
using namespace std;
int main() {
	char s1[100];
	char s2[100];
	cin >> s1 >> s2;//这里可以直接cin，它会在最后面加上一个\0.
	int i=0, k = 0;
	while (s1[i + k]) {//这种题就是一个思路，改变一个k的值
		for (i = 0; s1[i + k] && s2[i] && s1[i + k] == s2[i]; i++) {
			
		}
		if (!s2[i]) {
			cout << k + 1 << "\n" << k + i << endl;
			break;//这里直接跳出，防止重复计算
		}
		k++;
	}
	if (!s1[i + k])cout << -1 << endl;
	return 0;
}
```



#### string类

- 使用字符串类string表示字符串
- string实际上是对字符数组操作的封装

#### string类常用的构造函数

- string(); //默认构造函数，建立一个长度为0的串

  例：string s1;

- string(const char *s); //用指针s所指向的字符串常量初始化string对象

  例：string s2 = “abc”;

- string(const string& rhs); //复制构造函数

  例：string s3 = s2;

  

#### string类的运算

- s = t 用t更新s
- s + t 将串s和t连接成一个新串
- s == t 判断s与t是否相等
- s != t 判断s与t是否不等
- s < t 判断s是否小于t（按字典顺序比较）
- s <= t 判断s是否小于或等于t （按字典顺序比较）
- s > t 判断s是否大于t （按字典顺序比较）
- s >= t 判断s是否大于或等于t （按字典顺序比较）
- s[i] 访问串中下标为i的字符🔸🔸🔸

#### cin.get()&cin.getline()的相关问题

- 当一次键盘输入结束时会将输入的数据存入输入缓冲区，而cin函数直接从输入缓冲区中取数据。正因为cin函数是直接从缓冲区取数据的，所以有时候当缓冲区中有残留数据时，cin函数会直接取得这些残留数据而不会请求键盘输入，这就是例子中为什么会出现输入语句失效的原因！

- cin>>该操作符是根据后面变量的类型读取数据。输入结束条件  ：遇到Enter、Space、Tab键。(这个很重要！)。对结束符的处理 ：将缓冲区中使得输入结束的结束符(Enter、Space、Tab) 读字符保留，不会清除其中的值。

- cin.get(array,size)输入超长，则按需要的长度取数据。

- 🔸cin.get()不带参数返回的是一个int类型的值，所以要用(mu=cin.get())!='\n'或者cin.get()!='\n'才可以，不能直接cin.get（char）!='\n'

  ```c++
  while(!(cin>>golf[i])){
      cin.clear;//reset input
      while(cin.get()!='\n')//根据前面的叙述，错误输入或是溢出的会进入缓冲区，而下一次cin、cin.get()就会接受其中的值
          continue;         //这里使用continue可以直接再次进入循环继续用其接受，然后clear。
      cout<<"please enter a number:"
  }
  ```

  

- 读取字符串的情况：cin.get(array_name, Arsize)是用来读取字符串的，可以接受空格字符，遇到Enter结束输入，按照长度(Arsize)读取字符。

  

- ```c++
  using namespacestd;
  int main (){
         char ch, a[20];
         cin.get(a, 5);
         cin>>ch;
         cout<<a<<endl;
         cout<<(int)ch<<endl;
         return 0;
  }//测试一输入：12345[Enter]输出：123453【分析】第一次输入超长，字符串按长度取了"1234"，而'5'仍残留在缓冲区中，所以第二次输入字符没有从键盘读入，而是直接取了'5'，所以打印的ASCII值是53('5'的ASCII值)
  ```

- ```c++
  #include <iostream>
  using namespace std;
  int main (){
         charch, a[20];
         cin.getline(a,5);
         cin>>ch;
         cout<<a<<endl;
         cout<<(int)ch<<endl;
         return0;
  //cin.getline() :cin.getline()与 cin.get(array_name,Arsize)的读取方式差不多，以Enter结束，可以接受空格字符。按照长度(Arsize)读取字符, 会丢弃最后的Enter字符。但是这两个函数是有区别的：cin.get(array_name, Arsize)当输入的字符串超长时，不会引起cin函数的错误，后面的cin操作会继续执行，只是直接从缓冲区中取数据。但是cin.getline()当输入超长时，会引起cin函数的错误，后面的cin操作将不再执行。
  ```

- voidios::clear(iostate _State=goodbit);
  该函数用来重置标识变量，_State是用来重置的值，默认为goodbit，即默认时将所有标志位清零。用户也可以传进参数，如：clear(failbit)，这样就将标识变量置为failbit(即：001)。我们一般是用它的默认值，当cin出现异常，我们用该函数将所有标志位重置。如果cin出现异常，没有重置标志的话没法执行下一次的cin操作。

  ​    🔸clear()是将所有标志清零，再置以参数新的标志。但是它只是清除cin的错误标志，但不会清空缓冲区。
  
- ```c++
  #include<iostream>
  using namespace std;
  int main ()
  {
  char ch, str[20];
  cin.getline(str, 5);
  cout<<"flag1:"<<cin.good()<<endl;   // 查看goodbit状态，即是否有异常
  cin.clear();                        // 清除错误标志
  cout<<"flag1:"<<cin.good()<<endl;   // 清除标志后再查看异常状态
  cin>>ch; 
  cout<<"str:"<<str<<endl;
  cout<<"ch :"<<ch<<endl;
  return 0;
  }
  输出：
  flag1:0 // good() 返回false说明有异常
  flag2:1 // good()返回true说明，clear()已经清除了错误标志
  str:1234
  ch :5
  /*【分析】程序执行结束还是只执行了一次读操作，cin>>ch还是没有从键盘读取数据，但是与程序8中不同，这里打印了ch的值为'5'，而且在cin>>ch之前已经清楚了错误标志，也就是cin>>ch的读操作实际上执行了。这就是前面讲的cin读取数据的原理：它是直接从输入缓冲区中取数据的。此例中，第一次输入"12345",而getline(str, 5)根据参数'5'只取缓冲区中的前4个字符，所以str取的是"1234"，而字符'5'仍在缓冲区中，所以cin>>ch直接从缓冲区中取得数据，没有从键盘读取数据！
  也就是当前一次读取数据出错后，如果缓冲区没有清空的话，重置错误标志还不够！要是能将缓冲区的残留数据清空了就好了*/
  
  ```

- basic_istream&ignore(streamsize _Count = 1, int_type _Delim = traits_type::eof());
  function: Causes a number of elements to be skipped from the current readposition.
  Parameters:
  _Count, The number of elements to skip from the current read position.
  _Delim, The element that, if encountered before count, causes ignore to returnand allowing all elements after _Delim to be read. (引用msdn)
  这个函数用来丢弃输入缓冲区中的字符，第一参数定义一个数，第二个参数定义一个字符变量。下面解释一下函数是怎样执行的：函数不停的从缓冲区中取一个字符，并判断是不是_Delim，如果不是则丢弃并进行计数，当计数达到_Count退出，如果是则丢弃字符退出。例：cin.ignore(5, 'a'); 函数将不断从缓冲区中取一个字符丢弃，直到丢弃的字符数达到5或者读取的字符为'a'。

- ```c++
  #include <iostream>
  using namespace std;
  int main ()
  {
  cin.ignore(5, 'a');
  return 0;
  }
  测试一输入：
  c[enter]
  c[enter]
  c[enter]
  c[enter]
  c[enter]
  测试二输入：
  c[enter]
  c[enter]
  a[enter]
      //其实该函数最常用的方式是这样的，将第一个参数设的非常大，将第二个参数设为'\n'，这样就可以缓冲区中回车符中的所有残留数据，因为一般情况下前面输入残留的数据是没有用的，所以在进行新一次输入操作前将缓冲区中所有数据清空是比较合理。如：cin.ignore(1024, '\n'); 
  ```

## ◻逻辑运算符

### 🔸短程运算

- &&与！运算若判断前面的表达式是正确的就不会进行后面的运算。

### 🔸逗号运算

- 运算法则：对于一个括号里的几条括起来的语句赋值z=（expression1，expression2，expression3）则先赋值3。其他的直接跳过。

- "，"在for循环中的运用

  ```c++
  for(j=0,i=word.size()-1;j<i;i--,j++)//这里先执行j++然后执行i--，也是由右向左。
  {
      temp=word[i];
      word[i]=word[j];
      word[j]=temp;
  }
  ```




## ◻二维数组输出图形

1. 如果是要输出数字，则可以先将所有的二维数组元素都赋值为"0"，然后再修改其中的值。

   - eg.在这之后，像杨辉三角，我们先可以全赋一遍0，然后把边界值赋完。最后两两相加即可。

     ```c++
     #include<iostream>
     using namespace std;
     const int level = 19;//先定义两个常量。
     const int divs = 10;
     int main() {
     	int yh[divs][level];
     	int mid = (level - 1) / 2//找中间值。
     	for (int j = 0; j < divs; j++) {
     		for (int i = 0; i < level; i++)
     			yh[j][i] =0;//然后开始赋值为0.
     	}
     	yh[0][mid] = 1;
     	for (int m = 1; m < divs; m++)
     	{
     		yh[m][mid - m] = 1;
     		yh[m][mid + m] = 1;
     	}//开始赋值外圈。
     	for (int n1 = 1; n1 < divs; n1++)
     		for (int n2 = 1; n2 < level-1; n2++)
     			yh[n1][n2] = yh[n1 - 1][n2+1] + yh[n1 - 1][n2 - 1];//前两项相加得后面一项，运算
     	for (int j1 = 0; j1 < divs; j1++) {
     		for (int i1 = 0; i1 < level; i1++)
     			cout << yh[j1][i1]<<"\t";//最后一个循环将所有是值打印。
     		cout << endl;
     	}
     	return 0;
     }
     ```
     

1. 如果是要输出图新，则要用char 先全部赋值为空格，然后再给其符符号。

   - ```c++
     #include<iostream>
     const int y = 10;
     const int x = 21;
     int main() {
     	using namespace std;
     	int mid = (x - 1) / 2;
     	char pic[y][x];
     	for (int j = 0; j < y; j++) {
     		for (int i = 0; i < x; i++)
     			pic[j][i] = ' ';//全部赋值为空格。
     	}
     	pic[0][mid] = '*';
     	for (int j1 = 1; j1 < y; j1++)
     		if (j1 % 2 == 0) {
     			for (int i1 = 0; i1 < j1 + 1; i1 = i1 + 2)
     			{
     				pic[j1][mid] = '*';
     				pic[j1][mid - i1] = '*';
     				pic[j1][mid + i1] = '*';
     			}//奇数直接要赋中间值，然后等差2向外赋值。
     		}
     		else {
     			for (int i2 = 1; i2 < j1 + 1; i2 = i2 + 2)
     			{
     				pic[j1][mid - i2] = '*';
     				pic[j1][mid + i2] = '*';
     			}//偶数直接向外加然后赋值
     
     		};
     	for (int m = 0; m < y; m++) {
     		for (int n = 0; n < x; n++)
     			cout << pic[m][n] << " ";
     		cout << endl;//最后直接全部输出。
     	}
     
     return 0;
     }
     ❓1//我能不能直接使用前面的i&j加","直接优化程序
         anwser：不能使用，因为在每行完后要有一个endl来换行，而两个连一块实现不了这个换行
     ❓2//能不能不限于直线边，可不可以直接以二次函数为边，或者直接加两个直角三角形，用一个二维数组。
     ```
   
1. 通过指针来表示二维数组的各个元素：

   - ```c++
     eg.int (*p)[4];//这里的p是指向int类型的指针然后每个有四个元素。
     int a[3][4];
     p=a;
     //这里p、p+1、p+2对应的是二维数组的第1、2、3行，然后其中的元素的每行中的a[][i]。
     ```

   - 表示方式

     ```c++
     a[2][3]  *(*(a+2)+3);
     ```

     <img src="E:\图片\md笔记图片\IMG_20211123_093809.jpg" style="zoom:25%;" />

## ◻函数模板

#### 作用和功能：

- 函数模板是通用的函数描述；他们用泛型来定义函数。

- 由于模板允许以泛型的方式编写程序，因而有时也被称为通用编程。

- 一般将其放在头文件中，并在需要使用模板的文件中包含头文件。

  ```c++
  template<typename AnyType>
  void Swap(AnyType  &a,AnyType &b)//声明函数时声明这部分；
  {
      AnyType temp;
      ……
  }
  ```

#### 局限性：

- 在模板函数的定义里面不能够使用一般的运算符，因为如果AnyType是数组，或者是结构，指针什么的，将不能进行运算。

#### 显式具体化：

- 对于给定的函数名，可以有非模板函数、模板函数和显示具体化函数以及它们的重载形式。

- 显式具体化的原型和定义应以template<>打头，并通过名称来指出函数。

- 具体化优先于常规模板，而非模板函数优先于具体化和常规模板。

  ```c++
  eg.
      template<>void Swap <job>(job &,job &)
      or template<>void Swap(job &, job &)//中间的那个job（参数类型）可要可不要
  ```

#### 显式实例化：

- 语法声明：template void Swap <int>(int ,int)

  ​                   意味不用使用Swap模板来生成函数定义，而应使用专门为int类型显式定义的函数定义。

#### 显式具体化：

- 语法声明：template<>void Swap <int>(int &,int&)

  ​                  template<>void Swap(int &,int&)   

  ​                🔸意味着使用模板函数来生成int 类型的函数定义。              

#### 优先级：

- 指向非const数据的指针和引用优先于非const指针和引用参数匹配。
- 非模板类函数将优先于模板函数。
- 如果完全匹配的都是模板函数，则较具体的模板函数优先。

#### 关键字decltype：

- 作用：可以使两个变量类型等价；

  ```c++
  decltype (expression)var;//将表达式的类型表明为var的类型；
  decltype(function(...))var;//则将var的类型等价为函数返回的类型。
  
  double xx=4.4;
  decltype((xx))r2=xx;//expression为一个左值，则var为指向其类型的引用。即double &。
  
  //结合使用typedef和decltype
  typedef decltype (x+y) xytype;
  xytype xpy=x+y;
  ```

## ◻命名空间

#### 命名空间的特性：

- 通过定义一个新的声明区域来创建命名空间。目的是提供一个声明名称的区域。🔸一个命名空间中的名称不会和其他的命名

  空间的相同名称发生冲突。同时允许程序的其他的部分使用该命名空间中声明的东西

  ```c++
  namespace xxx{//可以在其中声明一些东西。
      double...;
      int....;
      void...;
      struct.....;
  }
  ```

- 名称空间可以是全局的，也可以位于另一个名称空间中🔸但不能位于代码块中

- 名称空间是开放的，即可以把名称加入到已有的名称空间中.由此可以在后面直接在命名空间中加入函数的定义。

  ```c++
  namespace jill{
      char * goose(const char*);
  }
  ```

#### 名称空间的使用：

🔸操作规范：一般可以将名称空间放头文件里。

- 通过作用域解析运算符：：，使用名称空间来限定该名称。

  ```c++
  jack::pail=...;
  jack::hill(这是个结构)  mole//说明使用jack命名空间的hill结构来声明一个结构。
  ```

- using声明：

  ```c++
  using jill::fetch;//using声明，将特定名称添加到它所属的声明区域中。
  //相当于函数声明，把位于某个命名空间的函数或其他声明出来，以便使用。
  ```

  1. ​	对一个全局变量fetch，若在某个代码块里也有一个fetch局部变量，就可以使用：：fetch来使用全局变量。

- using 编译指令：

  1. 使用：其由名称空间和它前面的关键字using namespace组成，这使得命名空间里的所有名称都可以使用，

     ```c++
     using namespace jack；
     ```

- 名称空间的嵌套：

  ```c++
  namespace elements{
      namespace fire{
          int flame;
          .....
      }
      float water;
     .....
  }
  ```

  则要使用flame，则需要

  ```c++
  using namespace elements::fire::flame;
  ```

  或者要在其他名称空间里使用其他名称空间，也可以在其他名称空间里使用

  ```c++
  namespace jack{
      using jill::fetch;
      using namespace elements;
      using ......;
  }//如果要访问fetch，可以使用cin>>myth::fetch
  //or cout<<jill::fetch;
  ```

- 名称空间的"="运算

  1. 设置别名

     ```c++
     namespace mvft=jill//mvft是jill 的别名。
     ```

  2. 简化对嵌套名称空间的使用：

     ```c++
     namespace MEF=myth ::elements::fire;
     using MEF::flame;
     ```

##  联合类型：

1. 说明：C++中，允许不同的数据类型使用同一存储区域，即同一 存储区域由不同类型的变量共同表示，这种数据类型就是 联合类型。

   ```c++
   union 联合体名
   { 
       成员表列；
   } 变量表列；
   union data
   { 
       int i;
       char ch;
       float f;
   } a, b, c;
   union data a, b, c;//这几个成员在联合体变量中存放在同一地址，相互覆盖，其
   //长度为最长的成员的长度。
   
   ```

2. 用法：

   - 联合体变量不能在定义时赋初值。 
   - 联合体的空间在某一时刻只有一个成员起作用。联合体 变量中的成员是最后一次放入的成员。 
   - 联合体变量不能作为函数的参数或函数值，但可使用指 向联合体的指针变量。  
   - 联合体可以作为结构的成员，结构体也可以作为联合体 的成员。

3. 举例：

   ```c++
   union un
   { short int a;
   char c[2];
   } w;
   w.c[0]=‘A’; w.c[1]=‘a’;
   cout<<oct<<w.a<<endl; 
   ```

   <img src="C:\Users\夔whd\AppData\Roaming\Typora\typora-user-images\image-20211109194927583.png" alt="image-20211109194927583" style="zoom: 67%;" />

​		其会全部输出。

​		<img src="C:\Users\夔whd\AppData\Roaming\Typora\typora-user-images\image-20211109195017676.png" alt="image-20211109195017676" style="zoom:67%;" />

注意这个储存空间是共享的，所以在赋值时，其数值共享。

​		![image-20211109195248703](C:\Users\夔whd\AppData\Roaming\Typora\typora-user-images\image-20211109195248703.png)

🔸对一个没有赋初值的变量，在定义其指针时要先对其地址运算，将该地址赋值给这个指针。而对于一个有初值的变量就可以直接*point=该值。



























































































































## 
