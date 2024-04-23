#include <any>
#include <iostream>
#include <string>
using namespace std;

//int main()
//{
//    string str;
//    cin >> str;
//
//    string tmp1;
//    string ret;
//
//    for (int i = 0; i < str.size(); i++)
//    {
//        if (str[i] >= '0' && str[i] <= '9')
//        {
//            while (str[i] >= '0' && str[i] <= '9')
//            {
//                tmp1 += str[i++];
//            }
//            if (tmp1.size() > ret.size())
//            {
//                swap(tmp1, ret);
//            }
//        }
//        tmp1.clear();
//    }
//
//    cout << ret;
//    return 0;
//}

//#include <queue>
//class Solution
//{
//    int m, n;
//    int dx[4] = { 0,0,1,-1 };
//    int dy[4] = { 1,-1,0,0 };
//    bool vis[201][201] = { 0 };
//    queue<pair<int, int>> q;
//public:
//    int solve(vector<vector<char> >& grid)
//    {
//        m = grid.size();
//        n = grid[0].size();
//
//        int cout = 0;
//        for (int i = 0; i < m; i++)
//        {
//            for (int j = 0; j < n; j++)
//            {
//                //如果是1，而且没有被探索过，那么就进行广度探索
//                if (grid[i][j] == '1' && vis[i][j] == false)
//                {
//                    //广度优先遍历
//                    q.push({ i, j });
//                    BFS(grid);
//                    cout++;
//                }
//            }
//        }
//        return cout;
//    }
//
//    void BFS(vector<vector<char> >& grid)
//    {
//        while (!q.empty())
//        {
//            int a = q.front().first, b = q.front().second;
//            q.pop();
//            for (int i = 0; i < 4; i++)
//            {
//                int x = a + dx[i], y = b + dy[i];
//                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == '1' && vis[x][y] == false)
//                {
//                    vis[x][y] = true;
//                    q.push({ x,y });
//                }
//            }
//        }
//    }
//};
//
//int main()
//{
//    //[[], [], [], [], []] 
//    vector<vector<char>> grid{{ '1', '1', '0', '0', '0' }, {'0', '1', '0', '1', '1'}, {'0', '0', '0', '1', '1' }, { '0', '0', '0', '0', '0' }, { '0', '0', '1', '1', '1' }};
//    Solution s;
//    int ret = s.solve(grid);
//    cout << ret << endl;
//    return 0;
//}

# include <algorithm>
using namespace std;
int p[6];
int f = 0;
int fun(int a, int b, int c)
{
    if (a + b > c && a + c > b && b + c > a) return 1;
    return 0;
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        for (int i = 0; i < 6; i++)
        {
            cin >> p[i];
        }
        sort(p, p + 6);
        do {
            if (fun(p[0], p[1], p[2]) && fun(p[3], p[4], p[5]))
            {
                f = 1;
                break;
            }
        } while (next_permutation(p, p + 6));
        //全排列问题，可以使用这个函数
        if(f)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
        f = 0;
    }
    return 0;
}