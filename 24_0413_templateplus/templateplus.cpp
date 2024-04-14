#include<iostream>
using namespace std;

//函数参数（T 对象1， T 对象2...）
//模板参数 <class T1, class T2...>

template<class T1, class T2>
class Data
{
public:
	Data() { cout << "Data<T1, T2>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};

//全特化
template<>
class Data<int, char>
{
public:
	Data() { cout << "Data<int, char>" << endl; }
private:
	int _d1;
	char _d2;
};
//偏特化
template <class T1>
class Data<T1, int>
{
public:
	Data() { cout << "Data<T1, int>" << endl; }
private:
	T1 _d1;
	int _d2;
};
//两个参数偏特化为指针类型
template <typename T1, typename T2>
class Data <T1*, T2*>
{
public:
	Data() { cout << "Data<T1*, T2*>" << endl; }

private:
	T1 _d1;
	T2 _d2;
};
//两个参数偏特化为引用类型
template <typename T1, typename T2>
class Data <T1&, T2&>
{
public:
	Data(const T1& d1, const T2& d2)
		: _d1(d1)
		, _d2(d2)
	{
		cout << "Data<T1&, T2&>" << endl;
	}

private:
	const T1& _d1;
	const T2& _d2;
};

void TestVector()
{
	Data<int, int> d1;
	Data<int, char> d2;
	Data<int*, string*> d3;
	Data<int&, int&> d4(1, 2);
}


#include"template.h"
int main()
{
	//TestVector();
	return 0;
}