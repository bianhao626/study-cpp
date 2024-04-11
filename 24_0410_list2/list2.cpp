#include"list.h"
using namespace kuto;

void Test1()
{
	list<int> t1;
	t1.push_back(1);
	t1.push_back(2);
	t1.push_back(3);
	list<int>::iterator it = t1.begin();
	for (auto e : t1)
	{
		cout << e << " ";
	}
	cout << endl;
	t1.pop_back();
	for (auto e : t1)
	{
		cout << e << " ";
	}
	cout << endl;

}
void Test2()
{
	struct A
	{
		int _a1;
		int _a2;

		A(int a1 = 0, int a2 = 0)
			:_a1(a1)
			,_a2(a2)
		{}
	};
	list<A> list_a;
	A aa(1, 2);
	list_a.push_back(aa);
	list_a.push_back({ 1,1 });
	list_a.push_back(A(4, 5));
	list<A>::iterator it = list_a.begin();
	while (it != list_a.end())
	{

		cout << it->_a1 << "," << it->_a2 << endl;
		it++;
	}
}
void Test3()
{
	list<int> t1;
	t1.push_back(1);
	t1.push_back(2);
	t1.push_back(3);
	Print(t1);
	list<int> t2(t1);
	Print(t2);
	list<int> t3;
	t3.push_back(10);
	t3 = t1;
	Print(t3);

}
int main()
{
	Test3();
	return 0;
}