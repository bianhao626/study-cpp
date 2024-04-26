#include<iostream>
#include<set>
#include<map>
#include<string>
using namespace std;

void test_set()
{
	//�����ȥ�أ��������޸�
	set<int> s1;
	s1.insert(1);
	s1.insert(11);
	s1.insert(2);
	s1.insert(4);
	s1.insert(3);

	//����ʹ�õ�����
	set<int>::iterator it = s1.begin();
	for (auto e : s1)
	{
		cout << e << endl;
	}
}

void test_map1()
{
	//Key_Valueģ��
	map<string, string> m;
	//����
	pair<string, string> kv1("sort", "����");
	m.insert(kv1);
	m.insert(pair<string, string>("hello","���"));
	m.insert(make_pair("right", "�ұ�"));
	m.insert({ "left","���" });

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
	//Key_Valueģ��
	map<string, string> m;
	m.insert({ "string","�ַ���" });

	//����
	m["right"];
	//����+�޸�value
	m["left"] = "���";
	//����
	cout << m["string"] << endl;
	//�޸�value
	m["right"] = "�ұ�";
}
int main()
{
	test_map2();
	return 0;
}