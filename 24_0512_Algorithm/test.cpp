//#include <iostream>
//#include <algorithm>
//#include <map>
//#include <vector>
//using namespace std;
//
//class Solution
//{
//    map<string, int> tmp;
//public:
//    vector<string> topKFrequent(vector<string>& words, int k)
//    {
//        for (auto& e : words)
//        {
//            tmp[e]++;
//        }
//
//        vector<string> ret;
//        for (auto& e : tmp)
//        {
//            ret.push_back(e.first);
//        }
//        std::stable_sort(ret.begin(), ret.end(), [&](const std::string& a, const std::string& b) {
//            return tmp[a] > tmp[b];
//            });
//
//        ret.erase(ret.begin() + k, ret.end());
//        return ret;
//    }
//};

//#include <iostream>
//#include <string>
//#include <map>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//string str;
//map<string, int> m;
//
//bool cmp(pair<string, int>& a, pair<string, int>& b)
//{
//	return a.second > b.second;
//}
//
//int main()
//{
//	getline(cin, str);
//	//把所有是字母的字符转换成小写
//	for (auto& e : str)
//	{
//		if (isalpha(e))
//		{
//			e = tolower(e);
//		}
//	}
//	string tmp;
//	for (int i = 0; i < str.size(); i++)
//	{
//		if (str[i] == ' ' || str[i] == '.')
//		{
//			m[tmp]++;
//			tmp.clear();
//			continue;
//		}
//		else
//		{
//			tmp += str[i];
//		}
//	}
//	//转存到vector
//	vector < pair<string, int> > v;
//	for (auto e : m)
//	{
//		v.push_back(e);
//	}
//	
//	sort(v.begin(), v.end(), cmp);
//
//	for (auto e : v)
//	{
//		cout << e.first << ":" << e.second << endl;
//	}
//	return 0;
//}

//day24
//#include <cmath>
//class Solution {
//public:
//    int treehigh(TreeNode* pRoot)
//    {
//        if (pRoot == nullptr)
//        {
//            return 0;
//        }
//        int lefthigh = treehigh(pRoot->left);
//        int righthigh = treehigh(pRoot->right);
//        return  lefthigh > righthigh ? lefthigh + 1 : righthigh + 1;
//    }
//    bool IsBalanced_Solution(TreeNode* pRoot)
//    {
//        if (pRoot == nullptr)
//        {
//            return true;
//        }
//        int ret1 = treehigh(pRoot->left);
//        int ret2 = treehigh(pRoot->right);
//
//        if (abs(ret1 - ret2) > 1)
//        {
//            return false;
//        }
//        return true;
//    }
//};
//解法二
//class Solution {
//public:
//    bool IsBalanced_Solution(TreeNode* pRoot)
//    {
//        return dfs(pRoot) != -1;
//    }
//    int dfs(TreeNode* root)
//    {
//        if (root == nullptr)
//        {
//            return 0;
//        }
//        int left = dfs(root->left);
//        if (left == -1)
//        {
//            return -1;
//        }
//        int right = dfs(root->right);
//        if (right == -1)
//        {
//            return -1;
//        }
//        return abs(left - right) <= 1 ? max(left, right) + 1 : -1;
//    }
//};

//矩阵的前缀和
//#include <iostream>
//#include <vector>
//using namespace std;
//
//const int N = 110;
//int n;
//vector<vector<int>> dp(N,vector<int>(N));
//
//int main()
//{
//	cin >> n;
//	int tmp = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			cin >> tmp;
//			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + tmp;
//		}
//	}
//
//	int ret = -127 * N;
//	for (int x1 = 1; x1 <= n; x1++)
//	{
//		for (int y1 = 1; y1 <= n; y1++)
//		{
//			for (int x2 = x1; x2 <= n; x2++)
//			{
//				for (int y2 = y1; y2 <= n; y2++)
//				{
//					ret = max(ret, dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1]);
//				}
//			}
//		}
//	}
//
//	return 0;
//}

#include <iostream>
#include <string>
#include <map>
using namespace std;

int n;
string str;
int arr[2];

int main()
{	
	cin >> n;
	cin >> str;

	for (auto e : str)
	{
		arr[e - '0']++;
	}
	
	int left = 0, right = 0, ret = 0, half = n / 2;
	int count[2] = { 0 };
	while (right < n-1)
	{
		count[str[right] - '0']++;
		while (right - left + 1 > half)
		{
			count[str[left++] - '0']--;
		}
		if (right - left + 1 == half)
		{
			if (count[0] * 2 == arr[0] && count[1] * 2 == arr[1])
			{
				ret += 2;
			}
		}
		right++;
	}
	cout << ret << endl;
	return 0;
}