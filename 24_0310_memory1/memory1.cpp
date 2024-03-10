#include<iostream>
using namespace std;

//int globalVar = 1;
//static int staticGlobalVar = 1;
//void Test()
//{
//	static int staticVar = 1;
//	int localVar = 1;
//	int num1[10] = { 1, 2, 3, 4 };
//	char char2[] = "abcd";
//	const char* pChar3 = "abcd";
//	int* ptr1 = (int*)malloc(sizeof(int) * 4);
//	int* ptr2 = (int*)calloc(4, sizeof(int));
//	int* ptr3 = (int*)realloc(ptr2, sizeof(int) * 4);
//	free(ptr1);
//	free(ptr3);
//}
//int main()
//{
//	Test();
//	//注意上面的变量都在内存空间中的哪个区域
//	return 0;
//}

//int main()
//{
//	//基础语法
//	int* p1 = new int;
//	int* p2 = new int[10];
//	delete p1;
//	delete[] p2;
//
//	int* p3 = new int(10);
//	cout << *p3 << endl;
//	int* p4 = new int[10] {1, 2, 3, 4, 5, 6, 7};
//	delete p3;
//	delete[] p4;
//
//	return 0;
//}

struct ListNode
{
	ListNode* _front;
	ListNode* _next;
	int _val;

	ListNode(int n)
		:_front(nullptr)
		,_next(nullptr)
		,_val(n)
	{}
};
ListNode* CreatList(int n)
{
	ListNode head(-1);
	ListNode* tail = &head;
	int val;
	printf("请依次输入%d个数据:", n);
	for (size_t i = 0; i < n; i++)
	{
		cin >> val;
		tail->_next = new ListNode(val);
		tail = tail->_next;
	}
	return head._next;
}

int main()
{
	ListNode* list = CreatList(5);
	return 0;
}