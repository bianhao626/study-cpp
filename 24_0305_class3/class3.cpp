#include<iostream>
using namespace std;

//��֮����ڴ����
//#pragma pack(1)
//class A
//{
//private:
//	int i;
//	char j;
//};
//class B
//{
//private:
//	char i;
//	int j;
//};
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
//	int _year;     // ��
//	int _month;    // ��
//	int _day;      // ��
//};
////��Ա��������һ��������thisָ�룬һ���ǳ�Ա�����ĵ�һ������
//int main()
//{
//	Date d1, d2;
//	d1.Init(2022, 1, 11);
//	d2.Init(2022, 1, 12);
//	d1.Print();
//	d2.Print();
//	//����ͬһ������������������ͬ�����ݵ�
//
//	return 0;
//}

//class A
//{
//public:
//	void Print()
//	{
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

//class A
//{
//public:
//	void PrintA()
//	{
//		cout << _a << endl;
//	}
//private:
//	int _a;
//};
//int main()
//{
//	A* p = nullptr;
//	p->PrintA();
//	return 0;
//}

////////////////////////////
//���캯����Ϊ�˳�ʼ��
//class A
//{
//public:
//	A()
//	{
//		cout << "A()" << endl;
//		_a = 0;
//	}
//private:
//	int _a;
//};
//class MyClass
//{
//public:
//	//MyClass()
//	//{
//	//	_year = 1;
//	//	_month = 1;
//	//	_day = 1;
//	//}
//	MyClass(int year = 1, int month = 1, int day = 1)
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
//
//	A _aa;
//};
//int main()
//{
//	//���캯��һ�����ڶ���ʵ������ʱ�����ָ������
//	MyClass a1;
//	//Ϊ�˺ͺ������������ֿ����涨�޲�����ʱ���ǲ����Լ����ŵ�
//	a1.Print();
//	MyClass a2(2024, 3, 5);
//	a2.Print();
//	return 0;
//}

//��������/��������   int/char/ָ���   �����Լ������������
//�Զ�������    struct/class
//Ĭ�����ɵĹ��캯���������������Ͳ��������Զ������ͻ��������Ĭ�Ϲ��캯��

//��������
typedef int DataType;
class Stack
{
public:
	Stack(size_t capacity = 3)
	{
		_array = (DataType*)malloc(sizeof(DataType) * capacity);
		if (NULL == _array)
		{
			perror("malloc����ռ�ʧ��!!!");
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
	// ��������...
	~Stack()
	{
		cout << "~Stack" << endl;
		if (_array)
		{
			free(_array);
			_array = NULL;
			_capacity = 0;
			_size = 0;
		}
	}
private:
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
class MyQueue
{
	Stack s1;
	Stack s2;
};
int main()
{
	//TestStack();
	MyQueue q;
	return 0;
}