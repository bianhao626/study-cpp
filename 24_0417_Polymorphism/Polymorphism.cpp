#include<iostream>
using namespace std;

//class Person 
//{
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
//};
//class Student : public Person 
//{
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-���" << endl; }
//};
//
////��̬����
////1������������麯����д��������������������ֵ��Ҫ��һ����
////2������ʹ�ø����ָ��������õ����麯��
//void Func(Person& p)
//{
//	//��ͬ�Ķ�����ͬһ�����飬���ֵ���̬��һ��
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
//	//�����麯�����ͻ������ָ��
//	//32λ���ĸ��ֽ�
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
//	//ֻ����һ�����ָ��
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
//	virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
//private:
//	int _a = 1;
//};
//
//class Student : public Person 
//{
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-���" << endl; }
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
	//�麯������һ������ָ������
	VFP* p = (VFP*)(*((int*)(&d)));
	PrintPath(p);

	return 0;
}