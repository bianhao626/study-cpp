#include"vector.h"
using namespace kuto;

void test1()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	print_vector(v1);

	v1.pop_back();
	print_vector(v1);
}
void test2()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	print_vector(v1);

	v1.resize(7, 100);
	print_vector(v1);
}
void test3()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);

	vector<int> v2;
	v2.push_back(100);
	v2.push_back(23);
	v1.swap_vector(v2);
	print_vector(v1);
	print_vector(v2);

	vector<int> v3(v1);
	print_vector(v3);

	v2 = v1;
	print_vector(v2);
}
void test4()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	print_vector(v1);
	v1.insert(v1.begin(), 5);
	print_vector(v1);
	v1.insert(v1.begin() + 3, 5);
	print_vector(v1);
	v1.erase(v1.end() - 1);
	print_vector(v1);
	v1.erase(v1.begin() + 1);
	print_vector(v1);
}
void test5()
{
	vector<int> v1(4, 100);
	print_vector(v1);
	vector<double> v2(5, 1.1);
	print_vector(v2);
}
void test6()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	vector<int> v2(v1.begin(), v1.end());
	print_vector(v2);
}
void test7()
{
	vector<string> v1;
	v1.push_back("111");
	v1.push_back("222");
	v1.push_back("333");
	v1.push_back("444");
	v1.push_back("555");
	print_vector(v1);
}
void test8()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	//迭代器失效的问题
	auto it = v1.begin()+2;
	v1.insert(it, 40);
	print_vector(v1);
	//失效的迭代器就不要使用！！！
	cout << *it << endl;
}
void test9()
{
	//迭代器失效的问题
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(4);
	
	//迭代器的使用需要进行更新
	auto it = v1.begin();
	while (it != v1.end())
	{
		if (*it % 2 == 0)
		{
			it = v1.erase(it);
		}
		else
		{
			it++;
		}
	}
	print_vector(v1);
}
int main()
{
	test9();
	return 0;
}