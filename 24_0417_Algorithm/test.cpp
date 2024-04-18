#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//dd�����
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
//		//1���봰��
//		sum += v[right];
//		//2��������
//		while (sum >= x)
//		{
//			//3��������֮ǰ�ȸ���
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

//��2��
typedef long long LL;
LL n, k;

priority_queue<LL> heap;
int main()
{
	cin >> n >> k;

	LL tmp = 0, sum = 0;
	//1���Ƚ���ɸѡ���Ѷ�Ӧ��ż���������
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
	//2���ѶѶ���ż���ó�����Ȼ���2
	//��2֮����ż���Ż�ȥ������ż��ֱ�Ӽ�sum��
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