#include<iostream>
using namespace std;

//1����һ������--��װ
//���ݺͷ����ŵ�һ������ⲿ���ʵĶ���Ϊ���У�������ⲿ���ʵĶ����˽��
//һ�����ͷŵ���һ���������棬ͨ��typedef��Ա������������װ��һ��ȫ�µ�����

//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//protected:
//	string _name = "peter"; // ����
//	int _age = 18;  // ����
//	int _num = 1;
//};
//
//class Student : public Person
//{
//public:
//	void func()
//	{
//		cout << _num << endl;
//		cout << Person::_num << endl;
//	}
//protected:
//	int _stuid; // ѧ��
//	int _num = 12;
//};
//class Teacher : public Person
//{
//protected:
//	int _jobid; // ����
//};


class A
{
public:
	void fun()
	{
		cout << "func()" << endl;
	}
};
class B : public A
{
public:
	void fun(int i)
	{
		A::fun();
		cout << "func(int i)->" << i << endl;
	}
};

class Person
{
public:
	Person(const char* name = "peter")
		: _name(name)
	{
		cout << "Person()" << endl;
	}

	Person(const Person& p)
		: _name(p._name)
	{
		cout << "Person(const Person& p)" << endl;
	}

	Person& operator=(const Person& p)
	{
		cout << "Person operator=(const Person& p)" << endl;
		if (this != &p)
			_name = p._name;

		return *this;
	}

	~Person()
	{
		cout << "~Person()" << endl;
	}
protected:
	string _name; // ����
};
class Student : public Person
{
public:
	Student(const char* name, int num)
		: Person(name)
		, _num(num)
	{
		cout << "Student()" << endl;
	}

	Student(const Student& s)
		: Person(s)
		, _num(s._num)
	{
		cout << "Student(const Student& s)" << endl;
	}

	Student& operator = (const Student& s)
	{
		cout << "Student& operator= (const Student& s)" << endl;
		if (this != &s)
		{
			Person::operator =(s);
			_num = s._num;
		}
		return *this;
	}

	~Student()
	{
		cout << "~Student()" << endl;
	}
protected:
	int _num; //ѧ��
};

void Test()
{
	Student s1("jack", 18);
	Student s2(s1);
	Student s3("rose", 17);
	s1 = s3;
}

int main()
{
	//B b;
	//b.fun(10);
	//b.A::fun();

	Test();
	return 0;
}