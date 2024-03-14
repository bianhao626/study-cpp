#include<iostream>
using namespace std;
#include<string>

void StringTest()
{
	string s1("abcdefg");
	//反向迭代器
	string::reverse_iterator rit = s1.rbegin();
	while (rit != s1.rend())
	{
		//普通迭代器可读可写
		(*rit)++;
		cout << *rit;
		rit++;
	}
	cout << endl;

	const string s2("abcdefghij");
	string::const_iterator cit = s2.begin();
	//const迭代器只读，不可写
	while (cit != s2.end())
	{
		//(*cit)++;不可写
		cout << *cit;
		cit++;
	}
	cout << endl;
}
void StringTest2()
{
	string s1("abcdefg");
	cout << s1.size() << endl;
	cout << s1.length() << endl;
	//cout << s1.max_size() << endl;
	cout << s1.capacity() << endl;
}
void StringTest3()
{
	string s1("abcdefghijklmnopq!");
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;

	s1.reserve(20);
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;

	string s2;
	s2.resize(100, 'x');
	cout << s2.size() << endl;
	cout << s2.capacity() << endl;
	cout << s2 << endl;
}
void StringTest4()
{
	string s1("abcdefghijklmnopq!");
	cout << s1[5] << endl;
	cout << s1.at(5) << endl;
	try
	{
		//s1[35];
		//异常不会被捕获，程序直接崩溃
		s1.at(35);
		//异常会被捕获
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}
}
void StringTest5()
{
	string s1("abcdefghijklmnopq!");
	s1.push_back('-');
	cout << s1 << endl;

	s1.append("xxxx");
	cout << s1 << endl;

	string s2(s1);
	s2 += ' ';
	s2 += "apple";
	cout << s2 << endl;
}
void StringTest6()
{
	string s1("abcdefghijklmnopq!");
	s1.assign("xxx");
	cout << s1 << endl;

	s1.insert(0, "yyy");
	cout << s1 << endl;
	s1.erase(2, 1);
	cout << s1 << endl;
	string s2("i am fine!");
	string s3;
	for (auto ch : s2)
	{
		if (ch != ' ')
		{
			s3 += ch;
		}
		else
		{
			s3 += "20%";
		}
	}
	cout << s3 << endl;
}

//415. 字符串相加
class Solution {
public:
	string addStrings(string num1, string num2) {
		int len1 = num1.size() - 1, len2 = num2.size() - 1;
		string retstr;
		int next = 0;
		while (len1 >= 0 || len2 >= 0)
		{
			int val1 = len1 >= 0 ? num1[len1--] - '0' : 0;
			int val2 = len2 >= 0 ? num2[len2--] - '0' : 0;
			int ret = val1 + val2 + next;

			next = ret / 10;
			ret = ret % 10;

			retstr += (ret + '0');
		}
		if (next == 1)
		{
			retstr += '1';
		}
		reverse(retstr.begin(), retstr.end());
		return retstr;
	}
};
int main()
{
	//StringTest6();
	Solution s1;
	string s = s1.addStrings("111", "98");
	cout << s << endl;
	return 0;
}