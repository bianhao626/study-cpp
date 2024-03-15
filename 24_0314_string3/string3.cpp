#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
void StringTest1()
{
	string filename("test.cpp");
	FILE* f = fopen(filename.c_str(), "r");
	//c_str兼容C而出现的
}
void StringTest2()
{
	string s1("file.cpp");
	size_t pos1 = s1.find('.');
	if (pos1 != string::npos)
	{
		string suffix = s1.substr(pos1);
		cout << suffix << endl;
	}
	else
	{
		cout << "none!" << endl;
	}
	string s2 = "abcd";
	string s3 = "acdf";
	cout << (s2 > s3) << endl;
	cout << (s2 != s3) << endl;
}
class Solution {
public:
	int firstUniqChar(string s) {
		int count[26] = { 0 };
		for (auto n : s)
		{
			count[n - 'a'] += 1;
		}
		for (int i = 0; i < s.size(); i++)
		{
			if (count[s[i] - 'a'] == 1)
			{
				return i;
			}
		}
		return -1;
	}
};
//int main()
//{
//	StringTest2();
//	string str;
//	//cin>>str
//	//解决输入读取空格失败的问题
//	getline(cin, str);
//
//	//char ch;
//	//ch = getchar();
//	//while (ch != '\n')
//	//{
//	//	str += ch;
//	//	ch = getchar();
//	//}
//
//	size_t pos = str.rfind(' ');
//	cout << (str.size() - (pos + 1)) << endl;
//	return 0;
//}

int main()
{
	char buff[] = "你好";
	cout << sizeof(buff) << endl; 

	buff[1]++;
	cout << buff << endl;

	int i = 1;
	double d = 2.1;
	string s1 = to_string(i);
	s1 += to_string(d);
	cout << s1 << endl;
	return 0;
}