#include<iostream>
using namespace std;

//class MyClass
//{
//public:
//	MyClass(int x = 0)
//		:_n(x)
//	{
//		cout << "MyClass(int x):" << _n << "-" << this << endl;
//	}
//	~MyClass()
//	{
//		cout << "~MyClass()" << endl;
//	}
//private:
//	int _n;
//};
//int main()
//{
//	MyClass* p1 = new MyClass;
//	MyClass* p2 = new MyClass[10]{ 1,2,3,4 };
//	return 0;
//}

//class A
//{
//public:
//	A(int a = 0)
//		: _a(a)
//	{
//		cout << "A():" << this << endl;
//	}
//	~A()
//	{
//		cout << "~A():" << this << endl;
//	}
//private:
//	int _a;
//};
/////////////////////////////////////////

//Ä£°å
//void Swap(int& left, int& right)
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}
//void Swap(double& left, double& right)
//{
//	double temp = left;
//	left = right;
//	right = temp;
//}
//void Swap(char& left, char& right)
//{
//	char temp = left;
//	left = right;
//	right = temp;
//}
//º¯ÊýÄ£°å
//template<typename T>
//void Swap(T& x, T& y)
//{
//	T tmp = x;
//	x = y;
//	y = tmp;
//}
//int main()
//{
//	int a = 1, b = 9;
//	Swap(a, b);
//	return 0;
//}

//template<class T1, class T2>
//T2 Add1(T1 left, T2 right)
//{
//	return left + right;
//}
//void Test()
//{
//	Add1(1, 2);
//	Add1(1, 2.0);
//}
template<class T>
T Add2(const T& x, const T& y)
{
	return x + y;
}
int main()
{
	/*Test();*/
	double x = 1.1, y = 3.2;
	cout << Add2(1.1, 4.2) << endl;
	return 0;
}