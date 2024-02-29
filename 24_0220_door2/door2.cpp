#include<iostream>
using namespace std;

//using std::cout;
//using std::endl;
//
//namespace bit
//{
//	//命名空间之间可以套娃
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
//	//命名空间的使用
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
//	//C++兼容C语言
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

//缺省/默认 参数
//void Fun(int a = 0)
//{
//	//一个缺省参数
//	cout << a << endl;
//}
//void Func(int a, int b = 10, int c = 20)
//{
//	//多个缺省参数
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
//	//插入数据100
//	struct Stack ps1;
//	StackInit(&ps1, 100);
//	//插入数据10
//	struct Stack ps2;
//	StackInit(&ps2, 10);
//	//不知道插入多少数据
//	struct Stack ps3;
//	StackInit(&ps3);
//	return 0;
//}

//函数重载
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
// 2、参数个数不同
void f()
{
	cout << "f()" << endl;
}
void f(int a)

{
	cout << "f(int a)" << endl;
}
// 3、参数类型顺序不同
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