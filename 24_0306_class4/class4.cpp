#include<iostream>
using namespace std;

//class Date
//{
//public:
//	Date(int a = 0)
//	{
//		_a = a;
//	}
//	~Date()
//	{
//		cout << "~Date()--" << _a << endl;
//	}
//
//private:
//	int _a;
//};
////（出栈的顺序）局部对象  >  局部静态  >  全局对象
//int main()
//{
//	Date d1(1);
//	Date d2(2);
//	//局部变量存放是在栈区
//	static Date d3(3);
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

////////////////////////
//拷贝构造
//class Date
//{
//public:
//    Date(int year = 1900, int month = 1, int day = 1)
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//    // Date(const Date& d)   // 正确写法
//    Date(const Date& d)   // 错误写法：编译报错，会引发无穷递归
//    {
//        _year = d._year;
//        _month = d._month;
//        _day = d._day;
//    }
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//int main()
//{
//    Date d1;
//    Date d2(d1);
//    return 0;
//}

//引用的权限放大缩小问题
//void func(const int& x)
//{
//	//...
//}
//int main()
//{
//	int a = 1;
//	const int& b = a;
//	//权限缩小，a是整形具有的权限是可读可修改
//	//权限放大是不可以的--如下所示
//	//const int c = 0;
//	//int& d = c;
//
//	const int& x = 10;
//	const int& y = 10 + a;
//	//常量以及表达式的返回时（属于临时变量）都具有常性
//	func(10);
//	func(y);
//	return 0;
//}

//深拷贝和浅拷贝的问题
//typedef int DataType;
//class Stack
//{
//public:
//	Stack(size_t capacity = 10)
//	{
//		_array = (DataType*)malloc(capacity * sizeof(DataType));
//		if (nullptr == _array)
//		{
//			perror("malloc申请空间失败");
//			return;
//		}
//		_size = 0;
//		_capacity = capacity;
//	}
//	void Push(const DataType& data)
//	{
//		// CheckCapacity();
//		_array[_size] = data;
//		_size++;
//	}
//	Stack(const Stack& s)
//	{
//		DataType* tmp = (DataType*)malloc((sizeof(DataType)) * s._capacity);
//		if (tmp == NULL)
//		{
//			perror("malloc error");
//			exit(-1);
//		}
//		_size = s._size;
//		_capacity = s._capacity;
//		memcpy(tmp, s._array, (sizeof(DataType)) * s._capacity);
//		_array = tmp;
//	}
//	~Stack()
//	{
//		if (_array)
//		{
//			free(_array);
//			_array = nullptr;
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//private:
//	DataType* _array;
//	size_t _size;
//	size_t _capacity;
//};
//int main()
//{
//	Stack s1;
//	s1.Push(1);
//	s1.Push(2);
//	s1.Push(3);
//	s1.Push(4);
//	Stack s2(s1);
//	return 0;
//}

//运算符重载
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
    {
        _year = year;
        _month = month;
        _day = day;
    }

    // bool operator==(Date* this, const Date& d2)
    // 这里需要注意的是，左操作数是this，指向调用函数的对象
    bool operator==(const Date & d2)
    {
        return _year == d2._year 
            && _month == d2._month
            && _day == d2._day;
    }
private:
    int _year;
    int _month;
    int _day;
};
int main()
{
    Date d1(2024, 3, 6);
    Date d2(2024, 3, 6);

    cout << d1.operator==(d2) << endl;
    cout << (d1 == d2) << endl;
    return 0;
}