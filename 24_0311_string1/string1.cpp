#include<iostream>
using namespace std;

//int main()
//{
//	int x = 10, y = 9;
//	swap(x, y);
//	//C++库中有一个swap的模板
//	double a = 1.0, b = 3.9;
//	swap(a, b);
//
//	cout << x << " " << y << endl;
//	cout << a << " " << b << endl;
//	return 0;
//}

#include<string>
#include<vector>
void StringTest()
{
	string s0;
	string s1("hello,string!");
	string s2(s1);
	string s3(s1, 5);
	string s4(s1, 5, 3);
	string s5(s1, 5, 10);

	cout << s0 << endl;
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s5 << endl;

	string s6(10, '#');
	cout << s6 << endl;
}
void StringTest2()
{
	string s1("hello,string!");

	string::iterator it1 = s1.begin();
	while (it1 != s1.end())
	{
		cout << *it1;
		it1++;
	}
	cout << endl;

	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	vector<int>::iterator it2 = v.begin();
	while (it2 != v.end())
	{
		cout << *it2;
		it2++;
	}
	cout << endl;
	for (auto e : v)
	{
		cout << e;
	}
	cout << endl;
}
int main()
{
	StringTest2();
	return 0;
}