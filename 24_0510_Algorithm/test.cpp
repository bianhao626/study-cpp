//day23
//什么叫浮点数错误？？？？？？？？
//#include <iostream>
//using namespace std;
//
//int t;
//int h, a, H, A;
//
//int main()
//{
//    cin >> t;
//    while (t--)
//    {
//        cin >> h >> a >> H >> A;
//        if (a >= H)
//        {
//            cout << -1;
//        }
//        int n = H / a + (H % a != 0 ? 1 : 0);
//        int m = n - 1;
//        int x = m * A;
//
//        int y = h / x - (h % x == 0 ? 1 : 0);
//        cout << y;
//    }
//    return 0;
//}

//#include <iostream>
//using namespace std;
//
//int t;
//int h, a, H, A;
//
//int func()
//{
//    if (a >= H)
//    {
//        return -1;
//    }
//    int n = H / a + (H % a != 0 ? 1 : 0);
//    int m = n - 1;
//    int x = m * A;
//
//    int y = h / x - (h % x == 0 ? 1 : 0);
//    return y;
//}
//
//int main()
//{
//    cin >> t;
//    while (t--)
//    {
//        cin >> h >> a >> H >> A;
//        cout << func() << endl;
//    }
//    return 0;
//}

//城市群数量
//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Solution
//{
//public:
//    void dfs(vector<vector<int>>& m, int i, vector<int>& tmp)
//    {
//        tmp[i] = 1;
//        for (int j = 0; j < m.size(); j++)
//        {
//            if (m[i][j] == 1 && tmp[j] == 0)
//            {
//                dfs(m, j, tmp);
//            }
//        }
//    }
//
//    int citys(vector<vector<int> >& m)
//    {
//        int n = m.size();
//        int num = 0;
//
//        vector<int> tmp(n);
//        for (int i = 0; i < n; i++)
//        {
//            //当前的城市开始进行深度优先
//            if (tmp[i] == 0)
//            {
//                dfs(m, i, tmp);
//                num++;
//            }
//        }
//        return num;
//    }
//};
//
//int main()
//{
//    vector<vector<int>> m = { {1,1,0},{1,1,0},{0,0,1} };
//    Solution s;
//    cout << s.citys(m);
//    return 0;
//}

//字符串的分类
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int n;
map<string, int> m;

int main()
{
	cin >> n;
	string tmp;
	while (n--)
	{
		cin >> tmp;
		sort(tmp.begin(), tmp.end());
		m[tmp]++;
	}
	cout << m.size();
	return 0;
}