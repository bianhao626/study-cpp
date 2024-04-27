//day11
//#include <algorithm>
//#include <iostream>
//using namespace std;
//
//int main()
//{
//    typedef long long LL;
//    LL n, m, a, b;
//    cin >> n >> m >> a >> b;
//
//    LL ret = 0;
//    for (LL i = 0; i * 2 <= n && i <= m; i++)
//    {
//        LL x = n - 2 * i;
//        LL y = m - i;
//        LL j = min(y / 2, x);
//        LL sum = i * a + j * b;
//        ret = max(ret, sum);
//    }
//    cout << ret;
//    return 0;
//}

//Ì°ÐÄ²ßÂÔ
//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//    int n;
//    cin >> n;
//    int prices[n];
//    for (int i = 0; i < n; i++)
//    {
//        cin >> prices[i];
//    }
//
//    vector<int> tmp(n);
//    tmp[0] = 0;
//    for (int i = 1; i < n; i++)
//    {
//        if (prices[i] - prices[i - 1] > 0)
//        {
//            tmp[i] = tmp[i - 1] + prices[i] - prices[i - 1];
//        }
//        else
//        {
//            tmp[i] = tmp[i - 1];
//        }
//    }
//    cout << tmp[n - 1];
//
//    return 0;
//}

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string str;
    getline(cin, str);

    vector<string> tmp1;
    string tmp2;
    auto it = str.begin();

    while (it != str.end())
    {
        if (*it != ' ')
        {
            tmp2 += *it;
        }
        else
        {
            tmp1.push_back(tmp2);
            tmp2.clear();
        }
        it++;
    }
    tmp1.push_back(tmp2);

    reverse(tmp1.begin(), tmp1.end());
    auto j = tmp1.begin();
    while (j != tmp1.end())
    {
        cout << *j;
        if (j != tmp1.end() - 1)
        {
            cout << " ";
        }
        j++;
    }
    return 0;
}