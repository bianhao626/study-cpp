#include"class2.h"

//int main()
//{
//	//auto自动识别类型
//	auto i = 2;
//	int j = 1;
//	auto p = &j;
//	auto& r = j;
//	return 0;
//}

//auto使用场景
//void func(int a, int b)
//{
//	//...
//}
//int main()
//{
//	void(*p1)(int, int) = func;
//	//函数指针
//	auto p2 = func;
//
//	cout << typeid(p1).name() << endl;
//	cout << typeid(p2).name() << endl;
//	return 0;
//}

//void f(int)
//{
//	cout << "f(int)" << endl;
//}
//void f(int*)
//{
//	cout << "f(int*)" << endl;
//}
//int main()
//{
//	f(0);
//	f(NULL);
//	f((int*)NULL);
//	return 0;
//}

///////////////////////////////////
//类和对象
//声明和定义分离
//void MyClass::Init(int year, int month, int day)
//{
//	_year = year;
//	_month = month;
//	_day = day;
//}
//void MyClass::Print()
//{
//	cout << _year << ":" << _month << ":" << _day << endl;
//}
//int main()
//{
//	MyClass s;
//	//定义，对象实例化
//	s.Init(2019, 12, 1);
//	s.Print();
//	return 0;
//}
// 类中仅有成员函数
//class A2 
//{
//public:
//	void f2() {}
//};
//// 类中什么都没有---空类
//class A3
//{};
//
//int main()
//{
//	MyClass p1;
//	A2 p2;
//	A3 p3;
//	//实例化类之后，为了表示类存在过，所以没有成员变量的类的大小是1
//	cout << sizeof(p1) << endl;
//	cout << sizeof(p2) << endl;
//	cout << sizeof(p3) << endl;
//	return 0;
//}

//小测试
class A
{
public:
	void print()
	{
		cout << "class f" << endl;
	}
};
int main()
{
	A a;
	A* p1 = &a;
	p1->print();

	A* p2 = nullptr;
	//成员函数是存放在公共区域的，因此是去公共区域找
	p2->print();
	//这个位置并不是解引用，而是和this指针有关
	return 0;
}