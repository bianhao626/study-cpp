//day15
//#include <cmath>
//#include <cstdlib>
//#include <iostream>
//using namespace std;
//
//int main()
//{
//    long long n;
//    cin >> n;
//
//    long long num = (int)sqrt(n);
//    int len1 = abs(num * num - n);
//    int len2 = abs((num + 1) * (num + 1) - n);
//    if (len1 > len2)
//    {
//        cout << (num + 1) * (num + 1);
//    }
//    else
//    {
//        cout << num * num;
//    }
//    return 0;
//}

//#include <iostream>
//#include <map>
//using namespace std;
//
//int n, m;
//map<int, int> tmp;
//
//bool Check(int x)
//{
//	int group = 0;
//	map<int, int>::iterator it = tmp.begin();
//	while (it != tmp.end())
//	{
//		group += (*it).second / x;
//		group += (*it).second % x == 0 ? 0 : 1;
//		it++;
//	}
//	return group <= m;
//}
//int main()
//{
//	//输入数据
//	cin >> n >> m;
//	int max_group = 0;
//	for (int i = 0; i < n; i++)
//	{
//		int x;
//		cin >> x;
//		max_group = max(max_group, ++tmp[x]);
//	}
//
//	//对数据进行处理
//	int kind = tmp.size();//计算一共有多少种声部
//	if (kind > m)
//	{
//		cout << -1 << endl;
//	}
//	else
//	{
//		//从一个人一个声部开始找，符合条件的情况
//		for (int i = 1; i <= max_group; i++)
//		{
//			if (Check(i))
//			{
//				cout << i << endl;
//				break;
//			}
//		}
//	}
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//
//const int N = 2e5 + 10;
////存储边的信息
//vector<vector<int>> edges(N);
////记录一个点的入度信息
//int d[N];
//
//int n, m;
//queue<int> q;
//vector<int> ret;
//
//int main()
//{
//	cin >> n >> m;
//	for (int i = 0; i < m; i++)
//	{
//		int a, b;
//		cin >> a >> b;
//		//记录边的信息，然后记录度
//		edges[a].push_back(b);
//		//b的入度加一
//		d[b]++;
//	}
//
//	//把入度0的节点加入到队列中
//	for (int i = 1; i <= n; i++)
//	{
//		if (d[i] == 0)
//		{
//			q.push(i);
//		}
//	}
//	
//	while (q.size())
//	{
//		int a = q.front();
//		q.pop();
//		ret.push_back(a);
//		//和a相关的点处理
//		for (auto e : edges[a])
//		{
//			if (--d[e] == 0)
//			{
//				q.push(e);
//			}
//		}
//	}
//
//	if (ret.size() == n)
//	{
//		for (int i = 0; i < n-1; i++)
//		{
//			cout << ret[i] << " ";
//		}
//		cout << ret[n - 1];
//	}
//	else
//	{
//		cout << -1 << endl;
//	}
//
//	return 0;
//}

//day16
//#include <cctype>
//#include <string>
//class Solution
//{
//public:
//    string formatString(string str, vector<char>& arg)
//    {
//        string ret;
//        int j = 0;
//        for (int i = 0; i < str.size(); i++)
//        {
//            if (!isalpha(str[i]))
//            {
//                ret.push_back(arg[j++]);
//                i++;
//            }
//            else
//            {
//                ret.push_back(str[i]);
//            }
//        }
//
//        while (j < arg.size())
//        {
//            ret.push_back(arg[j++]);
//        }
//        return ret;
//    }
//};

//#include <iostream>
//#include <vector>
//using namespace std;
//
//int a, b;
//
//int main()
//{
//	int num[21] = { 11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
//	int hashnum[100] = { 0 };
//	for (int i = 0; i < 21; i++)
//	{
//		hashnum[num[i]]++;
//	}
//
//	//枚举！！！！！！！！！
//	cin >> a >> b;
//	vector<int> tmp;
//	int count = 0, flag = 0;
//	for (int i = a; i <= b; i++)
//	{
//		int tmp_i = i;
//		while (tmp_i)
//		{
//			tmp.push_back(tmp_i % 10);
//			tmp_i /= 10;
//		}
//		//枚举进行组合
//		int flag = 0;
//		for (int x = 0; x < tmp.size(); x++)
//		{
//			for (int y = 0; y < tmp.size(); y++)
//			{
//				if (x != y && tmp[x] != 0)
//				{
//					int sum = 10 * tmp[x] + tmp[y];
//					if (hashnum[sum] != 0)
//					{
//						count += 1;
//						flag = 1;
//						break;
//					}
//				}
//			}
//			if (flag == 1)
//			{
//				flag = 0;
//				break;
//			}
//
//		}
//		tmp.clear();
//	}
//	cout << count << endl;
//	return 0;
//}

#include <iostream>
#include <string>
using namespace std;

string str;
int n;

int num(int x, int n)
{
	int count = 0;
	for (int i = x; i < x+n; i++)
	{
		if (str[i] == 'C' || str[i] == 'G')
		{
			count++;
		}
	}
	return count;
}

int main()
{
	//滑动窗口的题目
	//但是题目这句话就跟智障一样！！！TMD误导人(DNA序列为 ACGT 的子串有: ACG , CG , CGT 等等，但是没有 AGT ， CT 等等)
	cin >> str >> n;
	int left = 0, right = n - 1;

	//记录最多的个数以及起始位置
	int len = 0, begin = 0;
	while(right < str.size())
	{
		int ret = num(left, n);
		if (ret > len)
		{
			len = ret;
			begin = left;
		}
		left++;
		right++;
	}
	string retstr;
	while (n--)
	{
		retstr.push_back(str[begin++]);
	}
	cout << retstr << endl;

	return 0;
}