#include<iostream>
using namespace std;

//using std::cout;
//using std::endl;
//
//namespace bit
//{
//	//�����ռ�֮���������
//	namespace zs
//	{
//		void Push()
//		{
//			cout << "zs" << endl;
//		}
//	}
//	namespace ls
//	{
//		void Push()
//		{
//			cout << "ls" << endl;
//		}
//	}
//}
//
//int main()
//{
//	//�����ռ��ʹ��
//	int i = 0;
//	std::cin >> i;
//	cout << "xxxxxx" << endl;
//
//	bit::zs::Push();
//	bit::ls::Push();
//	return 0;
//}

//using namespace std;
//int main()
//{
//	//C++����C����
//	int i = 2;
//	i = i << 1;
//	const char* str = "hello world!";
//	char ch;
//	cout << i << endl;
//
//	cin >> i >> ch;
//	cout << str << i << ch << endl;
//	return 0;
//}

//ȱʡ/Ĭ�� ����
//void Fun(int a = 0)
//{
//	//һ��ȱʡ����
//	cout << a << endl;
//}
//void Func(int a, int b = 10, int c = 20)
//{
//	//���ȱʡ����
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//}
//int main()
//{
//	Fun(1);
//	Fun();
//	Func(1, 3, 4);
//	return 0;
//}

//struct Stack
//{
//	int* a;
//	int size;
//	int capacity;
//};
//void StackInit(struct Stack* ps, int n = 4)
//{
//	ps->a = (int*)malloc(sizeof(int) * n);
//
//}
//int main()
//{
//	//��������100
//	struct Stack ps1;
//	StackInit(&ps1, 100);
//	//��������10
//	struct Stack ps2;
//	StackInit(&ps2, 10);
//	//��֪�������������
//	struct Stack ps3;
//	StackInit(&ps3);
//	return 0;
//}

//��������
int Add(int left, int right)
{
	cout << "int Add(int left, int right)" << endl;
	return left + right;
}
double Add(double left, double right)
{
	cout << "double Add(double left, double right)" << endl;
	return left + right;
}
// 2������������ͬ
void f()
{
	cout << "f()" << endl;
}
void f(int a)

{
	cout << "f(int a)" << endl;
}
// 3����������˳��ͬ
void f(int a, char b)
{
	cout << "f(int a,char b)" << endl;
}
void f(char b, int a)
{
	cout << "f(char b, int a)" << endl;
}
int main()
{
	cout << Add(1, 2) << endl;
	cout << Add(1.12, 15.6) << endl;
	return 0;
}