#include<iostream>
using namespace std;

//inline int Add(int a, int b)
//{
//	return a + b;
//}
//int main()
//{
//	int x = 1, y = 2;
//	cout << Add(x, y) << endl;
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	auto b = 12;
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	return 0;
//}

//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8 };
//	for (auto e : arr)
//	{
//		cout << e << endl;
//	}
//	return 0;
//}

//class MyClass
//{
//public:
//	void Init(int age = 0,int year = 0,int month = 0)
//	{
//		_age = age;
//		_year = year;
//		_month = month;
//	}
//	void Print()
//	{
//		cout << _age << "-" << _year << "-" << _month << endl;
//	}
//private:
//	int _age;
//	int _year;
//	int _month;
//};
//int main()
//{
//	MyClass a1;
//	a1.Init(25, 1999, 3);
//	MyClass a2;
//	a2.Init(18, 2005, 10);
//
//	a1.Print();
//	a2.Print();
//	return 0;
//}

//���е�����Ĭ�ϳ�Ա����
//1����ʼ��
//1.1�����캯��--��Ҫ��ɳ�ʼ������
//1.2����������--������
//2����������
//2.1����������--��ʼ����������
//2.2����һ������ֵ����һ������
//3��ȡ��ַ����

class Date
{
public:
    Date(int year, int month, int day)
    {
    _year = year;
    _month = month;
    _day = day;
    }
    ~Date()
    {
        cout << "~Date()" << endl;
    }
    void Print()
    {
        cout << _year << "-" << _month << "-" << _day << endl;
    }

private:
    int _year;
    int _month;
    int _day;
};

int main()
{
    Date d1(1998, 2, 3);
    d1.Print();
    return 0;
}
