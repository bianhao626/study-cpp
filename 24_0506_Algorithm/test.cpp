//day19
//#include <iostream>
//using namespace std;
//
//typedef long long LL;
//LL n, x;
//
//LL find(LL x, LL y)
//{
//    //默认传过来x > y
//    LL tmp = 0;
//    tmp = x % y;
//    while (tmp != 0)
//    {
//        x = y;
//        y = tmp;
//        tmp = x % y;
//    }
//    return y;
//}
//
//int main()
//{
//    cin >> n >> x;
//    for (int i = 0; i < n; i++)
//    {
//        LL tmp = 0;
//        cin >> tmp;
//        if (x >= tmp)
//        {
//            x += tmp;
//        }
//        else
//        {
//            x += find(tmp, x);
//        }
//    }
//    cout << x;
//    return 0;
//}

//#include <algorithm>
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution
//{
//public:
//    int maxValue(vector<vector<int> >& grid)
//    {
//        int n = grid.size(), m = grid[0].size();
//        int i = 0, j = 0;
//        //动态规划
//        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
//
//        for (int i = 1; i <= n; i++)
//        {
//            for (int j = 1; j <= m; j++)
//            {
//                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
//            }
//        }
//        return dp[n][m];
//    }
//};

//对称之美
//#include <functional>
//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int t, n;
//vector<int> hashnum(26);
//
//int main()
//{
//    cin >> t;
//    while (t--)
//    {
//        //t组测试用例
//        cin >> n;
//        vector<string> tmp(n);
//        for (int i = 0; i < n; i++)
//        {
//            cin >> tmp[i];
//        }
//        int left = 0, right = n - 1, flag = 0;
//        while (left <= right)
//        {   
//            flag = 0;
//            //记录左边位置的字符串
//            for (auto e : tmp[left])
//            {
//                hashnum[e - 'a'] = 1;
//            }
//            //判断右边对称位置是否也存在相同字符
//            for (auto g : tmp[right])
//            {
//                if (hashnum[g - 'a'] == 1)
//                {
//                    //如果存在，首先清除对应的
//                    fill(hashnum.begin(), hashnum.end(), 0);
//                    flag = 1;
//                    break;
//                }
//            }
//            if (flag == 0)
//            {
//                //说明不存在相同的字符
//                fill(hashnum.begin(), hashnum.end(), 0);
//                cout << "No" << endl;
//                break;
//            }
//            else
//            {
//                left++;
//                right--;
//            }
//        }
//        if (flag == 1)
//        {
//            cout << "Yes" << endl;
//        }
//    }
//    return 0;
//}

//day20
//时间复杂度过高
//#include <iostream>
//using namespace std;
//
//int a, b, h, k;
//
//int main()
//{
//    cin >> a >> h >> b >> k;
//    int ret = 0;
//    while (h != 0 || k != 0)
//    {
//        if (h != 0 && k != 0)
//        {
//            ret += a;
//            ret += b;
//            h -= b;
//            k -= a;
//            if (h <= 0)
//            {
//                h = 0;
//            }
//            if (k <= 0)
//            {
//                k = 0;
//            }
//        }
//        else if (h != 0 && k == 0)
//        {
//            ret += a * 10;
//            h = 0;
//        }
//        else if (h == 0 && k != 0)
//        {
//            ret += b * 10;
//            k = 0;
//        }
//    }
//    cout << ret;
//    return 0;
//}
//--------------------
//#include <iostream>
//using namespace std;
//
//typedef long long LL;
//LL a, b, h, k;
//
//int main()
//{
//    cin >> a >> h >> b >> k;
//    LL ret;
//    int tmp1 = 0, tmp2 = 0;
//    tmp1 = h / b;
//    if (h % b != 0)
//    {
//        tmp1++;
//    }
//    tmp2 = k / a;
//    if (k % a != 0)
//    {
//        tmp2++;
//    }
//    if (tmp2 > tmp1)
//    {
//        ret = tmp1 * (a + b) + b * 10;
//    }
//    else if (tmp2 < tmp1)
//    {
//        ret = tmp2 * (a + b) + a * 10;
//    }
//    else
//    {
//        ret = tmp1 * (a + b);
//    }
//    cout << ret;
//    return 0;
//}

//#include <algorithm>
//#include <iostream>
//#include <vector>
//using namespace std;
//
//const int N = 10e5 + 10;
//typedef long long LL;
//int n;
//vector<LL> tmp(N);
//vector<LL> dp(N);
//
//int main()
//{
//    cin >> n;
//    for (int i = 1; i <= n; i++)
//    {
//        cin >> tmp[i];
//        dp[i] = max(dp[i - 1] + tmp[i], tmp[i]);
//    }
//
//    LL ret = dp[1];
//    for (int i = 1; i <= n; i++)
//    {
//        ret = max(ret, dp[i]);
//    }
//    cout << ret;
//    return 0;
//}

#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    string str;
    cin >> str;

    for (int i = str.length() / 2 - (str.length() % 2); i >= 0; i--)
    {
        if (str[i] != str[str.length() - i - 1])
        {
            cout << str.length() << endl;
            return 0;
        }
    }
    for (int i = 1; i < str.length(); i++)
    {
        if (str[i] != str[i - 1])
        {
            cout << str.length() - 1 << endl;
            return 0;
        }
    }
    cout << "0" << endl;
    return 0;
}