#include<iostream>
using namespace std;

//������:����ʵ����������
//���Ҫ��������������д
//class Car
//{
//public:
//	//���麯��
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

//����麯����������麯���ĵ�ַ��Ŀ����ʵ�ֶ�̬
//��������ڵ�ǰλ������ಿ�ֵ�ƫ������������μ̳���������Ͷ�����

//class Person {
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
//};
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-���" << endl; }
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
//	//ͬ���͵Ķ�����һ�����
//	//��������ڣ�--������
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	//ջ����ʱ������
//	int* p = new int;
//	//����
//	static int b = 10;
//	//��̬��
//	const char* s = "xxxxxx";
//	//������
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
//	// ����ȡ����е��麯��ָ���ӡ�����á����þͿ��Կ���������ĸ�����
//	cout << " ����ַ>" << vTable << endl;
//	for (int i = 0; vTable[i] != nullptr; ++i)
//	{
//		printf(" ��%d���麯����ַ :0X%x,->", i, vTable[i]);
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

//��̳�
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
//	cout << " ����ַ>" << vTable << endl;
//	for (int i = 0; vTable[i] != nullptr; ++i)
//	{
//		printf(" ��%d���麯����ַ :0X%x,->", i, vTable[i]);
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

//���μ̳е�����
//��������̳е�����

/////////////////////////////////////////
//����������
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
	dict.Insert("string", "�ַ���");
	dict.Insert("left", "��");
	dict.Insert("right", "��");
	dict.Insert("insert", "����");

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
	// ͳ��ˮ�����ֵĴ���
	string arr[] = { "ƻ��", "����", "ƻ��", "����", "ƻ��", "ƻ��", "����",
   "ƻ��", "�㽶", "ƻ��", "�㽶" };
	KV::BSTree<string, int> countTree;
	for (const auto& str : arr)
	{
		// �Ȳ���ˮ���ڲ�����������
		// 1�����ڣ�˵��ˮ����һ�γ��֣������<ˮ��, 1>
		// 2���ڣ�����ҵ��Ľڵ���ˮ����Ӧ�Ĵ���++
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