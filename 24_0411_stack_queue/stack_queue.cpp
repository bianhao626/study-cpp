#include<iostream>
using namespace std;
#include<queue>

#include"Stack.h"
#include"Queue.h"

void test1()
{
	kuto::stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
}
void test2()
{
	kuto::queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	cout << q.back() << endl;
	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
	
}
void test_priority_queue()
{
	//大堆
	//priority_queue<int> q;
	//小堆
	priority_queue<int, vector<int>, greater<int>> q;
	q.push(1);
	q.push(5);
	q.push(2);
	q.push(3);

	//相当于是堆(大堆)
	cout << q.top() << endl;

}

//仿函数，像函数一样调用的类
//struct Less
//{
//	bool operator()(const int& x, const int& y)
//	{
//		return x < y;
//	}
//};

void mypriority()
{
	kuto::priority_queue<int, deque<int>, kuto::greater<int>> q;
	q.push(1);
	q.push(5);
	q.push(2);
	q.push(3);
	q.push(8);
	q.push(7);
	
	while (!q.empty())
	{
		cout << q.top() << endl;
		q.pop();
	}
}
int main()
{
	//test2();
	//test_priority_queue();
	/*Less lessfunc;
	cout << lessfunc(1, 2) << endl;
	cout << Less()(3, 4) << endl;*/

	mypriority();

	return 0;
}