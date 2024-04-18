#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//dd爱框框
//int main()
//{
//	int n, x;
//	cin >> n >> x;
//
//	vector<int> v(n + 1);
//	for (size_t i = 1; i < n; i++)
//	{
//		cin >> v[i];
//	}
//
//	int left = 1, right = 1;
//	int sum = 0;
//	int len = n + 1, leftpos = -1, rightpos = -1;
//	while (right <= n)
//	{
//		//1、入窗口
//		sum += v[right];
//		//2、出窗口
//		while (sum >= x)
//		{
//			//3、出窗口之前先更新
//			if ((right - left + 1) < len)
//			{
//				len = right - left + 1;
//				leftpos = left;
//				rightpos = right;
//			}
//			sum -= v[left++];
//		}
//		right++;
//	}
//
//	cout << leftpos << " " << rightpos << endl;
//	return 0;
//}

//除2！
typedef long long LL;
LL n, k;

priority_queue<LL> heap;
int main()
{
	cin >> n >> k;

	LL tmp = 0, sum = 0;
	//1、先进性筛选，把对应的偶数放入堆中
	while (n--)
	{
		cin >> tmp;
		if (tmp % 2 == 0)
		{
			heap.push(tmp);
		}
		else
		{
			sum += tmp;
		}
	}
	//2、把堆顶的偶数拿出来，然后除2
	//除2之后是偶数放回去，不是偶数直接加sum中
	while (k-- && !heap.empty())
	{
		LL t = heap.top() / 2;
		heap.pop();
		if (t % 2 == 0)
		{
			heap.push(t);
		}
		else
		{
			sum += t;
		}
	}
	while (!heap.empty())
	{
		LL t = heap.top();
		heap.pop();
		sum += t;
	}
	cout << sum << endl;

	return 0;
}