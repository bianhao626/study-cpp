#include<iostream>
using namespace std;

//class A
//{
//public:
//	A(int a)
//	//A(int a)会出现找不到默认构造函数的报错
//		:_a(a)
//	{
//		cout << "int a = " << _a << endl;
//	}
//private:
//	int _a;
//};
//
//class Date
//{
//public:
//	Date(int year, int month, int day, int& x)
//		:_year(year)
//		,_month(month)
//		,_day(day)
//		,_n(1)
//		,_ret(x)
//		,_aa(1)
//	{}
//private:
//	//声明
//	int _year;
//	int _month;
//	int _day;
//
//	//以下三种类型必须走初始化列表
//	const int _n;
//	int& _ret;
//	A _aa;
//};
//
//int main()
//{
//	int x = 10;
//	Date d(2024, 3, 8, x);
//	return 0;
//}

//class A
//{
//private:
//	int _a = 1;
//	int* _p1 = nullptr;
//	int* _p2 = (int*)malloc(sizeof(int) * 4);
//};
//class B
//{
//public:
//	B(int x = 0)
//		:_x(x)
//	{}
//private:
//	int _x;
//};
//int main()
//{
//	B bb1(1);
//	B bb2 = 1;
//	//B& bb3 = 1;
//	//这样写的错误之处在于，这个表达式会先构造临时变量，然后再调用构造函数
//	//临时变量是具有常性，所以出现了权限放大的问题
//	const B& bb3 = 1;
//	//这样的写法是正确的
//	int i = 1;
//	//double& j = i;
//	//和上述的错误是一样的
//	const double& j = i;
//	return 0;
//}
///////////////////////////////
//class A
//{
//public:
//    A(int a)
//        :_a1(a)
//        , _a2(_a1)
//    {}
//
//    void Print() {
//        cout << _a1 << " " << _a2 << endl;
//    }
//private:
//    //初始化是按照声明顺序进行的
//    int _a2;
//    int _a1;
//};
//int main() {
//    A aa(1);
//    aa.Print();
//}
//1 随机值
/////////////////////////////////////
class A
{
public:
	A() 
	{ 
		++_scount; 
	}
	A(const A & t) 
	{ 
		++_scount; 
	}
	~A() 
	{ 
		--_scount; 
	}
	//static成员函数是没有this指针的
	static int GetACount() 
	{ 
		return _scount; 
	}
private:
	//声明
	//不是属于某一个对象，属于所有对象，属于整个类的
	static int _scount;
};
int A::_scount = 0;
void TestA()
{
	cout << A::GetACount() << endl;
	A a1, a2;
	A a3(a1);
	cout << A::GetACount() << endl;
	cout << a1.GetACount() << endl;
}
int main()
{
	return 0;
}