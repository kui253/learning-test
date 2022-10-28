# 函数高级用法



## 函数占位参数

- 说明：c++中函数的形参列表里可以有占位参数，用来做占位。调用函数时必须填补该位置。

  ​           还可以有默认参数。

- 语法：**返回值类型   函数名  （数据类型   ）{}**

  ```c++
  void func(int a , int ){
      
  }//如果要使用这个函数，就要传两个int类型的变量进来。
  int main(){
   func(10,10);
      return 0;
  }
  //默认参数
  void func(int a,int =10){}
  ```

## 函数重载

#### 作用：

函数名可以相同，提高复用性。

#### 满足条件：

- 同一个作用域下

- 函数名相同

- 函数参数类型，或者个数不同或者顺序不同

  🔸注意：函数的返回值不可以作为函数重载的条件。

#### 函数重载的注意事项：

- 引用作为重载条件：

  ```c++
  void func(int &a){
      cout <<""<<endl;
      
  }
  void func(const int& a){
      cout<<""<<endl;
  }//这样是可以通过的
  
  
  
  ```


例题：

```c++
void longest(char* str, char* result)
{
    char * start, * cur;
    int len = 0;
    cur = str;
    while (*cur != '\0') {
        while ((*cur == ' ' || *cur == '\t' || *cur == '\n' || *cur == '\r') && *cur != '\0')
            ++cur;//将指针移动过空格。
        start = cur;//将初始指针移动到这里。
        while (!(*cur == ' ' || *cur == '\t' || *cur == '\n' || *cur == '\r') && *cur != '\0')
            ++cur;//再移动另一个指针
        if (cur - start > len) {
            len = cur - start;
            for (int i = 0; i < len; ++i)
                result[i] = start[i];
            result[len] = '\0';
        }
    }
}

```

<img src="E:\图片\md笔记图片\QQ图片20211219225209.jpg" style="zoom: 25%;" />



