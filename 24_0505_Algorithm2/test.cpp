//day17
//#include <algorithm>
//#include <iostream>
//#include <vector>
//using namespace std;
//
//int n;
//vector<int> v;
//
//int main()
//{
//    cin >> n;
//    int tmp = n;
//    while (tmp)
//    {
//        if ((tmp % 10) % 2 == 0)
//        {
//            v.push_back(0);
//        }
//        else
//        {
//            v.push_back(1);
//        }
//        tmp /= 10;
//    }
//
//    reverse(v.begin(), v.end());
//    //处理前导0
//    int i = 0;
//    while (i < v.size() && v[i] == 0)
//    {
//        i++;
//    }
//    if (i == v.size())
//    {
//        cout << 0;
//    }
//    else
//    {
//        for (int j = i; j < v.size(); j++)
//        {
//            cout << v[j];
//        }
//    }
//
//    return 0;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//int n, m;
//typedef long long LL;
//
//int main()
//{
//    cin >> n >> m;
//    vector<vector<LL>> vv(n, vector<LL>(m));
//    vector<LL> row(n, 0);
//    //记录每一行数据的总和
//    vector<LL> col(m, 0);
//    //记录每一列数据的总和
//    for (int i = 0; i < n; i++)
//    {
//        LL sum = 0;
//        for (int j = 0; j < m; j++)
//        {
//            scanf("%lld", &vv[i][j]);
//            sum += vv[i][j];
//        }
//        row[i] = sum;
//    }
//
//    for (int j = 0; j < m; j++)
//    {
//        LL sum = 0;
//        for (int i = 0; i < n; i++)
//        {
//            sum += vv[i][j];
//        }
//        col[j] = sum;
//    }
//
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < m; j++)
//        {
//            LL ret = row[i] + col[j] - vv[i][j];
//            cout << ret << " ";
//        }
//        cout << endl;
//    }
//    return 0;
//}

//#include <iostream>
//using namespace std;
//
//typedef long long LL;
//int n, k;
//const int N = 10e5 + 10;
//LL hsum[N], ssum[N];//前缀和的问题
//
//int main()
//{
//	cin >> n >> k;
//	hsum[0] = ssum[0] = 0;
//	//记录前缀和
//	for (int i = 1; i <= n; i++)
//	{
//		LL tmp = 0;
//		cin >> tmp;
//		hsum[i] = tmp + hsum[i - 1];
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		LL tmp = 0;
//		cin >> tmp;
//		ssum[i] = tmp + ssum[i - 1];
//	}
//
//	LL hmax = 0, smin = 0, begin = 0;
//	for (int i = 1; i <= n-k+1; i++)
//	{
//		LL tmph = hsum[i + k - 1] - hsum[i - 1];
//		LL tmps = ssum[i + k - 1] - ssum[i - 1];
//		//更新数据
//		if (tmph > hmax)
//		{
//			begin = i;
//			hmax = tmph;
//			smin = tmps;
//		}
//		else if(tmph == hmax && tmps < smin)
//		{
//			begin = i;
//			hmax = tmph;
//			smin = tmps;
//		}
//	}
//	cout << begin << endl;
//	return 0;
//}

//day18
//#include <iostream>
//#include <string>
//using namespace std;
//
//class Solution
//{
//public:
//    string compressString(string param)
//    {
//        string ret;
//        int left = 0, right = 1;
//        while (right < param.size())
//        {
//            if (param[left] != param[right])
//            {
//                ret.push_back(param[left]);
//                if (right - left != 1)
//                {
//                    int tmp = right - left;
//                    ret += to_string(tmp);
//                }
//                left = right;
//                right++;
//            }
//            else
//            {
//                right++;
//            }
//        }
//        ret.push_back(param[left]);
//        if (right - left != 1)
//        {
//            int tmp = right - left;
//            ret += to_string(tmp);
//        }
//        return ret;
//    }
//};
//
//int main()
//{
//    Solution s;
//    cout << s.compressString("aaaaaaaaaaaaaaaaaabccddd");
//    return 0;
//}

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//const int N = 2e5 + 10;
//typedef long long LL;
//int n, k;
//struct Orange
//{
//    LL c;
//    LL sweet;
//    bool operator< (const Orange& tmp) const
//    {
//        if (sweet != tmp.sweet)
//        {
//            return sweet > tmp.sweet;
//        }
//        else
//        {
//            return c < tmp.c;
//        }
//    }
//};
//vector<Orange> v(N);
//
//int main()
//{
//    cin >> n >> k;
//    //记录下俩酸和甜的数值
//    for (int i = 1; i <= n; i++)
//    {
//        cin >> v[i].c;
//    }
//    for (int i = 1; i <= n; i++)
//    {
//        cin >> v[i].sweet;
//    }
//    sort(v.begin(), v.end());
//
//    LL sweet_num = 0, c_num = 0;
//    for (int i = 0; i < k; i++)
//    {
//        c_num += v[i].c;
//        sweet_num += v[i].sweet;
//    }
//    
//    cout << c_num << " " << sweet_num << endl;
//    return 0;
//}

//背包问题
//动态规划
#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>
class Solution
{
    int dp[1010] = { 0 };
public:
    int knapsack(int V, int n, vector<vector<int> >& vw)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = V; j >= vw[i][0]; j--)
            {
                dp[j] = max(dp[j], dp[j - vw[i][0]] + vw[i][1]);
            }
        }
        return dp[V];
    }
};

int main()
{
    vector<vector<int>> vw(2,vector<int>(2));
    vw[0][0] = 1;
    vw[0][1] = 3;
    vw[1][0] = 9;
    vw[1][1] = 8;
    Solution s;
    cout << s.knapsack(10, 2, vw);
    return 0;
}