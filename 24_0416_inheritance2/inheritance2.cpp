#include<iostream>
#include<string>

using namespace std;

//class Student;
//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name; // ����
//};
//class Student : public Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	int _stuNum; // ѧ��
//};
//void Display(const Person& p, const Student& s)
//{
//	cout << p._name << endl;
//	//�������Ԫ�����ѣ��������������Ԫ--��Ԫ�����Լ̳�
//	cout << s._stuNum << endl;
//	//�����������--���Ǹ���������������������
//}

class Person
{
public:
	Person() { ++_count; }
protected:
	string _name; // ����
public:
	static int _count; // ͳ���˵ĸ�����
};
int Person::_count = 0;
class Student : public Person
{
protected:
	int _stuNum; // ѧ��
};
class Graduate : public Student
{
protected:
	string _seminarCourse; // �о���Ŀ
};
void TestPerson()
{
	Student s1;
	Student s2;
	Student s3;
	Graduate s4;
	cout << " ���� :" << Person::_count << endl;
	Student::_count = 0;
	cout << " ���� :" << Person::_count << endl;
}
class A
{
public:
	int _a;
};
// class B : public A
class B : virtual public A
{
public:
	int _b;
};
// class C : public A
class C : virtual public A
{
public:
	int _c;
};
class D : public B, public C
{
public:
	int _d;
};

int main()
{
	//TestPerson();
	D d;
	d.B::_a = 1;
	d.C::_a = 2;
	d._b = 3;
	d._c = 4;
	d._d = 5;
	//ʵ���п�����ƶ�̳У����ǲ�Ҫ������μ̳�

	return 0;
}