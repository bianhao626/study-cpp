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
//չ��std�����ռ䣬�����Ϳ���ֱ�ӷ����ڲ���������������
//int main()
//{
//	cout << "hello!" << endl;
//	//endl�൱����\n������
//	return 0;
//}

//void Func(int a = 0)
//{
//	cout << a << endl;
//}
//int main()
//{
//	Func();     // û�д���ʱ��ʹ�ò�����Ĭ��ֵ
//	Func(10);   // ����ʱ��ʹ��ָ����ʵ��
//	return 0;
//}

//#include<iostream>
//using namespace std;
//// 1���������Ͳ�ͬ
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
//// 2������������ͬ
//void f()
//{
//	cout << "f()" << endl;
//}
//void f(int a)
//{
//	cout << "f(int a)" << endl;
//}
//// 3����������˳��ͬ
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
    int& ra = a;//<====������������
    printf("%p\n", &a);
    printf("%p\n", &ra);
}
int main()
{
    TestRef();
    return 0;
}