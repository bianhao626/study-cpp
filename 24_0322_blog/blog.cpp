//#include <stdio.h>
//#include <stdlib.h>
//int rand = 10;
//
//int main()
//{
//	printf("%d\n", rand);
//	return 0;
//}

//#include<iostream>
//namespace kuto
//{
//	int rand = 10;
//	namespace kuto_1
//	{
//		int a = 1;
//	}
//}
//namespace kuto
//{
//	int b = 0;
//}
//
//int main()
//{
//	printf("%d\n", kuto::rand);
//	printf("%d\n", kuto::kuto_1::a);
//	return 0;
//}

//#include<iostream>
//namespace kuto
//{
//	int a = 10;
//}
//using namespace kuto;
//int main()
//{
//	printf("%d\n", a);
//	return 0;
//}

//#include<iostream>
//using namespace std;
//展开std命名空间，这样就可以直接访问内部的输入输出运算符
//int main()
//{
//	cout << "hello!" << endl;
//	//endl相当于是\n的作用
//	return 0;
//}

//void Func(int a = 0)
//{
//	cout << a << endl;
//}
//int main()
//{
//	Func();     // 没有传参时，使用参数的默认值
//	Func(10);   // 传参时，使用指定的实参
//	return 0;
//}

//#include<iostream>
//using namespace std;
//// 1、参数类型不同
//int Add(int left, int right)
//{
//	cout << "int Add(int left, int right)" << endl;
//	return left + right;
//}
//double Add(double left, double right)
//{
//	cout << "double Add(double left, double right)" << endl;
//	return left + right;
//}
//// 2、参数个数不同
//void f()
//{
//	cout << "f()" << endl;
//}
//void f(int a)
//{
//	cout << "f(int a)" << endl;
//}
//// 3、参数类型顺序不同
//void f(int a, char b)
//{
//	cout << "f(int a,char b)" << endl;
//}
//void f(char b, int a)
//{
//	cout << "f(char b, int a)" << endl;
//}
//int main()
//{
//	Add(10, 20);
//	Add(10.1, 20.2);
//	f();
//	f(10);
//	f(10, 'a');
//	f('a', 10);
//	return 0;
//}

#include<iostream>
void TestRef()
{
    int a = 10;
    int& ra = a;//<====定义引用类型
    printf("%p\n", &a);
    printf("%p\n", &ra);
}
int main()
{
    TestRef();
    return 0;
}