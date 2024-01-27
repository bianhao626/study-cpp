#include <iostream>
using namespace std;

//struct A
//{
//private:
//	int _a;
//	char _i;
//};
//
//struct B
//{
//private:
//	char _i;
//	int _a;
//};
//
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
//
//int main()
//{
//	Date d1, d2;
//	d1.Init(2022, 1, 11);
//	d2.Init(2022, 1, 12);
//	d1.Print();
//	d2.Print();
//	return 0;
//}

//正常运行
//class A
//{
//public:
//	void Print()
//	{
//		//没有this的解引用
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

//class Date
//{
//public:
//	//Date()
//	//{
//	//	_year = 2017;
//	//	_month = 9;
//	//	_day = 1;
//	//}
//	Date(int year = 1, int month = 1, int day = 1)
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
//};
//
//int main()
//{
//	//构造函数
//	Date d1;
//	d1.Print();
//
//	Date d2(2024, 1, 27);
//	d2.Print();
//
//	Date d3(2024);
//	d3.Print();
//	return 0;
//}

//class A
//{
//public:
//	A()
//	{
//		cout << "A()" << endl;
//		cout << _a << endl;
//	}
//
//private:
//	int _a = 1;
//};
//class Date
//{
//public:
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
//	Date d1;
//	d1.Print();
//
//	return 0;
//}

//class Time
//{
//public:
//	~Time()
//	{
//		cout << "~Time()" << endl;
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Date
//{
//private:
//	// 基本类型(内置类型)
//	int _year = 1970;
//	int _month = 1;
//	int _day = 1;
//	// 自定义类型
//	Time _t;
//};
//int main()
//{
//	Date d;
//	return 0;
//}

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
		if (_array)
		{
			free(_array);
			_array = NULL;
			_capacity = 0;
			_size = 0;
		}
	}
private:
	//内置的类型
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
int main()
{
	TestStack();
	return 0;
}