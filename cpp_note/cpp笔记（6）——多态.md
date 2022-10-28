# 多态：

## 多态的基本概念：

1. 多态可分为两类：

   - 静态多态：函数重载和运算符重载属于静态多态，复用函数名
   - 动态多态：派生类和虚函数实现运行时多态，函数的地址晚绑定，运行阶段确定函数地址。

2. 满足条件：

   - 要有继承关系
   - 子类要重写（函数什么都一样）父类的虚函数。

3. 动态多态的使用

   - 父类的指针或引用，指向子类的对象

   ```c++
   class animal{
       public:
       //虚函数
       virtual void speak(){//虚拟状态，则直接就会先调用子类中的成员函数
           cout<<"ssss"<<endl;
       }
   };
   class Cat:public animal{
       public:
       virtual void speak(){
           cout<<"ddd"<<endl;
           
       }
   }
   //地址早绑定，在编译阶段就已经确定了函数地址。
   //如果想执行子类的speak就要使地址晚绑定
   void doSpeak(animal & ani){
       animal.speak();//这样使得speak这个函数有多个状态，传入的是哪个类就走哪个的speak。
   }
   test01(){
       Cat cat;
       doSpeak(cat);//允许父类与子类的转换
   }
   //继承关系
   //子类要重写父类的虚函数
   //子类中可以写virtual
   //父类指针指向子类的对象
   base * abc = new sub;
   ```

### 多态的具体剖析

1. 虚函数标的问题：当父类中写了一个虚函数时，父类虚函数表里面放到就是父类的虚函数，当子类重写父类的虚函数时，子类的虚函数表内部就会替换成子类的虚函数地址&cat::speck();
2. 当父类的指针或者引用指向子类对象时，发生多态，在继承发生时，父类的虚函数表也会被继承下来，在写虚函数时就会被重写

### 多态的好处

1. 功能可以外加不用直接动源码。

## 纯虚函数

1. 纯虚函数的语法:

   ```C++
   virtual 返回值类型 函数名 (参数列表) = 0;
   //当类中有了纯虚函数，这个类也称为抽象类
   //无法实例化对象，抽象类的子类必须要重写父类的纯虚函数
   class Base{
       public :
       virtual void func() = 0;
   };
   class Son:public Base{
       public:
       void func(){};
   };
   Son s;
   ```

2. 虚析构和纯虚析构

   1. 问题:多态使用时，如果子类中有属性开辟到堆区，那么父类的指针在释放时无法调用到子类的析构代码

   2. 解决：将父类的析构函数改为虚析构或纯虚析构

      ```C++
      class animal{
          public:
          //虚函数
          animal(){
      		cout<<"animal d gouzao hanshu d diaoyong ."<<endl;
          }
          //所以这里要有虚构
          virtual ~animal() {
              cout<<"animal d xigou hanshu d diaoyong "<<endl;
          }
          //纯虚构
          //virtual　~animal() = 0;
          virtual void speak(){//虚拟状态，则直接就会先调用子类中的成员函数
              cout<<"ssss"<<endl;
          }
      }
      class Cat:public animal{//更改数据放置的位置
          public:
          Cat(string name){
              m_name = new string(name);//在堆区开辟内存
          }
          virtual void speak(){
              cout<<"ddd"<<endl;
              
          }
          string * m_name;
          ~Cat(){
              if(m_name!= NULL){
                  cout<<"cat d xigou hanshu d diaoyong "<<endl;
                  delete m_name;
                  m_name = NULL;
              }
      };
          
      void test01(){
          animal* animal = new Cat("Tom");
          animal->speak();
          //父类指针在析构时，不会调用子类中的析构函数，导致子类中如果有堆区的数据就会有数据泄露
          delete animal;
      }
      //
      ```

      

