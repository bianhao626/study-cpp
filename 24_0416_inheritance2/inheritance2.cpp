#include<iostream>
#include<string>

using namespace std;

//class Student;
//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name; // 姓名
//};
//class Student : public Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	int _stuNum; // 学号
//};
//void Display(const Person& p, const Student& s)
//{
//	cout << p._name << endl;
//	//父类的友元（朋友），不是子类的友元--友元不可以继承
//	cout << s._stuNum << endl;
//	//解决方案就是--既是父类的朋友又是子类的朋友
//}

class Person
{
public:
	Person() { ++_count; }
protected:
	string _name; // 姓名
public:
	static int _count; // 统计人的个数。
};
int Person::_count = 0;
class Student : public Person
{
protected:
	int _stuNum; // 学号
};
class Graduate : public Student
{
protected:
	string _seminarCourse; // 研究科目
};
void TestPerson()
{
	Student s1;
	Student s2;
	Student s3;
	Graduate s4;
	cout << " 人数 :" << Person::_count << endl;
	Student::_count = 0;
	cout << " 人数 :" << Person::_count << endl;
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
	//实践中可以设计多继承，但是不要设计菱形继承

	return 0;
}