//#include <iostream>
//#include <vector>
//using namespace std;
//
//int n;
//
//int main()
//{
//    cin >> n;
//    int x = n;
//    vector<int> tmp(n + 1);
//    for (int i = 1; i <= n; i += 2)
//    {
//        tmp[i] = x--;
//    }
//    for (int i = 2; i <= n; i += 2)
//    {
//        tmp[i] = x--;
//    }
//    for (int i = 1; i <= n; i++)
//    {
//        cout << tmp[i];
//    }
//    return 0;
//}

//#include <stdio.h>
//#include <errno.h>
//#include <unistd.h>
//
//int main()
//{
//    execlp("ls", "ls", "-l", "-a", (char*)NULL);
//    perror("execlp failed");
//
//    return 1;
//}

//class Solution {
//    vector<string> tmp = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
//    vector<string> ret;
//    string str;
//public:
//    void dfs(int pos, string digits)
//    {
//        if (pos == digits.size())
//        {
//            ret.push_back(str);
//            return;
//        }
//        int num = digits[pos] - '0';
//        for (int i = 0; i < tmp[num].size(); i++)
//        {
//            str.push_back(tmp[num][i]);
//            dfs(pos + 1, digits);
//            str.pop_back();
//        }
//    }
//    vector<string> letterCombinations(string digits)
//    {
//        if (digits.empty())
//        {
//            return ret;
//        }
//        dfs(0, digits);
//        return ret;
//    }
//};

//#include"iterator.h"
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	bit::list<int> ls;
//	ls.push_back(1);
//	ls.push_back(2);
//	ls.push_back(3);
//	bit::list<int>::r_iterator rit = ls.rbegin();
//	while (rit != ls.rend())
//	{
//		cout << *rit << " ";
//		rit++;
//	}
//	cout << endl;
//
//	bit::vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	bit::vector<int>::r_iterator it = v.rbegin();
//	while (it != v.rend())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//string A;
//string B;
//
//int main()
//{
//    cin >> A;
//    cin >> B;
//    int n = A.size(), m = B.size();
//    int ret = n;
//
//    for (int i = 0; i <= m - n; i++)
//    {
//        int count = 0;;
//        for (int j = 0; j < n; j++)
//        {
//            if (A[j] != B[i + j])
//            {
//                count++;
//            }
//        }
//        ret = min(ret, count);
//    }
//    cout << ret;
//    return 0;
//}

//#include <iostream>
//using namespace std;
//
//int n;
//int arr[51];
//
//bool func(int m)
//{
//    for (int i = 0; i < n; i++)
//    {
//        if (m % arr[i] != 0)
//        {
//            return false;
//        }
//        else
//        {
//            int tmp = m / arr[i];
//            //判断tmp是不是2的次方
//            if (tmp & (tmp - 1))
//            {
//                return false;
//            }
//        }
//    }
//    return true;
//}
//
//int main()
//{
//    cin >> n;
//    int m = 0;
//    for (int i = 0; i < n; i++)
//    {
//        cin >> arr[i];
//        m = max(m, arr[i]);
//    }
//
//    if (func(m)) cout << "YES";
//    else cout << "NO";
//
//    return 0;
//}

#include <iostream>
using namespace std;

const int N = 2e4 + 10;
int V;
int n;
int dp[N];
int arr[31];

int main()
{
	cin >> V >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = V; j >= arr[i]; j--)
		{
			dp[j] = max(dp[j], dp[j - arr[i]] + arr[i]);
		}
	}
	cout << V - dp[V];
	return 0;
}
