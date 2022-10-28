# 对象和类

## 封装:

#### 封装的意义：

- 将属性和行为作为一个整体，表现一个生活中的事物。
- 将属性和行为加以权限控制。

#### 封装的语法：

```c++
class 类名{  访问权限：属性  /   行为}
```

- 示例

  ```c++
  //设计一个圆类，求圆的周长。
  const double PI=3.141596;
  class circle{
      
      public:
      //访问权限
      //属性
      //半径
      int m_r;
      //行为
      //获取圆的周长
      double calculateZC(){
          return 2*PI*m_r;
      }
      
  };
  int main(){
      //通过圆类，创建具体的圆（对象）
      //实例化
      circle cl;
      //给圆对象的属性进行赋值
      cl.m_r=10;
      cout<<"圆的周长为="<<cl.calculateZC()<<endl;//通过.运算符来访问里面的属性。
      return 0;
  }
  ```


#### 成员属性设置为私有：

优点：

- 将所有成员属性设置为私有，可以自己控制读写权限。

- 对于写权限，我们可以检测数据的有效性。

  ```c++
  //实例———成员属性设置为私有
  class Person{
      public:			//对外提供一个成员函数。来使其可以访问私有成员。
          //设置姓名
          void setName (string name){
          	m_Name = name;
       	}
      	//获取姓名
      	string getName (){
             	return m_Name; 
          }
      	//获取年龄
      	int getAge(){
            	m_Age =0;//初始化年龄
              return m_Age;
          }
      	void setAge(int age){
              if(age<0||age>150)//这里就是可以判断数据的有效性。而且他不能改变私有数据。
              {
                  cout<<"年龄输出错误"<<endl;
                  return;
              }
              m_Age = age;
          }
      	//设置，只写。
      	void setLover(string lover){
              m_lover = lover;
          }
      
      //公共接口可以来访问私有成员。
      private:
      //姓名
      	string m_Name;
      //年龄
      	int m_Age;
      //情人
      	string m_Lover;
      
  }
  int main(){
      Person P;
      p.setName("zhangsan");
      cout<<"  "<<p.getName()<<endl;
      //外侧不能访问。
      cout<<"  "<<p.getAge()<<endl;
      
  }
  ```

  - 🔸全局函数与成员函数判断的区别。



## struct与class的区别：

#### 区别：

- struct 默认权限为公有

- class默认权限为私有

  ```c++
  class Cl{
      int m_A;//默认权限，是私有
  };
  Cl c1;
  c1.m_A=100;//会报错，因为不能访问
  
  struct C2{
      int m_A;//默认权限，是公有。
  };
  //而struct 类外可以是访问。
  ```

## 对象的初始化和清理：

#### 构造函数与析构函数

##### 构造函数的声明和定义：

```c++
Stock::Stock(.......);//函数的声明，不需要在类名前面加上函数类型（如void）
//这里是先对Stock类使用::来作用于其中的stock（）成员函数。
/*然后在定义对象时，想给这个对象赋初值，那类中的该构造函数将会被调用。，然后按照构造函数的法则去
赋初值,如果没有定义，会生成默认构造函数。*/

//其中的Stock（）函数原型应该位于类声明的公有部分。
{
    //在这里面可以访问类的私有成员，并可以完成构造函数的定义。 
}
```

1. 作用：

   - 用于创建对象时为对象的成员属性赋值，其由编译器自动调用🔸将值赋值给它们的数据成员🔸。

2. 格式：名称要与类名相同（案例如上）

3. 构造函数的语法:

   - 虽然没有返回值，但没有被声明为void类型。实际上，构造函数没有声明类型。	


   - 不要试图将类成员名称用作构造函数的参数名

     ```c++
     Stock::Stock(const string& company,long shares,double share_val)
         //这其中company，shares， share_val是类Stock是私有成员。而构造函数的参数表示的不是类成员，而是赋给类成员的值。
         //为了避免这个情况，我们在类的数据成员的声明是就可以给它加上前缀，或者是"_"
     .....
         private:
            string m_company;
     .....//在构造函数中就可直接使用原名称了。
     ```


   - 构造函数可以有参数，也可以发生函数重载。
   - 在后面学习了this指针后就可以使用this指针来解决这个问题。


##### 构造函数的使用：

```c++
class Person{
    public:
    	Person(){		//要在公共的作用域下才能访问得到。
            cout<<"Person 构造函数的调用"<<endl;
        }

};
void test01(){
    Person p;//这时没有调用构造函数，仅仅是创建了一个对象。
}

int main(){
    test01();
    //再输出时会自动调用
}
```



- 隐式调用构造函数：

  ```c++
  Stock garment("Furry Mason",50,1.25)
  ```

- 显式调用：

  ```c++
  Stock garment=Stock("Furry Mason",50,1.25)
  ```

- 可以使用new来给类分配动态内存：

  ```c++
  Stock* pstock=new Stock("xxxxx",50,1.25)
  ```

- 🔸注意事项：

  - 指针不会调用构造和析构函数，只是定义了一个指针，没有申请内存（如果只是定义了一个指针）
  - 使用new创建对象时，申请分配内存，调用构造函数
  - 当我们使用new为指针开辟空间，然后用delete释放掉空间会分别调用构造和析构函数，换句话说如果没有使用delete来删除new开辟的空间就不算调用了析构函数


##### 构造函数的分类和调用：

1. 分类：
   - 按参数分为：有参构造和无参构造
   - 按类型分类：普通构造和拷贝构造。
2. 调用方法：
   - 括号法
   - 显示法
   - 隐式转换法

```c++
class person{
    person(){
        cout<<"person 的 构造函数的调用"<<endl;
        
    }
    /*
    person(int a){
        cout<<"person 的有参数构造函数的调用"<<endl;
        
    }
    */  
    ~person{
        cout<<"person 的析构函数调用"<<endl;
    }
    //拷贝构造函数
    person(const person &p){		//将p里的属性全部拷贝到另一个对象中，用const 防止p是数据改变
        //将传入人的身上的所有属性，拷贝到我身上？
        age=p.age;//将p 的年龄拷贝给另一个对象。
    }
}
//调用
int main(){
    //1.括号法
    person p;  //默认构造函数
    //调用默认构造函数时，不要加（）
    person p1();//编译器会将其看成一个函数声明。
    
    
    person p2(10);//调用有参构造函数。
    person p3(p2);//调用拷贝函数
    
    
    
    //2.显示法
    person p1;
    person p2 =person(10);//有参构造
    person p3 =person(p2);//拷贝构造
    person(10);//匿名对象，特点：当前执行结束后，系统会立即回收掉匿名对象。
    	//🔸不要利用拷贝构造函数初始化匿名对象。编译器会认为person(p3)===person p3;
             /*(错误)*/person(p3);//会显示重定义
    
    
    //隐式转换法
    person p4=10;//相当于写了 person p4=person(10);
    person p5=p4;//拷贝函数的隐式调用。
    
    
    
}
```

3、构造函数的调用规则：

- 如果用户定义有参构造函数，c++不再提供无参构造函数，但会提供拷贝构造函数。
- 如果用户定义拷贝构造函数，c++不再提供其他构造函数。

##### 拷贝构造函数的调用时机：

- 使用一个已经创建的对象来初始化一个新的对象。
- 值传递的方式给函数参数传值（因为要拷贝一个副本，同时也会调用析构函数）
- 以值的方式返回局部对象。（要拷贝一份过来返回）

深拷贝与浅拷贝：

- 深：在堆区重新申请空间，进行拷贝操作，

- 浅：简单的赋值操作。

  ```c++
  class Person{
      Person(){
          cout<<"Person的默认构造函数调用"<<endl;
      }
      ~Person(){
          //析构代码，将堆区开辟的数据做释放操作
          if(m_Height!=NULL)
          {
              delete m_Height;
              m_Height=NULL;
          }
          cout<<"Person的析构函数的调用"<<endl;
          
      }
      Person(int age,int height){
          m_age=age;
          int *m_Height=new int (height);
          cout<<""<<endl;
      }
      int m_age;
      int *m_Height;
  }
  void test01(){
      Person p1(18,160);
      cout<<"p1的年龄为："<<p1.age<<"身高为："<<*p1.m_Height<<endl;
      Person p2(p1);
      cout<<"p2的年龄为："<<p2.age<<"身高为："<<*p2.m_Height<<endl;
  }
  ```

  🔸浅拷贝的问题：堆区的内存重复释放。在上述的例子中，析构函数先释放p2.Height指向的内存，在之后，到p1析构时发现其指向的堆区是空的，就会报错。（两者的指向内存是一样的，因为值拷贝会将p1中m_Height的存贮的地址原封不动的复制给p2，所以p2的m_Height的内容也是一样的地址。）

- 用深拷贝来解决：

  ```c++
  //再写一个拷贝函数
  Person(const Person &p){
      cout<<"Person拷贝函数调用"<<endl;
      m_age=p.m_age;
      //深拷贝操作
      m_Height =new int (*p.m_Height);//将这个值先取出，再在堆区开辟一个新的内存来存储。
  }
  ```

##### 析构函数

- 完成对象被删除前的一些清理工作。

- 在对象的生存期结束的时刻（销毁后）系统自动调用它，然后再释放此对象所属的空间。

- 如果程序中未声明析构函数，编译器将自动产生一个默认的析构函数，其函数体为空。

- 不可以有参数

  ```c++
   #include <iostream>
   using namespace std;
   class Point {     
   public:
     Point(int xx,int yy);
     ~Point();
     //...其他函数原型，如果没有定义析构函数，其会生成一个默认的析构函数
   private:
     int x, y;
   };
  ```

#### 初始化列表：

- 作用：c++提供了初始化语法，用来初始化属性

- 语法：

  构造函数（）：属性1（值1），属性2（值2）……{函数体 }

  ```c++
  class Person{
      public:
      //构造函数初始化
      Person(int a ,int b , int c){
          m_A=a;
          m_B=b;
          m_C=c;
          
      }
      //初始化列表
      Person(int a, int b, int c):m_A(a),m_B(b),m_C(c){}//相当于也是一种构造函数
      int m_A;
      int m_B;
      int m_C;
      
  }
  int main(){
      
      Person p(30,10,20);//调用的时候两者等价。
      
  }
  ```

  

## 类作为类成员

- 先走phone的类，在出来person的类。两者的先后关系要清楚。

```c++
class phone{
    public:
    phone (string pName){
        m_pName =pName;
    }//有参构造函数。
    //手机品牌名称。
    string m_pName;
}




class Person{
public:
    Person(string name,string pName):m_Name(name),m_Phone(pName){//phone m_phone = pName。隐式转换法。会调用phone的构造函数。 
		//初始化列表来初始化相关属性。        
    }
    string m_Name ;
    phone m_Phone;
    
    
}
void test01(){
    Person P ("xxxx","xxxx");
    cout<<p.m_Name<<"xxx"<<p.m_Phone.m_pName<<endl;
}
```

## 成员函数的定义（类外）

1. 类外——定义类成员时可以用作用域解析运算符（：：）来标识函数所属类(🔸表明是在哪个类作用域下的成员函数)

   

2. 类方法可以访问类的private组件；即访问里面的变量什么的。

   

3. 实现类的成员函数：

   🔸过程：在类中说明函数原型；可以在类外给出函数体实现，并在函数名前使用类名加以限定；

   ##### 

```c++
//定义属于stock类里的update成员函数
void stock ::update(double price) 
//同样允许在其他类里定义一个成员名为update的成员函数。
void buffoon::update()
```





## 静态成员函数

#### 说明：

1. 所有对象共享同一个函数

2. 静态成员函数只能访问静态成员变量。

2. 所有的函数都可以访问静态成员变量。

   ```c++
   class Person{
       public:
       static void func(){//因为静态函数和静态变量是全部共享的所以可以一起使用。
           m_A=100;//静态成员函数可以访问静态成员变量。
           cout<<" 静态函数的调用  "<<endl;
       }
       static int m_A;//静态成员变量。
       int m_B;//非静态成员函数。如果放入静态函数中，在多个对象调用函数时就无法区分到底是哪个对象的m_B属性。
       //静态函数是有访问权限的。
       private:
        static void func2(){
             m_A=100;
            cout<<" 静态函数2的调用  "<<endl;
       }
   }
   int Person::m_A=0//类内声明，类外初始化。
   //两种的访问方式
   void test02(){
       //1、通过对象来访问
       Person p;
       p.func();
       ///2、通过类名来放问。
       Person::func();
       //Person::func2()这个是非法操作，类外是访问不到私有的静态成员函数。
   }
   int main(){
       test02();
       return 0;
   }
   ```

## c++对象模型和this指针

#### 成员函数和成员变量是分开存储的：

- 只有非静态成员变量才属于类的对象上。

  ```c++
  class Person{
      public:
      int m_A;
      static int m_B;//静态成员变量不是类的对象上的内存
      void func(){};//非静态成员函数不属于类的对象上
      static void func2(){};//静态成员函数不属于类的对象上。
  }
  void test01(){
      Person P;
      cout<<"size of p"<<sizeof(p)<<endl;
      //C++编译器会给每个对象分配一个字节空间，是为了区分空对象占内存的位置。
  }
  void test02(){
  	Person p;
      
  }
  int main(){
      test01();
      return 0;
  }
  ```

#### this指针：

- this指针指向被调用的成员函数所属的对象。
- this指针的本质是指针常量，指针指向是不可以修改的。其指向的值可以修改。
- 每当一个成员函数被调用时，this指针指向的对象就是固定的。

1. 作用：

   - 当成员属性与形参名相同时（发生了重突时）

     ```c++
     class Person{
         public:
         	Person(int age ){
                 this->age=age;//此时this指向的就是下面的成员属性age而不是右边的形参age。
             }
     		int age
     }
     ```

   - 在类的非静态成员函数中返回成员函数本身，可用  return* this.

     ```c++
     class person{
         public:
         	Person& PersonAdd(Person& p){//引用做函数返回参数就是返回函数的本体
                 this->age+=p.age;
                 return *this;//这里的this返回的将是
             }
         	/*
         	Person PersonAdd(Person& p){这个会调用拷贝函数就直接会复制一个副本来，所以最后结果不是返回原来的对象
         		this->age+=p.age;
         		return *this;
         	}
         	*/
     }
     void test02(){
         Person p(10);
         Person p2(10);
         p2.PersonAdd(p).PersonAdd(p).PersonAdd(p);//最后的结果是40
     }
     ```
   
2. 适用情况：（补充）

   - 每个类成员都只涉及一个对象，即调用它的对象，但是有点方法可能涉及两个对象，这种情况下就要使用this指针。当前对象自己的指针。

   实例：

   ```c++
   //对于Stock类声明的两个对象stock1,stock2它们都包含topval（）成员函数，则如果要比较这两个成员函数的值，并选出最大的赋给top
   top=stock1.topval(stock2);//显式访问1，隐式访问2。
   top=stock2.topval(stock1);//显示访问2，隐式访问1。
   函数：
       const Stock & topval(const Stock & s)const;
   {
       if(s.total_val>total_val)
           return s;
       else
           return *this;
       //这里的问题在于如果是stock1.topval(stock2),则s是stock2的引用，但是stock1没有别名返回
       //这时this将指向用来调用成员函数的对象——即this将会被设置为stock1的地址
   }
   ```

   



#### 空指针：

1. 空指针调用成员函数：

   ```c++
   class Person{
       public:
       void showPersonName(){
           cout<<""<<endl;
       }
       void showPersonAge(){
           if(this==NULL)
               return;//这样可以防止传入空指针。
           cout<<m_age<<endl;//这里相当于有一个this指针指向m_age而这个this指针必须要有有意义的对象。才可以访问里面的属性。
       }
       int m_age;
   }
   void test01(){
       Person *p = NULL;
       p->showPersonAge();//编译器报错，应为这个指针指向空，而调用成员变量要用到实体指针。
   }
   ```

   

#### const修饰成员函数：

1. 常函数

   - 常函数内不可以修改成员属性。

   - 在成员函数后面加上const，修饰的是this指针，让指针指向的值也是不可修改的。

   - 成员属性加上关键字mutable后，就可以在常函数修改。

     ```c++
     class Person{
         public:
         void showPerson()const {
             this->m_B=100;
             /*直接使用this->m_A=100这个会直接报错，应为这个不可以修改*/
         }
         void func(){
             m_A;
         }
         int m_A;
         mutable int m_B//特殊变量，即在常函数中，也可以修改这个值。
     }
     ```

2. 常对象：

   - 在创建对象时在类名前面加const

   - 常对象只能调用常函数。

     ```c++
     void test01(){
         const Person p;
         //p.m_A=100;这个会直接报错，m_A不是常变量
         p.m_B=100;//这个是可行的
         p.showPerson();//对
         //p.func();这个调用是错误的。常对象，不可以调用普通成员函数，因为普通成员函数可以修改属性。
     }
     ```


## 友元：

#### 作用：

- 有些私有属性也想让类外的特殊的一些函数或类进行访问，就需要用到友元技术
- 友元的目的是让一个函数或类，访问另一个类中的私有成员。

#### 三种实现：

##### 全局函数做友元

```c++
【在类中使用friend关键字】


class Building {
   //在public上面声明友元。
    friend void GoodFriend(Building *building);//这样就声明友元了。 
    public:
    	building(){//构造函数，直接在创建对象时就给对象的成员属性就赋了初值。
            m_sittingRoom="客厅";
            m_bedRoom="卧室";
        }
    
    
    	string m_sittingRoom;//客厅
    private:
    	string m_bedRoom;//卧室
}
//创建全局函数
void GoodFriend(Building *building){
    cout<<"全局函数正在访问"<<building->m_sittingRoom<<endl;
    
    cout<<"全局函数正在访问"<<building->m_bedRoom<<endl;//如果没有声明友元就会在这里报错。
}
```

##### 类做友元

```c++
class building ;//事先声明一个类；


class goodFriend{
    public:
		goodFrieng();
    	void visit();
    private:
		Building *building;//类中再创建一个指向Building类的对象指针。（应该也可以直接创建对象，不带指针）
};


class Building {
    friend class goodFriend;//因为要用goodFriend来访问这Building类里的成员。
    public:
		Building();
    public:
    	string m_sittingRoom;
    private:
		string m_bedRoom;
};


//
Building::Building(){
    m_sittingRoom="客厅";
    
    m_bedRoom="卧室";
};
goodFriend::goodFriend(){
    //创建一个建筑物对象
    building = new Building;//此时也会调用Building的构造函数，并给building赋初值
    //再堆区给goodFriend的类成员building分配一个Building类的空间。相当于构造函数。
};
void goodFriend::visit(){
    cout<<"GoodFriend正在访问"<<building->m_sittingRoom<<endl;
    cout<<"GoodFriend正在访问"<<building->m_bedRoom<<endl;
}
//
void test01(){
	goodFriend gg;
    gg.visit();
}
int main(){
    test01();
	return 0;
}
```



##### 成员函数做友元

```c++
class building ;


class goodFriend{
    public:
		goodFrieng();
    	void visit();//让visit()可以访问Building的私有成员
    	void visit2();//而visit2()不可以访问Building的私有成员。
    private:
		Building *building;
};


class Building {
    friend void goodFriend::visit();//就是将整个成员函数的声明放在要访问的类里
    public:
		Building();
    public:
    	string m_sittingRoom;
    private:
		string m_bedRoom;
};


//
Building::Building(){
    m_sittingRoom="客厅";
    
    m_bedRoom="卧室";
};
goodFriend::goodFriend(){
    
    building = new Building;
    
};
void goodFriend::visit(){
    cout<<"GoodFriend正在访问"<<building->m_sittingRoom<<endl;
    cout<<"GoodFriend正在访问"<<building->m_bedRoom<<endl;
}
void goodFriend::visit2(){
    cout<<"GoodFriend正在访问"<<building->m_sittingRoom<<endl;
    //这里就不能访问这个内容cout<<"GoodFriend正在访问"<<building->m_bedRoom<<endl;
}
//
void test01(){
	goodFriend gg;
    gg.visit();
}
int main(){
    test01();
	return 0;
}
```





## 对象数组

##### 说明：

- 和一般的数组类似，通过创建对象数组，用户可以同时创建一个类的多个对象。

  ```c++
  Stock mystuff[4];
  ```

##### 利用构造函数来初始化数组元素。

```c++
const int size=4;
Stock stocks[size]={
    Stock("....",12.5,20),
    Stock("....",13.5,30),
    ....,
    ....,
}//这样就完成了4个元素的赋值。

const int STKS=4;//如果类中包含多个构造函数，则可以对不同的元素使用不同的构造函数。
Stock stock[STKS]={
    stock("....",12.5,20),
    Stock(),
    Stock("....",130,13.5),
}
```

##### 对象数组指针：

```c++
const Stock* top=&stock[0];//这里是将stock[0]的地址赋值给一个名为top的指针。
for (int st=1;st<4;st++)
    top=&top->topval(stock[st]);//这里等价于指针top对象去访问topval（），即top=(*top).topval(stock2);
top->show();
```

## 继承

1.  作用：减少重复的代码

2.  派生类的成员：

   - 一类是从基类继承过来的，一类是自己增加的成员
   - 从基类继承过来的表现其共性，而新增的成员体现了其个性

   ```c++
   //class 子类（派生类）：继承方式 父类（基类） 
   class BasePage{
       void left(){};
       void right(){};
       void .....
   }
   class Java : public BasePage{
       public:
       cout<<"Java教学视频"<<endl;
       
   }
   class Python : public BasePage{//继承上面是类的公共部分
       public:
       cout<<"python视频"<<endl;
   }
   
   ```

3.  继承的方式

   - 公共继承：公共成员和保护成员依旧不变直接进入子类，而父类的私有成员还是不可访问

   - 保护继承：公共成员和和保护成员都是保护成员，但是父类私有成员还是不可访问的

   - 私有继承：父类的公共成员和保护成员都在子类中变成了私有成员，但是父类的私有成员还是不可访问

     ```c++
     class Base1{
         public:
         int m_A;
         protected:
         int m_B;
         private:
         int m_C;
     }
     class son1 : public Base1{
         public:
         fun(){
             m_A=10;
             m_B=10;
         }
     }
     void test01(){
         son1 s1;
         s1.m_B;//报错不能访问
     }
     ```

4.  继承中的对象模型

   - 问题：到底哪些会被继承到子类中？

     ```c++
     //在父类中的所有非静态的成员都会被继承了（而私有成员也继承了但是编译器隐藏了，还是不可以访问）
     class Base{
         public:
         int m_A;
         protected:
         int m_B;
         private:
         int m_C;
         
     }
     class Son:public Base{
         public:
         int m_D;
     }
     void test01(){
         cout<<"size of son = "<<sizeof(Son)<<endl;//最后结果是16.
     }
     ```

   - 利用开发人员命令提示工具查看对象模型：

     - 跳转盘符  F:
     - 跳转文件的路径  cd....具体路径
     - 查看命令 ：cl /d1 reportSingleClassLayout类名 文件名

5.  继承中构造和析构顺序：

    - 先构造父类，再构造子类，析构的顺序相反。

      ```c++
      //继承中的构造和析构顺序
      class Base{
          public:
          Base (){
              cout<<"Base 的构造函数！"<<endl;
          }
          ~Base(){
              cout<<"Base 的析构函数！"<<endl;
          }
      }
      class Son:public Base{
          Son(){
              cout<<"Son 的构造函数！"<<endl;
          }
          ~Son(){
              cout<<"Son 的析构函数!"<<endl;
          }
      }
      void test01(){
          //先构造父类，再构造子类，析构的顺序相反。
          Son s
          
      }
      ```

6.  继承同命成员处理方式

    - 访问子类同名成员，直接访问即可

    - 访问父类同名成员，需要加作用域

      ```c++
      
      
      class Base {
          public:
          Base(){
              m_A=100;
          };
          void fun(){
              cout<<"Base fun 的调用"<<endl;
          }
          int m_A;
      };
      class Son:public Base{
          public:
          
          Son(){
              m_A=200;
          }
          void fun(){
              cout<<"son_fun的调用"<<endl;
          }
          int m_A;
      };
      //同名成员属性
      void test01(){
          Son s ;
          cout<<"Son 下 m_A"<<s.m_A<<endl;
          //如果要通过子类对象访问到父类中的同名成员，需要加作用域。
          cout<<"Base 下 m_A"<<s.Base::m_A<<endl;
      }
      //同名成员函数
      void test02()
      {
          Son s;
          s.fun();
          s.Base::fun();//访问父类的
          //如果子类中出现了和父类同名的成员函数，子类的同名成员会隐藏掉父类中所有的同名成员函数
          //如果想访问父类的要加作用域。
          
      }
      int main(){
          test01();
          return 0;
      }
      ```

7.  继承中同名静态成员的处理方式

    - 静态成员和非静态成员出现同名，处理方式一致

      ```c++
      //继承中的同名静态成员的处理方式
      class Base{
          public:
          static int m_A;
      };
      Base::m_A=100;
      class Son:public Base{
          static int m_A;
      };
      Son::m_A=200;
      //通过对象来访问。
      void test01(){
          Son s;
          cout<<"Son"<<s.m_A<<endl;
          cout<<"Base"<<s.Base::m_A<<endl;
      }
      //通过类名来访问（仅对静态成员有效）
      void test02(){
          cout <<"Son"<<Son::m_A<<endl;
          cout<<"Base"<<Son::Base::m_A<<endl;
      }
      ```

8.  允许一个类继承多个类：

    - 多继承可能会引发父类中有同名成员出现，需要加作用域来区分

      ```c++
      class Base1{
      	public:
          Base1(){
              m_A=100;
          }
          int m_A;
      }
      class Base2{
          public:
          Base2(){
              m_B=200;
          }
          int m_B;
      }
      //继承方式就是通过逗号实现
      class Son:public Base1,public Base2{
          public:
          Son(){
              m_C=300;
              m_D=400;
          }
          int m_C;
          int m_D;
          //会有二意性出现，这时候就要使用作用域了。
      }
      ```

9.  菱形继承

  - 两个派生类继承同一个基类

  - 又有某个类同时继承了两个派生类





# 函数递归的一个小tricky:

- 问题导入

  <img src="C:\Users\夔whd\AppData\Roaming\Typora\typora-user-images\image-20211212111648630.png" alt="image-20211212111648630" style="zoom:50%;" />

  <img src="C:\Users\夔whd\AppData\Roaming\Typora\typora-user-images\image-20211212111728400.png" alt="image-20211212111728400" style="zoom:50%;" />

  - 🔸🔸这个问题主要是于函数的调用有关系的，每次函数调用自身都要先进入到函数体里，进行完函数体里面的运算后跳出最里面的函数，所以叫函数的递归，有一个传递也有一个回归的过程，而回归的过程就要从最里面的函数体里一个一个先外面的函数体回归。
  - 🔸第二：函数递归是需要占用内存的，所以调用到后面内存一点点的堆栈，内存就会增加。

# */



# /*

## 内存模型：

### 内存的分区模型：							

#### 代码区：

存放函数体的二进制代码，由操作系统进行管理

#### 全局区：

存放全局变量和静态变量以及常量

#### 栈区：

由编译器自动分配释放，存放函数的参数值，局部变量。

- （栈区的数据由编译器管理和开辟，不要返回局部变量的地址，因为最后会被释放。）

  ```c++
  int *fun (){
      int a = 10;
      return &a;//错误示范，a是局部变量。
  }
  ```

  

#### 堆区：

由程序员分配和释放，若程序员不释放，程序结束时有操作系统来回收

- 就是使用new来开辟数据。

  ```c++
  eg.
      int* fun(){
  //直接使用new关键字，它会返回它开辟这一部分的地址
      
      new int (10);
       
  //而指针可以用来存放地址所以就有了以下语句
  //指针本身也是局部变量，放在栈上，其保存的数据放在了堆区。而放在堆区的数据要程序员来释放。
      int *p = new int (10);
  //然后通过指针来接收这块内存
      return p;
      
  }
  ```

  

🔸这四个分区的内存由不同的生命周期

## 引用:

#### 作用：

给变量起别名

```c++
int &b = a;
//这样就可以通过变量b来操作a
```

#### 注意事项：

- 必须要初始化
- 初始化后就不可以改变

#### 引用来做函数参数：

```c++
这是用指针时
//定义时
void Swap(int *a,int *b){//因为这里给形参是a是一个地址。
    
}
//使用时
Swap (&a, &b);
//总结在定义时传指针，在使用时传引用。
```

```c++
使用引用时
void Swap(int &a,int &b){
    
    
}
Swap(a,b)    
```

#### 引用做函数的返回值：

- 注意：不要返回局部变量的引用。

  ​           函数调用可以作为左值。

```c++

int& test(){
    static int a =10;
    return a;
}//此时test 返回的其实就是a的本身。

int& ref=test();
cout <<"ref="<<ref<<endl;//这里的ref 结果就是10。先当于ref成了a的别名。

//作为左值存在
test()=1000;//这样相当于直接作用于a，并将其值修改成1000，同时ref的值也会被修改。

```

#### 引用的本质：

- 在c++内部实现一个指针常量。

  ```c++
  //发现是引用，转换为int* const ref=&a;
  void func(&ref){
      int ref =100;//ref是引用直接转换为*ref=100；
  }
  int main(){
      int a = 10;
      
      //自动转换为int* const ref =&a;(这里的const是指针的指向是固定的)
      //指针常量是指针指向不可改，也说明之前为什么引用不可以改。
      int& ref = a;
      ref = 20;//内部发现ref是引用，自动帮我们转换为：*ref = 20;
      
      func(a);
      return 0;
  }
  
  ```

#### 常量引用：

- 🔸作用：一般用来修饰形参，防止误操作。

  ```c++
  //如果这个函数是我们用来只需要输出相关的值，那就可以加上const来防止误修改上面的值。
  void Show(int &val){
      val =100;//这里修改了参数的值。
      cout<<val;
  }
  
  int a;
  Show(a);//则这里的a的值也发生了改变。
  
  
  //所以为了防止这种情况发生。
  void Show(const int &val);//这样如果在函数里修改了val的值，编译器就会报错。
  ```

  



