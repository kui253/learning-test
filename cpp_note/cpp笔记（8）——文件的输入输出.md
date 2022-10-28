# 输入输出流

## 利用cout输出

### ostream方法

#### ostream& put (char)

1. 说明：这个将会显示一个字符。

   ```C++
   cout.put('w');//将显示w
   cout.put(65);//将显示ASCII码65对应的字符
   cout.put(65.3);//将显示ASCII码65对应的字符
   ```

2. put（char）接受一个参数且会强制转换为char类型

#### basic_ostream<char T,traits>&ostream write(const char_type* s,streamsize n );

1. 说明使用cout调用时，将接受一个字符串的地址，然后显示前n个字符

   ```C++
   cout.write("TOMMMA",3);//将显示TOM
   ```

2. 它返回的也时cout对象，所以可以直接接上<<使用

   ```C++
   cout.write(state1,i)<<endl;
   ```

3. 它也可以用于值数据

4. ```C++
   struct pl;
   cout.write((char*)&pl,sizeof pl);
   ```

   

#### 刷新输出缓冲区（flush）

1. 控制符也是函数，所以可以使用flush(cout);来刷新cout缓存区
2. 也可以cout<<flush;
3. flush刷新缓存区，endl刷新缓存区并且在行尾部加上换行符

### 用cout进行输出格式化

#### 修改显示的计数系统

```C++
//以十六进制来显示整数值
cout(hex);
cout<<hex;
//以八进制来显示整数值
cout(oct);
cout<<oct;
//以十进制来显示整数值
cout(dec);
cout<<dec;
```

#### 调整字段宽度

```C++
int width();//返回字段的当前设置
int width(int i );//将字段宽度设置为i个空格，并返回以前的字段宽度，使得能够保存之前的格式，方便恢复
//🔸width()只会影响下一次的输出格式
//🔸默认右对齐，说明在最后的几个会被输出字符替换
```

1. 填充字符fill(char);

   ```C++
   cout.fill('W');
   //这将设置width的填充字符，其默认为空格，如果通过fill()方法修改就可是用W填充
   //一旦修改就会一直生效，直到下一次被修改
   ```

#### 设置精度与数据输出格式

##### cout.precision(int i)

设置显示小数后几位

##### setf（）

1. fmtflags  setf(fmtflags );

   - ![image-20220226102959051](C:\Users\夔whd\AppData\Roaming\Typora\typora-user-images\image-20220226102959051.png)

     

2. fmtflags  setf(fmtflags , fmtflags);

   - ![image-20220226102854285](C:\Users\夔whd\AppData\Roaming\Typora\typora-user-images\image-20220226102854285.png)

##### 头文件iomanip

1. cout<<setfill(char)
   - 用于填充setw
2. cout<<setw(int )
3. cout<<setprecision(int)
   - 用于设置精度

## 使用cin输入

### 流状态

#### 相关成员

![image-20220226103045030](C:\Users\夔whd\AppData\Roaming\Typora\typora-user-images\image-20220226103045030.png)

![image-20220226103052262](C:\Users\夔whd\AppData\Roaming\Typora\typora-user-images\image-20220226103052262.png)

#### 设置状态

1. clear()
   - cin.clear():将清除全部三个状态位（eofbit、badbit、failbit）
   - cin.clear(eofbit):只会讲状态设置位eofbit，其他两个会被清除
2. setstate():该方法只影响其参数中已设置的位，不会影响其他的位

#### 流状态的影响

1. 只有在流状态良好时（所有位都被清除）的情况下，cin才会返回true

2. 如果一旦相关的状态被设置，那就要用cin.clear()清除一下才可以正常使用

3. 仅通过cin.clear()是不能够重新设置流状态🔸导致输入循环终止的不匹配输入仍留在输入队列中。解决方案是让程序读取字符，直到读到空白为止

   ```C++
   while(cin.get()!= '\n'){
   	continue;
   }
   ```

### 其他istream类方法

#### cin.get(void)&&cin.get(char)

|          特征          | ch  =  cin.get(void) |       cin.get(ch)       |
| :--------------------: | :------------------: | :---------------------: |
|   传输输入字符的方法   |  将函数返回赋值给ch  |      赋值给参数ch       |
| 字符输入时函数的返回值 |  字符编码（int值）   | 指向istream的对象的引用 |
| 达到文件尾函数的返回值 |         EOF          |       转换为false       |

#### 字符串的输入：getline(),get()&ignore()

##### get()

```C++
istream & get(char* , int, char);//第一个是字符串储存的位置，第二个参数要比读取的最大字符数大1，第三个是指定的分界符的字符
istream & get(char*, int);
//get()会将换行留在输入流中，这样接下来首先看到的将会是换行符
```

##### getline()

```C++
istream& getline(char*,int ,char);
istream& getline(char*, int);
//getline()会丢弃最后的换行符，也会丢弃分界字符#
```

##### ignore()

```C++
//函数将会读取并丢弃第一个参数个的字符，知道到达第一个截至符，所以第一个可以弄大点
istream & ignore(int = 1,int = EOF);//第一个是要读取的最大字符，另一个是输入分界字符
//返回调用对象，说明可以链式使用
```

##### 意外输入

1. 空行导致get（）无法抽取字符

   ```C++
   //解决
   char temp[80];
   while(cin.getline(temp,80)&&temp[0] != '\0')
   ```

2. 读取超出最大的范围

   |        方法         |                             行为                             |
   | :-----------------: | :----------------------------------------------------------: |
   | getline(char*,int ) | 如果没有读取任何字符（但换行符被视为读取了一个字符）则设置为failbit<br />如果读取了最大数目的字符，且行中还有其他字符，则设置为failbit |
   |  get(char*, int )   |            如果没有读取任何字符，则设置为failbit             |

#### 其他istream方法

1. read()函数读取指定的字节数，并将其储存在指定位置

   ```C++
   char gross[144];
   cin.read(gross,144);
   //read不会再输入后加上空字符，不能将输入转换为字符串，常用于文件的读入
   //返回类型是&istream
   ```

2. peek()查看并返回下一个字符但是不抽取输入流中的字符

3. gcount（）返回最后一个非格式化化抽取方法读取的字符数

4. putback()函数将一个字符插入到输入字符串中，被插入的字符将是下一条输入语句读取到的第一个字符

## 文件输入与输出

包含C++头文件<fstream>

### 文件的打开：

#### 调用open()

```C++
ofstream fout;
fout.open("sdfkas.txt");
fout.close();
```

#### 构造函数

```C++
ofstream fout("sdfa.txt");
```

🔸用这种方式来输出是如果没有这样的文件就创建一个新的文件，如果有这样的将会清空文件，将输出进入到一个空文件中。默认情况下把文件自动截短为0，相当于删除原有的内容

🔸c_str()函数 用某个string对象调用，可以将string转换为c风格字符串

#### 判断文件的打开

1. is_open()：判断文件是否打开成功

#### 打开多个文件

可以打开一个流，然后将它依次关联到各个文件

### 文件模式

open（）还可以接收另外一个参数，在ios_base类中定义了一个openmode

| 打开方式    |            解释            |
| ----------- | :------------------------: |
| ios::in     |     为读文件而打开文件     |
| ios::out    |     为写文件而打开文件     |
| ios::ate    |      初始位置：文件尾      |
| ios::app    |       追加方式写文件       |
| ios::trunc  | 如果文件存在先删除，在创建 |
| ios::binary |         二进制方式         |

🔸可以通过  |  符号来实现打开方式的组合

### *二进制文件

利用write(),read()来操作二进制文件，因为它正好是通过字节来传输的

```C++
#include<iostream>
#include<fstream>
#include<cstdlib>
inline void eatline() { while (std::cin.get() != '\n')continue; }
using namespace std;
typedef struct Person {
	int age;
	int height;
	char name[10];
}p;

void readData(const char* filename) {
	ifstream fin(filename, ios_base::in | ios_base::binary);
	if (!fin.is_open()) {
		cout << "error!!" << endl;
		exit(1);
	}
	p person;
	int num;
	while (fin.read((char*)&person, sizeof p)) {//这里fin.read()返回类型可以终止循环。
	cout << person.name << "  " << person.age << "  " << person.height << endl;
	}
	fin.close();
}
void printData(const char* filename, p person) {//printData只能打印一次
	ofstream fout(filename, ios_base::app | ios_base::binary);
	if (!fout.is_open()) {
		cout << "error" << endl;
		exit(1);
	}
	fout.write((char*)&person, sizeof p);
	fout.close();
}
int main() {
	const char* ch = "joo.txt";
	p person1;
	person1.age = 10, person1.height = 176;
	strcpy_s(person1.name, "Johneey");
	printData(ch, person1);
	readData(ch);//这个可以读全部
	return 0;
}
```

#### 随机访问

因为要修改数据，所以要用out输出，同时要有读入

```C++
fstream finout;
finout.open(file,ios_base::in|ios_base::out|ios_binary);
//这样就是声明一个双向流
```

##### seekg()&&seekp()

1. 作用：将输入指针移动到指定的位置，第二个是将输出指针移动到指定的位置单位（字节）

   ```C++
   seekg(streamoff,ios_base::seekdir);//这个表示相对于第二个参数的偏移位置
   fin.seekg(30,ios_base::beg);//离开始向后30个字节
   fin.seekg(-1,ios_base::cur);//向后移动一个字节
   seekg(streampos);//距离初始位置的距离
   fin.seekg(0);//移动到开头
   ```

##### tellg()&&tellp()

1. 作用返回当前指针的位置

随机访问的算法：
主要是通过一个streampos变量来调节位置，因为一个结构体的数据是一块一块的，所以可以通过这个跳过

还有就是通过一个rec变量来记录第几块，方便能够相乘rec*sizeof（p）。这个rec是重0开始的

```C++
void changeData(const char* filename) {
	fstream finout;
	finout.open(filename, ios::in | ios::out | ios::binary);
	if (!finout.is_open()) {
		cout << "error" << endl;
		exit(1);
	}
	p person0;
	int ct = 0;
	long rec ;
	while (finout.read((char*)&person0, sizeof p))
	{
		cout << ct++ << ": " << "   " << person0.name << "   " << person0.age << "   " << person0.height << endl;
	}
    //这上面都是读取信息
	if (finout.eof()) {
		finout.clear();
	}//这一步必不可少，因为一边已经达到文件尾了所以必须要使用重新设置eofbit
    
    //这里来创建位置偏移变量
	streampos place = rec * sizeof p;
	finout.seekg(place);
	finout.read((char*)&person0, sizeof p);
	cout << rec << ": " << "   " << person0.name << "   " << person0.age << "   " << person0.height << endl;
	if (finout.eof()) {
		finout.clear();
	}
	cout << "name:" << endl;
	cin >> person0.name;
	cout << "age:" << endl;
	cin >> person0.age;
	cout << "height" << endl;
	cin >> person0.height;
	finout.seekg(place);
	finout.write((char*)&person0, sizeof p) << flush;
	ct = 0;
	finout.seekg(0);
	cout << "here are the new contents." << endl;
	while (finout.read((char*)&person0,sizeof p))
	{
		cout << ct++ << ": " << "   " << person0.name << "   " << person0.age << "   " << person0.height << endl;
	}
	finout.close();
}
```

