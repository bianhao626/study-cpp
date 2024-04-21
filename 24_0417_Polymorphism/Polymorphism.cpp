#include<iostream>
using namespace std;

//class Person 
//{
//public:
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//};
//class Student : public Person 
//{
//public:
//	virtual void BuyTicket() { cout << "买票-半价" << endl; }
//};
//
////多态条件
////1、父子类完成虚函数重写（函数名，参数，返回值都要求一样）
////2、必须使用父类的指针或者引用调用虚函数
//void Func(Person& p)
//{
//	//不同的对象做同一件事情，呈现的形态不一样
//	p.BuyTicket();
//}
//int main()
//{
//	Person ps;
//	Student st;
//	Func(ps);
//	Func(st);
//
//	return 0;
//}

//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Func1()" << endl;
//	}
//private:
//	//存在虚函数，就会有虚表指针
//	//32位，四个字节
//	int _b = 1;
//};
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Base::Func1()" << endl;
//	}
//	virtual void Func2()
//	{
//		cout << "Base::Func2()" << endl;
//	}
//	void Func3()
//	{
//		cout << "Base::Func3()" << endl;
//	}
//private:
//	//只会有一个虚表指针
//	int _b = 1;
//};
//class Derive : public Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Derive::Func1()" << endl;
//	}
//private:
//	int _d = 2;
//};
//
//int main()
//{
//	Base b;
//	Derive d;
//	cout << sizeof(b) << endl;
//	return 0;
//}

//class Person 
//{
//public:
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//private:
//	int _a = 1;
//};
//
//class Student : public Person 
//{
//public:
//	virtual void BuyTicket() { cout << "买票-半价" << endl; }
//private:
//	int _b = 1;
//};
//void Func(Person& p)
//{
//	p.BuyTicket();
//}
//
//int main()
//{
//	Person Mike;
//	Func(Mike);
//	Student Johnson;
//	Func(Johnson);
//	return 0;
//}

class Base {
public:
	virtual void func1() { cout << "Base::func1" << endl; }
	virtual void func2() { cout << "Base::func2" << endl; }
private:
	int a;
};
class Derive :public Base {
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
	virtual void func4() { cout << "Derive::func4" << endl; }
private:
	int b;
};

typedef void(*VFP)();
void PrintPath(VFP* ptr)
{
	for (size_t i = 0; i < 4; i++)
	{
		printf("%p->", ptr[i]);
		(*ptr[i])();
	}
	cout << endl;
}

int main()
{
	Derive d;
	//虚函数表是一个函数指针数组
	VFP* p = (VFP*)(*((int*)(&d)));
	PrintPath(p);

	return 0;
}