#include<iostream>
using namespace std;

//class A
//{
//public:
//	A(int a)
//	//A(int a)������Ҳ���Ĭ�Ϲ��캯���ı���
//		:_a(a)
//	{
//		cout << "int a = " << _a << endl;
//	}
//private:
//	int _a;
//};
//
//class Date
//{
//public:
//	Date(int year, int month, int day, int& x)
//		:_year(year)
//		,_month(month)
//		,_day(day)
//		,_n(1)
//		,_ret(x)
//		,_aa(1)
//	{}
//private:
//	//����
//	int _year;
//	int _month;
//	int _day;
//
//	//�����������ͱ����߳�ʼ���б�
//	const int _n;
//	int& _ret;
//	A _aa;
//};
//
//int main()
//{
//	int x = 10;
//	Date d(2024, 3, 8, x);
//	return 0;
//}

//class A
//{
//private:
//	int _a = 1;
//	int* _p1 = nullptr;
//	int* _p2 = (int*)malloc(sizeof(int) * 4);
//};
//class B
//{
//public:
//	B(int x = 0)
//		:_x(x)
//	{}
//private:
//	int _x;
//};
//int main()
//{
//	B bb1(1);
//	B bb2 = 1;
//	//B& bb3 = 1;
//	//����д�Ĵ���֮�����ڣ�������ʽ���ȹ�����ʱ������Ȼ���ٵ��ù��캯��
//	//��ʱ�����Ǿ��г��ԣ����Գ�����Ȩ�޷Ŵ������
//	const B& bb3 = 1;
//	//������д������ȷ��
//	int i = 1;
//	//double& j = i;
//	//�������Ĵ�����һ����
//	const double& j = i;
//	return 0;
//}
///////////////////////////////
//class A
//{
//public:
//    A(int a)
//        :_a1(a)
//        , _a2(_a1)
//    {}
//
//    void Print() {
//        cout << _a1 << " " << _a2 << endl;
//    }
//private:
//    //��ʼ���ǰ�������˳����е�
//    int _a2;
//    int _a1;
//};
//int main() {
//    A aa(1);
//    aa.Print();
//}
//1 ���ֵ
/////////////////////////////////////
class A
{
public:
	A() 
	{ 
		++_scount; 
	}
	A(const A & t) 
	{ 
		++_scount; 
	}
	~A() 
	{ 
		--_scount; 
	}
	//static��Ա������û��thisָ���
	static int GetACount() 
	{ 
		return _scount; 
	}
private:
	//����
	//��������ĳһ�������������ж��������������
	static int _scount;
};
int A::_scount = 0;
void TestA()
{
	cout << A::GetACount() << endl;
	A a1, a2;
	A a3(a1);
	cout << A::GetACount() << endl;
	cout << a1.GetACount() << endl;
}
int main()
{
	return 0;
}