//day10
//时间复杂度是N^2----运行超时
//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//    int n;
//    cin >> n;
//
//    //写入数据
//    vector<int> prices(n);
//    int i = 0;
//    while (i < n)
//    {
//        cin >> prices[i++];
//    }
//
//    int maxcount = 0;
//    //动态规划计算出每一天的最大收益
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = i + 1; j < n; j++)
//        {
//            int count = (prices[j] - prices[i]) > 0 ? (prices[j] - prices[i]) : 0;
//            maxcount = count > maxcount ? count : maxcount;
//        }
//    }
//
//    cout << maxcount;
//    return 0;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//    int n;
//    cin >> n;
//
//    //写入数据
//    vector<int> prices(n);
//    int i = 0;
//    while (i < n)
//    {
//        cin >> prices[i++];
//    }
//
//    //动态规划的思想
//    vector<int> tmp(n);
//    tmp[0] = 0;
//    for (int i = 1; i < n; i++)
//    {
//        int num = prices[i] - prices[i - 1];
//        tmp[i] = num + tmp[i - 1] > num ? num + tmp[i - 1] : num;
//    }
//
//    int max = 0;
//    for (auto e : tmp)
//    {
//        if (e > max)
//        {
//            max = e;
//        }
//    }
//    cout << max;
//    return 0;
//}

//#include <vector>
//#include <string>
//#include <iostream>
//using namespace std;
//class Solution {
//public:
//    int getLongestPalindrome(string A)
//    {
//        int len = A.size();
//        if (len < 2)
//        {
//            return 1;
//        }
//        vector<vector<int>> tmp(len, vector<int>(len));
//        for (int i = 0; i < len; i++)
//        {
//            tmp[i][i] = 1;
//        }
//
//        //中心扩散，从最2回文进行判断
//        int maxlen = 1;
//        for (int x = 2; x <= len; x++)
//        {
//            for (int i = 0; i < len; i++)
//            {
//                int j = x + i - 1;
//                if (j >= len)
//                {
//                    break;
//                }
//
//                if (A[i] != A[j])
//                {
//                    tmp[i][j] = 0;
//                }
//                else
//                {
//                    if (j - i < 3)
//                    {
//                        tmp[i][j] = 1;
//                    }
//                    else
//                    {
//                        tmp[i][j] = tmp[i + 1][j - 1];
//                    }
//                }
//
//                if (tmp[i][j] == 1 && j - i + 1 > maxlen)
//                {
//                    maxlen = j - i + 1;
//                }
//            }
//        }
//        return maxlen;
//    }
//};

//用例不可以全部通过
//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//    int n, m, x, y;
//    cin >> n >> m >> x >> y;
//
//    //动态规划
//    vector<vector<int>> vis(n + 1, vector<int>(m + 1));
//    //先定位马可以控制的位置
//    vis[x][y] = -1;
//    for (int i = 0; i < n + 1; i++)
//    {
//        for (int j = 0; j < m + 1; j++)
//        {
//            if (abs(x - i) + abs(y - j) == 3 && i != x && j != y)
//            {
//                vis[i][j] = -1;
//            }
//        }
//    }
//
//    for (int i = 0; i < n+1; i++)
//    {
//        if (vis[i][0] != -1)
//        {
//            vis[i][0] = 1;
//        }
//    }
//    for (int j = 0; j < m+1; j++)
//    {
//        if (vis[0][j] != -1)
//        {
//            vis[0][j] = 1;
//        }
//    }
//
//    for (int i = 1; i < n + 1; i++)
//    {
//        for (int j = 1; j < m + 1; j++)
//        {
//            if (vis[i][j] != -1)
//            {
//                if (vis[i - 1][j] == -1 && vis[i][j - 1] == -1)
//                {
//                    vis[i][j] = 0;
//                }
//                else if (vis[i - 1][j] == -1 && vis[i][j - 1] != -1)
//                {
//                    vis[i][j] = vis[i][j - 1];
//                }
//                else if (vis[i - 1][j] != -1 && vis[i][j - 1] == -1)
//                {
//                    vis[i][j] = vis[i - 1][j];
//                }
//                else
//                {
//                    vis[i][j] = vis[i - 1][j] + vis[i][j - 1];
//                }
//            }
//        }
//    }
//    cout << vis[n][m];
//    return 0;
//}

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;

    x += 1, y += 1;
    vector<vector<long long>> dp(n + 2, vector<long long>(m + 2));
    dp[0][1] = 1;

    for (int i = 1; i < n + 2; i++)
    {
        for (int j = 1; j < m + 2; j++)
        {
            if ((x != i && y != j && abs(x - i) + abs(y - j) == 3) || (x == i && y == j))
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }

    cout << dp[n + 1][m + 1];
    return 0;
}