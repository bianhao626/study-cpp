#include"class2.h"

//int main()
//{
//	//auto�Զ�ʶ������
//	auto i = 2;
//	int j = 1;
//	auto p = &j;
//	auto& r = j;
//	return 0;
//}

//autoʹ�ó���
//void func(int a, int b)
//{
//	//...
//}
//int main()
//{
//	void(*p1)(int, int) = func;
//	//����ָ��
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
//��Ͷ���
//�����Ͷ������
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
//	//���壬����ʵ����
//	s.Init(2019, 12, 1);
//	s.Print();
//	return 0;
//}
// ���н��г�Ա����
//class A2 
//{
//public:
//	void f2() {}
//};
//// ����ʲô��û��---����
//class A3
//{};
//
//int main()
//{
//	MyClass p1;
//	A2 p2;
//	A3 p3;
//	//ʵ������֮��Ϊ�˱�ʾ����ڹ�������û�г�Ա��������Ĵ�С��1
//	cout << sizeof(p1) << endl;
//	cout << sizeof(p2) << endl;
//	cout << sizeof(p3) << endl;
//	return 0;
//}

//С����
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
	//��Ա�����Ǵ���ڹ�������ģ������ȥ����������
	p2->print();
	//���λ�ò����ǽ����ã����Ǻ�thisָ���й�
	return 0;
}