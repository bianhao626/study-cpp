#include<iostream>
using namespace std;

//class Date
//{
//	friend ostream& operator<<(ostream& _cout, const Date& d);
//	//��Ԫ����
//	friend istream& operator>>(istream& _cin, Date& d);
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//ostream& operator<<(ostream& _cout, const Date& d)
//{
//	_cout << d._year << "-" << d._month << "-" << d._day;
//	return _cout;
//}
//istream& operator>>(istream& _cin, Date& d)
//{
//	_cin >> d._year;
//	_cin >> d._month;
//	_cin >> d._day;
//	return _cin;
//}
//int main()
//{
//	Date d;
//	cin >> d;
//	cout << d << endl;
//	return 0;
//}

//class Time
//{
//    friend class Date;
//    //����������Ϊʱ�������Ԫ�࣬�����������о�ֱ�ӷ���Time���е�˽�г�Ա����
//public:
//    Time(int hour = 0, int minute = 0, int second = 0)
//        : _hour(hour)
//        , _minute(minute)
//        , _second(second)
//    {}
//
//private:
//    int _hour;
//    int _minute;
//    int _second;
//};
//class Date
//{
//public:
//    Date(int year = 1900, int month = 1, int day = 1)
//        : _year(year)
//        , _month(month)
//        , _day(day)
//    {}
//
//    void SetTimeOfDate(int hour, int minute, int second)
//    {
//        // ֱ�ӷ���ʱ����˽�еĳ�Ա����
//        _t._hour = hour;
//        _t._minute = minute;
//        _t._second = second;
//    }
//
//private:
//    int _year;
//    int _month;
//    int _day;
//    Time _t;
//};

//class A
//{
//private:
//    static int k;
//    int h;
//public:
//    class B // B��������A����Ԫ���ܵ����������
//    {
//    public:
//        void foo(const A& a)
//        {
//            cout << k << endl;//OK
//            cout << a.h << endl;//OK
//        }
//    };
//};
//int A::k = 1;
//int main()
//{
//    A::B b;
//    b.foo(A());
//    return 0;
//}

//class A
//{
//public:
//	A(int a = 0)
//		:_a(a)
//	{
//		cout << "A(int a)" << endl;
//	}
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//private:
//	int _a;
//};
//int main()
//{
//	//��������
//	A aa1;
//	A aa2(2);
//	//��������,��������ֻ�ڵ�ǰ��һ��
//	A();
//	A(11);
//	
//	return 0;
//}
///////////////////////////////////////
//��������ʱ���������Ż�
class Test
{
public:
	Test(int a = 0)
		:_a(a)
	{
		//����
		cout << "Test(int a = 0)" << endl;
	}
	Test(const Test& n)
		:_a(n._a)
	{
		//��������
		cout << "Test(const Test& n)" << endl;
	}
	Test& operator=(const Test& n)
	{
		//��ֵ����
		cout << "Test& operator=(const Test& n)" << endl;
		if (this != &n)
		{
			_a = n._a;
		}
		return *this;
	}
	~Test()
	{
		//��������
		cout << "~Test()" << endl;
	}
private:
	int _a;
};
//void func1(Test t)
//{
//	//...
//}
//void func2(const Test& t)
//{
//	//...
//}
//int main()
//{
//	Test t;
//	func1(t);
//	func2(t);
//
//	return 0;
//}

Test func3()
{
	Test t;
	return t;
	//���������򣬾ͻ�����t�Ŀ�����Ϊ����ֵ
}
Test func4()
{
	return Test();
}
int main()
{
	//Test ret = func3();
	Test ret;
	ret = func4();
	return 0;
}