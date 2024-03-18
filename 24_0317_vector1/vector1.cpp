#include<iostream>
#include<algorithm>
using namespace std;

#include<vector>

void test1()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);

	//���ֱ�����ʽ
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << '-';
	}
	cout << endl;

	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << endl;
		it++;
	}
	for (auto e : v)
	{
		cout << e << '-';
	}
	cout << endl;
}
void test2()
{
	size_t sz;
	vector<int> v;
	v.reserve(128);
	//��ǰ���ÿռ�Ͳ���������ݵ����
	sz = v.capacity();
	cout << "making v grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		v.push_back(i);
		if (sz != v.capacity())
		{
			sz = v.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}

	vector<int> a;
	a.resize(10, 1);
	//���ռ䲢���г�ʼ��
}
void test3()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	vector<int>::iterator pos = find(v.begin(), v.end(), 1);
	if(pos != v.end())
	{
		v.insert(pos, 100);
	}

	for (auto e : v)
	{
		cout << e << '-';
	}
	cout << endl;	
}
void test4()
{
	vector<string> v;
	string s1("ë��");
	v.push_back(s1);
	v.push_back(string("Ǧ��"));
	v.push_back("ü��");

	vector<vector<int>> vv;
	//��ά����Ķ��巽ʽ
}
int main()
{
	test4();
	return 0;
}