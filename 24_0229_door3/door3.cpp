#include<iostream>
using namespace std;
#include<assert.h>

//���ã��ܹ���ָ�룩�������þ��������
//int main()
//{
//	int a = 1;
//
//	//���ã�b����a�ı���
//	int& b = a;
//	//���������Ͼ���һ������
//	cout << &b << endl;
//	cout << &a << endl;
//	return 0;
//}


//���õ�ʹ�ó���:
//������
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

//1��һ�����������ж������
//2�����ö���֮�󲻿��Ը���ָ��
//C++��������Ϊ���滻ָ��ʹ�ñȽϸ��ӵĳ��������ǲ�����ȫ���
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


//����1����������a������Ͳ���|b���������ͽϴ�ʱ�����ٿ������Ч�ʣ�
//#include <time.h>
//struct A 
//{ 
//	int a[10000]; 
//};
//void TestFunc1(A a) 
//{
//	//�൱�ڶ����ݵĿ������в���
//}
//void TestFunc2(A& a) 
//{
//	//�൱�ڶ����ݱ�����в���
//}
//void TestRefAndValue()
//{
//	A a;
//	// ��ֵ��Ϊ��������
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc1(a);
//	size_t end1 = clock();
//	// ��������Ϊ��������
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc2(a);
//	size_t end2 = clock();
//	// �ֱ���������������н������ʱ��
//	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
//	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
//}
//int main()
//{
//	TestRefAndValue();
//	return 0;
//}
//////////////////////
//2������������ֵ
//ȫ�ֱ��������ϵ�����
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
//��������