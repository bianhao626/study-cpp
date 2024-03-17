#include"string4.h"
using namespace kuto;

void test1()
{
	MyString s1("abcdef");
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;

	for (size_t i = 0; i < s1.size(); i++)
	{
		cout << ++s1[i] << ' ';
	}
	cout << endl;
	const MyString s2("hello");
	for (size_t i = 0; i < s2.size(); i++)
	{
		cout << s2[i] << ' ';
	}
	cout << endl;
}
void test2()
{
	MyString s1("abcdef");
	//迭代器
	MyString::iterator it = s1.begin();
	while (it != s1.end())
	{
		cout << *it << "-";
		it++;
	}
	cout << endl;
	for (auto n : s1)
	{
		cout << n << "-";
	}
	cout << endl;

	//const对象调用const迭代器
	const MyString s2("hello");
	MyString::const_iterator it2 = s2.begin();
	while (it2 != s2.end())
	{
		cout << *it2 << "-";
		it2++;
	}
	cout << endl;
}
void test3()
{
	MyString s1("aloha");
	s1.push_back('!');
	cout << s1.c_str() << endl;
	s1.append("626!");
	cout << s1.c_str() << endl;
	s1 += '!';
	cout << s1.c_str() << endl;

	s1.insert(0, '!');
	cout << s1.c_str() << endl;
	s1.erase(3, 1);
	cout << s1.c_str() << endl;

	//s1.resize(5);
	//cout << s1.c_str() << endl;
	s1.resize(20, 'c');
	cout << s1.c_str() << endl;

	s1.insert(3, "---");
	cout << s1.c_str() << endl;
	MyString s2("xxx");
	s1 = s2;
	cout << s1.c_str() << endl;
	MyString s3(s1);
	cout << s1.c_str() << endl;
}
void test4()
{
	MyString s1("xxx");
	MyString s2 = "hello";
	s1.swap(s2);

	cout << s1.c_str() << endl;
	cout << s2.c_str() << endl;

	cout << s1.find('e') << endl;
	cout << s2.find("xy") << endl;

	MyString s3 = s1.substr(1, 2);
	cout << s3.c_str() << endl;
}
void test5()
{
	MyString s1("hello");
	MyString s2("helloq");
	cout << (s2 > s1) << endl;

	cout << s1 << endl;

	cin >> s1;
	cout << s1 << endl;
	getline(cin, s1);
	cout << s1 << endl;
}
void test6()
{
	MyString s1("hello");
	cin >> s1;
	cout << s1.capacity() << endl;
	MyString s2(s1);
	cout << s2 << endl;
}
int main()
{
	//test6();

	std::string s1("11111");
	cout << sizeof(s1) << endl;
	MyString s2("11111");
	cout << sizeof(s2) << endl;
	size_t a = 0;
	cout << sizeof(a) << endl;
	return 0;
}