# C++运算符的重载

- 对已有的运算符重新定义，赋予其另一种功能，以适应不同的数据类型。

### 加号运算符：

1. 定义：实现两个自定义的数据类型相加的运算
2. 注意：对于内置的数据类型，编译器知道如何进行运算。
3. 实现：通过直接写的成员函数来实现两个对象的部分数值的相加。
4. 可以发生函数重载。（还可以写Person和int的相加。）

```c++
//通过成员函数来实现运算符的重载。
class Person{
    public:
    	Person operator+ (Person &p)
		{
    		Person temp;
    		temp.m_A=this->m_A+p.m_A;
   		 	temp.m_B=this->m_B+p.m_B;
    		return temp;
		};
    int m_A;
    int m_B;
}


/*Person PersonAddPerson(Person &p){
    Person temp;//首先创建一个临时的对象。
    temp.m_A=this->m_A+p.m_A;
    temp.m_B=this->m_B+p.m_B;
    return temp;
}*/   //函数重载的本质。

//实质是
/*  Person p3 = p1.operator+(p2)  */
//简化为：
Person p3=p1+p2;

```

```c++
class Person{
    public:
    
    
    int m_A;
    int m_B;
};
//这个的实质也是Person p3= operator+(p1,p2);
Person operator+(Person &p1,Person &p2){
    Person temp;
    temp.m_A=p1.m_A+p2.m_B;
    temp.m_B=p1.m_B+p2.m_B;
    return temp;
}
```

### 左移运算符：

1. 作用：可以输出自定义数据类型。

   ```c++
   class Person{
       friend ostream & operator<<(ostream & cout,Person &P );//让其
       public:
       //void operator<<(Person &P)这个有一个问题就是<<后面就只有一个对象，不需要再传入对象。
       //所以成员函数就无法实现函数重载<<运算符，因为无法实现cout在左边。
       //只能利用全局函数重载<<运算符。
       Person(int a, int b)
       {
           m_A=a;
           m_B=b;
       }        
       
       private:
       int m_A;
       int m_B;
       
       
   }
   
   //这里将其返回值设置为ostream后其返回值还是一个cout类型，所以可以链式叠加
   ostream & operator<<(ostream & cout,Person &P ){//可以用鼠标右键cout然后转到定义，发现cout是ostream数据类型，所以直接可以传一个引用（因为cout只有一个），然后再附加以恶搞Person &P。
       cout<<"m_A="<<P.m_A<<"m_B="<<P.m_B<<endl;//这样就输出了p里面的数据。
       return cout;
   }
   void test(){
       Person P(10,10);
     
      // cout<<P.m_A<<endl;
       //现在我们要实现这个<<这个符号。
       /*如果使用void operator<<(ostream & cout,Person &P )
         cout<<P<<endl;*/   
       //这里这样做还是会报错。因为这还是一个链式编程思想，cout<<P的返回值为一个空，所以不能在后面直接加上<<，因为前面没有cout这个类型了
   }
   int main(){
       test();
       return 0;
       
   }
   ```

### 递增运算符：

1. 通过重载递增运算符，实现自己的整型数据。

   - 前置递增
   - 后置递增

   ```c++
   class MyInteger{
       friend ostream & operator<<(ostream & cout,Person &P );
       public:
       MyInteter(){
   		m_Num=0;
       }
       //重载前置++运算符
       MyInteger& operator++(){//这里使用引用也是和之前的是一样的，如果没有&就是按值传递其结果是拷一个副本（就是一个新的数据）然后再进行运算，不会一直作用于自身。
           //先进行++操作
           m_Num++;
           //再将自身（MyInteger）返回；
           return *this;
       }
       
       
       //后置运算++符；
       //这里不返回引用因为temp是一个临时对象，不可以返回临时变量的地址。
       //所以直接返回值的话就是调用构造函数然后返回一个值相同的副本。
       MyInteger operator++(int){//这里的int是一个占位运算符，告诉编译器他是一个后置运算符。
           //先记录的当时的结果
           MyInteger temp=*this;//这里就是将其作用的那个对象的值copy一份赋值给temp
           m_Num++;
           return temp;
       }
       private:
       int m_Num;
   }
   ostream & operator<<(ostream & cout,MyInteger &myint  ){
       
       cout<<"m_Num="<<myint.m_Num<<endl;
       return cout;
   }
   ```

### 关系运算符

#### 赋值运算符的重载：

- ```c++
  class Person{
      public:
  	Person(int age){
          m_Age= new int(age);//在堆区开辟一个数据
      }
      
      Person& operator=(Person &P){
          //第一步还是将其中的数据全部删除干净
          if(m_Age!=NULL){
  			delete m_Age;
               m_Age=NULL;
              
          }
          //复制一份其中的值，将其赋值给本体的对象的属性。（深拷贝）
          m_Age = new *( p.m_Age);
          //用堆区来给他分配内存；
          return *this;//返回自身的值即可。是为了后面可以进行链式操作。
      }
      ~Person{
          if(m_Age!=NULL)
          {
              delete m_Age;
              m_Age=NULL;//因为一般的=运用于对象的赋值是浅拷贝，所以会有重定义的问题，
              //所以我们要重定义一个=使其直接是深拷贝。
          }
          	
          
      }
      
      int *m_Age;
  }
  ```

#### 相等和不等的运算符的重载：

- ```c++
  //主要是可以对比两个自定义类型
  
  class Person {
      public:
      Person (string name, int age){
  		m_Name=name;
           m_Age=age;
      }
      //重载等号相等运算符的函数
      bool operator==(Person &P){
          if(this->m_Age==p.m_Age&& this->m_Name==P.m_Name)
              return true;
          else 
              return false;
      }
      int m_Age;
      string m_Name;
  }
  ```

#### 函数调用运算符的重载：（）

- 由于重载后的使用方法十分像函数调用，因此称为仿函数

- 仿函数没有固定写法，非常灵活；

  ```c++
  //打印输出类
  class MyPrint{
      public:
      //重载的函数
      void operator()(string test){
          cout<<"test"<<endl;
      }
      
  }
  void test(){
      MyPrint myPrint;
      myPrint ("helloword")//因为非常像函数的调用，因此被称为仿函数。
  }
  //仿函数非常灵活，没有一个固定的写法
  //甚至你可以写一个这样的算法
  class Add{
      public:
      int operator()(int a, int b){
          return a+b;
      }
  };
  test01(){
      Add myadd;
      int ret = myadd(100,100);//这样就成了一个相加的函数
  }
  
  
  //匿名函数对象
  cout<<MyAdd()(100,100)<<endl;//这个就是创建了一个匿名创建了一个对象，然后使用重载之后的小括号
  ```

  
