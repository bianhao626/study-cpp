#include<iostream>
using namespace std;
#include<assert.h>

//引用（受够了指针）所以引用就是起别名
//int main()
//{
//	int a = 1;
//
//	//引用，b就是a的别名
//	int& b = a;
//	//别名本质上就是一个东西
//	cout << &b << endl;
//	cout << &a << endl;
//	return 0;
//}


//引用的使用场景:
//做参数
//void Swap(int& a, int& b)
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//int main()
//{
//	int x = 2, y = 5;
//	Swap(x, y);
//	cout << x << " " << y << endl;
//	return 0;
//}

//1、一个变量可以有多个引用
//2、引用定义之后不可以更改指向
//C++的引用是为了替换指针使用比较复杂的场景，但是不能完全替代
//struct TreeNode
//{
//	int val;
//	struct TreeNode* left;
//	struct TreeNode* right;
//};
//void PushBack(struct TreeNode*& pphead, int x)
//{
//	pphead = NULL;
//}
//int main()
//{
//	struct TreeNode* p = NULL;
//	PushBack(p, 2);
//	return 0;
//}


//引用1、做参数（a、输出型参数|b、数据类型较大时、减少拷贝提高效率）
//#include <time.h>
//struct A 
//{ 
//	int a[10000]; 
//};
//void TestFunc1(A a) 
//{
//	//相当于对数据的拷贝进行操作
//}
//void TestFunc2(A& a) 
//{
//	//相当于对数据本身进行操作
//}
//void TestRefAndValue()
//{
//	A a;
//	// 以值作为函数参数
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc1(a);
//	size_t end1 = clock();
//	// 以引用作为函数参数
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc2(a);
//	size_t end2 = clock();
//	// 分别计算两个函数运行结束后的时间
//	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
//	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
//}
//int main()
//{
//	TestRefAndValue();
//	return 0;
//}
//////////////////////
//2、引用做返回值
//全局变量，堆上的数据
//int& f()
//{
//	int static a = 1;
//	return a;
//}
//int main()
//{
//	int& ret = f();
//	cout << ret << endl;
//	return 0;
//}

struct SeqList
{
	int* a;
	int size;
	int capaticy;

	void Init()
	{
		a = (int*)malloc(sizeof(int) * 4);
		size = 0;
		capaticy = 4;
	}

	void Push(int x)
	{
		a[size++] = x;
	}

	int& Get(int pos)
	{
		assert(pos >= 0);
		assert(pos < size);
		return a[pos];
	}
};
int main()
{
	SeqList s;
	s.Init();
	s.Push(1);
	s.Push(2);
	s.Push(3);
	s.Push(8);

	for (int i = 0; i < s.size; i++)
	{
		cout << s.Get(i) << " ";
	}
	cout << endl;
	for (int i = 0; i < s.size; i++)
	{
		if (s.Get(i) % 2 == 0)
		{
			s.Get(i) *= 2;
		}
	}
	for (int i = 0; i < s.size; i++)
	{
		cout << s.Get(i) << " ";
	}
	cout << endl;
	return 0;
}

/////////////////////////////////////
//内联函数