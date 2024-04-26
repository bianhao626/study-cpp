#include<iostream>
#include<set>
#include<map>
#include<string>
using namespace std;

void test_set()
{
	//排序加去重，不允许修改
	set<int> s1;
	s1.insert(1);
	s1.insert(11);
	s1.insert(2);
	s1.insert(4);
	s1.insert(3);

	//可以使用迭代器
	set<int>::iterator it = s1.begin();
	for (auto e : s1)
	{
		cout << e << endl;
	}
}

void test_map1()
{
	//Key_Value模型
	map<string, string> m;
	//排序
	pair<string, string> kv1("sort", "排序");
	m.insert(kv1);
	m.insert(pair<string, string>("hello","你好"));
	m.insert(make_pair("right", "右边"));
	m.insert({ "left","左边" });

	for (auto& e : m)
	{
		cout << e.first << ":" << e.second << endl;
	}
	auto it = m.begin();
	while (it != m.end())
	{
		cout << it->first << ":" << it->second << endl;
		it++;
	}
}
void test_map2()
{
	//Key_Value模型
	map<string, string> m;
	m.insert({ "string","字符串" });

	//插入
	m["right"];
	//插入+修改value
	m["left"] = "左边";
	//查找
	cout << m["string"] << endl;
	//修改value
	m["right"] = "右边";
}
int main()
{
	test_map2();
	return 0;
}