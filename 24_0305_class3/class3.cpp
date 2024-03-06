#include<iostream>
using namespace std;

//类之间的内存对齐
//#pragma pack(1)
//class A
//{
//private:
//	int i;
//	char j;
//};
//class B
//{
//private:
//	char i;
//	int j;
//};
//int main()
//{
//	cout << sizeof(A) << endl;
//	cout << sizeof(B) << endl;
//	return 0;
//}

//class Date
//{
//public:
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;     // 年
//	int _month;    // 月
//	int _day;      // 日
//};
////成员函数都有一个隐含的this指针，一般是成员函数的第一个参数
//int main()
//{
//	Date d1, d2;
//	d1.Init(2022, 1, 11);
//	d2.Init(2022, 1, 12);
//	d1.Print();
//	d2.Print();
//	//调用同一个函数，是如何输出不同的数据的
//
//	return 0;
//}

//class A
//{
//public:
//	void Print()
//	{
//		cout << "Print()" << endl;
//	}
//private:
//	int _a;
//};
//int main()
//{
//	A* p = nullptr;
//	p->Print();
//	return 0;
//}

//class A
//{
//public:
//	void PrintA()
//	{
//		cout << _a << endl;
//	}
//private:
//	int _a;
//};
//int main()
//{
//	A* p = nullptr;
//	p->PrintA();
//	return 0;
//}

////////////////////////////
//构造函数：为了初始化
//class A
//{
//public:
//	A()
//	{
//		cout << "A()" << endl;
//		_a = 0;
//	}
//private:
//	int _a;
//};
//class MyClass
//{
//public:
//	//MyClass()
//	//{
//	//	_year = 1;
//	//	_month = 1;
//	//	_day = 1;
//	//}
//	MyClass(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//
//	A _aa;
//};
//int main()
//{
//	//构造函数一般是在对象实例化的时候进行指定参数
//	MyClass a1;
//	//为了和函数的声明区分开，规定无参数的时候，是不可以加括号的
//	a1.Print();
//	MyClass a2(2024, 3, 5);
//	a2.Print();
//	return 0;
//}

//内置类型/基本类型   int/char/指针等   语言自己本身定义的类型
//自定义类型    struct/class
//默认生成的构造函数，对于内置类型不做处理，自定义类型会调用他的默认构造函数

//析构函数
typedef int DataType;
class Stack
{
public:
	Stack(size_t capacity = 3)
	{
		_array = (DataType*)malloc(sizeof(DataType) * capacity);
		if (NULL == _array)
		{
			perror("malloc申请空间失败!!!");
			return;
		}
		_capacity = capacity;
		_size = 0;
	}
	void Push(DataType data)
	{
		// CheckCapacity();
		_array[_size] = data;
		_size++;
	}
	// 其他方法...
	~Stack()
	{
		cout << "~Stack" << endl;
		if (_array)
		{
			free(_array);
			_array = NULL;
			_capacity = 0;
			_size = 0;
		}
	}
private:
	DataType* _array;
	int _capacity;
	int _size;
};
void TestStack()
{
	Stack s;
	s.Push(1);
	s.Push(2);
}
class MyQueue
{
	Stack s1;
	Stack s2;
};
int main()
{
	//TestStack();
	MyQueue q;
	return 0;
}