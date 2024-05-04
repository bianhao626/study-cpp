//day13
//#include <iostream>
//#include <ostream>
//using namespace std;
//
//int main()
//{
//    int T;
//    cin >> T;
//
//    int n = 0, k = 0;
//    string str;
//    while (T--)
//    {
//        int count = 0, lenwin = 0;
//        cin >> n >> k;
//        cin >> str;
//        for (auto e : str)
//        {
//            if (e == 'W')
//            {
//                if (lenwin >= 2)
//                {
//                    count += k;
//                }
//                else
//                {
//                    count += 1;
//                    lenwin++;
//                }
//            }
//            else if (e == 'L')
//            {
//                count -= 1;
//                lenwin = 0;
//            }
//        }
//        cout << count << endl;
//        str.clear();
//    }
//    return 0;
//}

//最长无重复子数组的问题--滑动窗口
//class Solution
//{
//    int hash[100010] = { 0 };
//public:
//    int maxLength(vector<int>& arr)
//    {
//        int left = 0, right = 0;
//        int ret = 0;
//        while (right < arr.size())
//        {
//            //进窗口
//            hash[arr[right]]++;
//            //判断
//            while (hash[arr[right]] > 1)
//            {
//                //出窗口
//                hash[arr[left]]--;
//                left++;
//            }
//            //更新最长的长度
//            ret = max(ret, right - left + 1);
//            right++;
//        }
//        return ret;
//    }
//};

//#include<iostream>
//#include<string>
//using namespace std;
//class Solution {
//public:
//    string reorganizeString(string s)
//    {
//        int hash[26] = { 0 };
//        char maxchar = 0;
//        int maxcount = 0;
//        for (auto e : s)
//        {
//            hash[e - 'a']++;
//            if (hash[e - 'a'] > maxcount)
//            {
//                maxcount = hash[e - 'a'];
//                maxchar = e;
//            }
//        }
//
//        int n = s.size();
//        string ret(n, ' ');
//        if (maxcount > (n + 1) / 2)
//        {
//            return "";
//        }
//        else
//        {
//            int i = 0;
//            //先填多的
//            while (maxcount--)
//            {
//                ret[i] = maxchar;
//                i += 2;
//            }
//            //处理剩下的部分
//            for (int j = 0; j < 26; j++)
//            {
//                if (hash[j] && j + 'a' != maxchar)
//                {
//                    while (hash[j]--)
//                    {
//                        if (i >= n) i = 1;
//                        ret[i] = j + 'a';
//                        i += 2;
//                    }
//                }
//            }
//        }
//        return ret;
//    }
//};
//int main()
//{
//    Solution s;
//    cout << s.reorganizeString("vvvlo");
//
//    return 0;
//}

//day14
//#include <iostream>
//#include <map>
//#include <string>
//using namespace std;
//
//int main()
//{
//    string str1;
//    string str2;
//    cin >> str1 >> str2;
//
//    int hash[26] = { 0 };
//    for (auto i : str1)
//    {
//        hash[i - 'A']++;
//    }
//
//    //对比
//    int flag = 0;
//    for (auto j : str2)
//    {
//        if (hash[j - 'A'] == 0)
//        {
//            cout << "No";
//            flag = 1;
//            break;
//        }
//        else
//        {
//            hash[j - 'A']--;
//        }
//    }
//    if (flag == 0)
//    {
//        cout << "Yes";
//    }
//    return 0;
//}

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//    int n;
//    cin >> n;
//    vector<int> tmp(3 * n);
//    for (int i = 0; i < 3 * n; i++)
//    {
//        cin >> tmp[i];
//    }
//
//    sort(tmp.begin(), tmp.end());
//    vector<int>::iterator it = tmp.end() - 2;
//    long long count = 0;
//    while (n--)
//    {
//        count += *it;
//        it -= 2;
//    }
//    cout << count;
//    return 0;
//}

//动态规划
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int hash[10010] = { 0 };

    int x;
    int f[10010];
    int g[10010];
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        hash[x] += x;
    }

    f[0] = g[0] = 0;
    for (int i = 1; i < 10010; i++)
    {
        f[i] = hash[i] + g[i - 1];
        g[i] = max(f[i - 1], g[i - 1]);
    }
    cout << max(f[10009], g[10009]);
    return 0;
}