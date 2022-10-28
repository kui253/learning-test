# 模板（泛型编程）

### 模板的概念：

- 就是建立通用的模板，大大提高复用性
- 不可以直接使用，只是一个框架，通用不是万能

### 模板类型：

#### 函数模板：

1. 作用：建立一个通用函数，其函数返回值类型和形参类型可以不具体指定，用一个虚拟的类型来代表

   ```c++
   //template <typename>
   //函数声明和定义
   
   template<typename T>//声明一个模板，告诉编译器后面代码中紧跟着T不要报错
   void mySwap(T &a, T &b){
       T temp=a;
       a=b;
       b=temp;
   }
   //自动类推导。
   mySwap(10,20)
   
   //显示指定类型
   mySwap<int>(a,b)//尖括号直接指定T的数据类型
   
   
   ```

2. 函数模板的注意事项

   - 自动类推导，必须推导出一致的数据类型T，才可以使用

   - 模板必须要确定出T的数据类型，才可以使用

     ```c++
     //1
     template <typename T>//可以替换成class,效果都一样
     void mySwap(T& a ,T& b){
         T temp=a;
     	a=b;
         b=temp;
     }
     void test01(){
         int a =10;
         int b =20;
         char c ='c';
         mySwap(a,c)//编译器报错，这里推导不出一致的数据类型
     }
     //2
     template <typename T>
     void func(){
         cout <<"func d diaoyong"<<endl;
     }
     void test02(){
         func();//这里会报错，因为没有传入参数
         //显示指定类型
         func<int>();//直接告诉编译器这是一个int类型的数据，这样就可以调用了。
     }
     
     ```

3. 普通函数与函数模板的区别

  - 普通函数调用时可以发生自动类型转换（隐式类型转换）

  - 函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换

  - 如果利用显示指定类型的方式，可以发生隐式类型转换

    🔸相当于如果没有显示指定类型，那再传入的数据类型不同则自动类推导不出相应的类型

    ​	而当使用显示指定类型时，就会直接强制类型转换

4. 普通函数和函数模板的调用规则

  - 如果函数模板和普通函数都可以实现，优先调用普通函数

  - 可以通过空模板参数列表来强制调用函数模板

  - 函数模板也可以发生重载

  - 如果函数模板可以产生更好的匹配，优先调用函数模板

    ```c++
    //point 2
    template <class T>
    void myprint(T &a,T& b){
        cout<<"函数模板的调用"<<endl;
    };
    void myprint(int a,int b){
    	cout<<"普通函数的调用"<<endl;
    };
    void test01(){
        int a =20;
        int b = 30;
        myprint(a,b);//这里调用的是普通函数
        myprint<>(a,b);//这样优先调用函数模板（强制调用）
    }   
    
    //point 3
    
    template <class T>
    void myprint(T &a,T &b,T &c){
    	cout <<"调用重载的模板"<<endl;
    }
    
    //point 4
    char c1='a';
    char c2='b';
    myprint(c1,c2);//不用发生隐式类型转换所以优先调用函数模板
    ```

5. 模板的局限性

  - 有一些特定的数据类型无法进行模板运算。所以C++提供了模板重载，可以为这些特定的类型提供具体化的模板

    ```c++
    class Person{
        public:
        
        Person(string name;int age){
            m_Age=age;
            m_Name=name;
        }
        string m_Name;
        int m_Age;
    }
    
    //对比函数
    template<class T>
    bool myCompare(T &a,T &b){
        if (a==b)
            return true;
        else
            return false;
    }
    
    //利用具体化Person的版本实现代码，具体化优先调用
    template <>bool myCompare(Person &p2,Perosn &p1){
        if (p1.m_Name==p2.m_Name&&p1.m_Age==p2.m_Age)
            return true;
        else
            return false;
    }
    //先当于提供了一个外加类型
    
    void test001(){
        int a =20;
        int b =30;
        
    }
    ```


#### 类模板：

1. 类模板的作用：建立一个通用类，类中的成员数据类型可以不具体制定，用一个虚拟的类型来代表

   ```c++
   //template<typename T>
   //类
   template<class NameType,class AgeType>
       //相当于连续声明几个模板，使得类的属性是一个虚拟类型
   class Person{
   public:
       person(NameType name,AgeType age){
           this->m_Name = name;
           this->m_Age = age;
       }
       
       void shpwPerson(){
           cout<<"name:"<<this->m_Name<<"age:"<<this->m_Age<<endl;
       }
       NameType m_Name;
       AgeType m_Age;
   }
   
   
   void test01(){
   	Person<string,int>p1("xxx",999);//显示指定类型
       //指定NameType为string类型，AgeType为int类型
       p1.showPerson
   
   }
   ```

2. 类模板和函数模板的区别

   - 类模板没有自动类型推导的使用方式

   - 类模板再模板参数列表中可以由默认参数

     ```c++
     template<class NameType,class AgeType>
     
     class Person{
     public:
         person(NameType name,AgeType age){
             this->m_Name = name;
             this->m_Age = age;
         }
         
         void shpwPerson(){
             cout<<"name:"<<this->m_Name<<"age:"<<this->m_Age<<endl;
         }
         NameType m_Name;
         AgeType m_Age;
     };
     
     //point 1
     void test01(){
         //Person p("xxxx",999)这样使用会直接报错，无法自动类型推导
         Person<string,int >p ("xxx",999)//正确，只能显示指定类型
             
     }
     
     
     //point 2
     void test02(){
         
        //在前面要这样声明一个类template<class NameType,class AgeType = int>
         Person<string>p1("xxx",999);
         p1.showPerson();
     }
     
     ```

3. 类模板中的创建时机

   - 普通类中的成员函数一开始就可以创建

   - 类模板中的成员函数在调用时才可创建

      ```c++
      class Person1{
          public:
          void showPerson1(){
              cout<<"Person1"<<endl;
          }
      };
      class Perosn2{
          public:
           void showPerson1(){
              cout<<"Person2"<<endl;
           }
      };
      template <class T>
          class MyClass{
              public:
              T obj;
              //这两个成员函数都不会创建，所以这样直接编译可以成功
              //这就说明了类模板在成员函数调用后才创建
             /* void func1(){
                  obj.showPerson1();
              }
              void func2(){
                  obj.showPerson2();
              }*/
              
          };
      void test01(){
      
          MyClass<Person1>m;
          m.func2();
          //这里就可以直接调用
      }
      
      
      ```

4. 类模板对象作函数参数

   - 指定传入的类型——直接显式对象的数据类型(最常用)

   - 参数模板化——将对象中的参数变为模板进行传递

   - 整个类模板化——将这个对象类型模板化进行传递

      ```C++
      template <class T1,class T2>
          class Person{
              public:
              Person(T1 name, T2 age){
                  this->m_Age = age;
                  this->m_name = name;
              }
              void showPerson(){
      			cout<<"xingming:"<<this->m_Name<<"nianling:"<<this->m_Age<<endl;
              }
              T1 m_Name;
              T2 m_Age;
          };
      //point 1
      void PrintPerson1(Person<string, int> &p){
          p.showPerson();
          
      }
      void test01(){
          Person<string, int> p ("",66);
          PrintPerson1(p);
      }
      //point 2
      template <class T1,class T2>
      void PrintPerson2(Person<T1,T2> &p){
          p.showPerson();
      }
      //point 3
      template <class T>
          void PrintPerson3(T &p){//直接把这个类变成模板
          p.showPerson1();
      }
      
      void test03(){
          Person<string,int>p("xx",30);
          PrintPerson3(p);
      }
      
      ```

5. 类模板与继承：

   - 当子类继承的父类的一个模板时，子类在声明的时候，要指定出父类中T的类型

   - 如果不指定，编译器无法给子类分配内存

   - 如果想灵活指定父类中T的类型，子类也需要变为类模板

      ```C++
      template <class T>
      class Base{
          T m;
      };
      //class son:public Base{//这样是错误的。必须要知道父类中T的类型
      class son:public Base<int>{//这样就具体化了。
      
      
      };
      //point 2
      template<class T1,class T2>//不过这里需要再次声明模板。
      class Son2:public Base<T2>{
          T1 obj;
      };
      void test02(){
          Son2<int, char>S2//这里第一个int是具体化T1，第二个char是具体化T2.这样就可以使用了。
      }
         
      ```

6. 类模板成员函数的类外实现

   ```C++
   template <class T1,class T2>
   class Person {
       public:
       Person(T1 name,T2 age){
           this->m_Name = name;
           this->m_Age = age;
       }
       void showPerson();
       T1 m_Name;
       T2 m_Age;
   };
   
   //构造函数的类外实现
   template<class T1,class T2>
       //告诉编译器这是一个类模板的函数实现
   Person<T1,T2>::Person(T1 name,T2 age){
           this->m_Name = name;
           this->m_Age = age;
   }
   template<class T1,class T2>
   void Person<T1 ,T2>::showPerson(){
       .....
   }
   
   ```

7. 类模板的分文件编写

   - 直接包含cpp源文件

   - 将声明和实现写道同一个文件中，并更改后缀名为.hpp，hpp是约定的名称，并不是强制

     ```c++
     template <class T1,class T2>
     class Person {
         public:
         Person(T1 name,T2 age);
         void showPerson();
         
         
         
         T1 m_Name;
         T2 m_Age;
     };
     template <class T1,class T2>
     Person<T1,T2>::Person(T1 name,T2 age){
         this->m_Age= age;
         this->m_Name= name;
     }
     template <class T1,class T2>
     Person<T1,T2>::showPerson(){
         cout<<"xingming:"<<this->m_Name<<"nianling:"<<this->m_Age<<endl;
     }
     void test01(){
         Person<string,int >p("Jerry",18);
         p.showPerson();
     }    
     ```
     
     ```c++
     //分文件编写cpp，解决方式1
     #include"Person.cpp"//与类模板创建的时机有关，因为编译器在编译时，先要看到具体的函数才会更具函数生成相应的具体化。所以要先包含函数所在的源文件。
     //第二种解决方式 解决方式2
     ```
   
8. 类模板与友元：

   - 全局函数的类内实现，直接在类内声明友元即可

   - 全局函数的类外实现，需要提前让编译器知道全局函数的存在

      ```C++
      主要是具体化的先后的问题，是编译器先知道那个的存在。
      template <class T1,class T2>
      class Person;
      
      void printPerson2(Person<T1,T2> p ){
              cout<<"...."<<endl;
      	} 
      template <class T1,class T2>
      class Person {
          //全局函数的类内实现
          friend void printPerson(Person<T1,T2> p ){
              cout<<"...."<<endl;
          }
          //全局函数的类外实现
          
          
          //加一个空模板参数列表
          //如果全局函数是类外实现，需要让编译器提前知道函数的存在
          friend void printPerson2<>(Person<T1,T2> p);
          public:
          Person(T1 name,T2 age){
              this->m_....
          };
          
          
          private:
          T1 m_Name;
          T2 m_Age;
      };
      void test01(){
          Person<string, int> p ("", 10);
          printPerson2(p);//直接就可以实现了。
      }
      
      
      
      ```

      



## 模板实例：

1. 描述

   - 利用函数模板封装一个排序函数，可以对不同的数据类型数组进行排序

   - 排序规则从小到大，排序算法为选择排序

     ```c++
     #include <iostream>
     using namespace std;
     template<class T>
     void mySwap(T &a,T &b){
         T temp=b;
         b=a;
         a=temp;
     }
     template<class T>
     //排序的模板函数
     void mySort(T arr[], int len){
         for(int i=0 ; i< len ; i++){
             int max=i;
             for(int j=i+1;j<len;j++){
                 //认定的最大值比遍历的最大也大，就更新角标
                 if(arr[max]<arr[j]) max=j;
               //依次把最大值和前面的值交换  
             }
             if(max!=i)mySwap(arr[max],arr[i])
         }
     } 
     /*还可以直接使用冒泡法
     for(int i=0;i<len;i++){
     	for(int j=i;j<len-1;j++){
     		if(arr[j]>arr[j+1]){
     			mySwap(arr[j],arr[j+1]);
     		}
     	}
     }
     
     */
     
     template <class T>
     void printArr(T arr[],int len){
     	for(int i=0;i<len;i++){
             cout <<arr[i]<<" "<<endl;
         }
         cout<<endl;
     }
     void test01(){
         //测试char数组
         char charArr[]="badcfe";
         int num = sizeof(charArr)/sizeof(char);
         mySort(charArr,num);
         printArr(charArr,num);
     }
     
     void test02(){
         int intArr[]={2,5,6,7,3,6,9}
         int num = sizeof(intArr)/sizeof(int);
         mySort(intArr,num);
         printArr(intArr, num);
     }
     int main(){
         test01();
         test02();
         return 0;
     }
     ```

     
