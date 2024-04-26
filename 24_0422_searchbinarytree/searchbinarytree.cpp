#include<iostream>
using namespace std;

//抽象类:不能实例化出对象
//间接要求完成派生类的重写
//class Car
//{
//public:
//	//纯虚函数
//	virtual void Drive() = 0;
//};
//class Benz : public Car
//{
//public:
//	//virtual void Drive()
//	//{
//	//	cout << "Benz" << endl;
//	//}
//};
//
//int main()
//{
//	//Car c;
//	Benz b;
//	b.Drive();
//	return 0;
//}

//虚表：虚函数表，存的是虚函数的地址，目标是实现多态
//虚基表：存在当前位置虚基类部分的偏移量，解决菱形继承数据冗余和二义性

//class Person {
//public:
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//};
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "买票-半价" << endl; }
//};
//void Func(Student p)
//{
//	p.BuyTicket();
//}
//int main()
//{
//	//Person Mike;
//	//Func(Mike);
//	Student Johnson;
//	Func(Johnson);
//	//同类型的对象是一个虚表
//	//所以虚表在？--常量区
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	//栈（临时变量）
//	int* p = new int;
//	//堆区
//	static int b = 10;
//	//静态区
//	const char* s = "xxxxxx";
//	//常量区
//}

//class Base {
//public:
//	virtual void func1() { cout << "Base::func1" << endl; }
//	virtual void func2() { cout << "Base::func2" << endl; }
//private:
//	int a;
//};
//class Derive :public Base {
//public:
//	virtual void func1() { cout << "Derive::func1" << endl; }
//	virtual void func3() { cout << "Derive::func3" << endl; }
//	virtual void func4() { cout << "Derive::func4" << endl; }
//private:
//	int b;
//};
//typedef void(*VFPTR) ();
//void PrintVTable(VFPTR vTable[])
//{
//	// 依次取虚表中的虚函数指针打印并调用。调用就可以看出存的是哪个函数
//	cout << " 虚表地址>" << vTable << endl;
//	for (int i = 0; vTable[i] != nullptr; ++i)
//	{
//		printf(" 第%d个虚函数地址 :0X%x,->", i, vTable[i]);
//		VFPTR f = vTable[i];
//		f();
//	}
//	cout << endl;
//}
//int main()
//{
//	Base b;
//	Derive d;
//	VFPTR* vTableb = (VFPTR*)(*(int*)&b);
//	PrintVTable(vTableb);
//	VFPTR* vTabled = (VFPTR*)(*(int*)&d);
//	PrintVTable(vTabled);
//
//	cout << sizeof(d) << endl;
//	return 0;
//}

//多继承
//class Base1 {
//public:
//	virtual void func1() { cout << "Base1::func1" << endl; }
//	virtual void func2() { cout << "Base1::func2" << endl; }
//private:
//	int b1;
//};
//class Base2 {
//public:
//	virtual void func1() { cout << "Base2::func1" << endl; }
//	virtual void func2() { cout << "Base2::func2" << endl; }
//private:
//	int b2;
//};
//class Derive : public Base1, public Base2 {
//public:
//	virtual void func1() { cout << "Derive::func1" << endl; }
//	virtual void func3() { cout << "Derive::func3" << endl; }
//private:
//	int d1;
//};
//typedef void(*VFPTR) ();
//void PrintVTable(VFPTR vTable[])
//{
//	cout << " 虚表地址>" << vTable << endl;
//	for (int i = 0; vTable[i] != nullptr; ++i)
//	{
//		printf(" 第%d个虚函数地址 :0X%x,->", i, vTable[i]);
//		VFPTR f = vTable[i];
//		f();
//	}
//	cout << endl;
//}
//int main()
//{
//	Derive d;
//	VFPTR* vTableb1 = (VFPTR*)(*(int*)&d);
//	PrintVTable(vTableb1);
//	VFPTR* vTableb2 = (VFPTR*)(*(int*)((char*)&d + sizeof(Base1)));
//	PrintVTable(vTableb2);
//	return 0;
//}

//菱形继承的问题
//菱形虚拟继承的问题

/////////////////////////////////////////
//搜索二叉树
#include<iostream>
using namespace std;
#include"bst.h"
//int main()
//{
//	int a[] = { 8,3,1,10,6,4,7,14,13 };
//	BSTree<int> t;
//	for (auto e : a)
//	{
//		t.Insert(e);
//	}
//	t.InOrder();
//
//	for (auto e : a)
//	{
//		t.erase(e);
//		t.InOrder();
//	}
//	return 0;
//}
void TestBSTree3()
{
	KV::BSTree<string, string> dict;
	dict.Insert("string", "字符串");
	dict.Insert("left", "左");
	dict.Insert("right", "右");
	dict.Insert("insert", "插入");

	string str;
	while (cin >> str)
	{
		KV::BSTreeNode<string, string>* ret = dict.FindNode(str);
		if (ret)
		{
			cout << ret->_value << endl;
		}
		else
		{
			cout << '0' << endl;
		}
	}
}
void TestBSTree4()
{
	// 统计水果出现的次数
	string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜",
   "苹果", "香蕉", "苹果", "香蕉" };
	KV::BSTree<string, int> countTree;
	for (const auto& str : arr)
	{
		// 先查找水果在不在搜索树中
		// 1、不在，说明水果第一次出现，则插入<水果, 1>
		// 2、在，则查找到的节点中水果对应的次数++
		//BSTreeNode<string, int>* ret = countTree.Find(str);
		auto ret = countTree.FindNode(str);
		if (ret == NULL)
		{
			countTree.Insert(str, 1);
		}
		else
		{
			ret->_value++;
		}
	}
	countTree.InOrder();
}


#include<string>
int main()
{
	TestBSTree4();
	return 0;
}