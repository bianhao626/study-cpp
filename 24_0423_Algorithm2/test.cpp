//#include <iostream>
//using namespace std;

//int main()
//{
//    int a, b;
//    cin >> a >> b;
//    int ret = b;
//
//    while (ret % a != 0)
//    {
//        ret += b;
//    }
//
//    cout << ret;
//    return 0;
//}
//#include <algorithm>
//#include <vector>
//class Solution {
//public:
//    //int MLS(vector<int>& arr)
//    //{
//    //    sort(arr.begin(), arr.end());
//    //    int num = arr.size();
//    //    vector<int> tmp;
//
//    //    int maxlen = 1;
//    //    tmp.push_back(arr[0]);
//    //    for (int i = 1; i < num; i++)
//    //    {
//    //        if (arr[i] == arr[i - 1] + 1)
//    //        {
//    //            while (arr[i] == arr[i - 1] + 1)
//    //            {
//    //                tmp.push_back(arr[i++]);
//    //            }
//    //            if (tmp.size() > maxlen)
//    //            {
//    //                maxlen = tmp.size();
//    //            }
//    //        }
//    //        tmp.clear();
//    //    }
//    //    return maxlen;
//    //}
//    int MLS(vector<int>& arr)
//    {
//        if (arr.empty())
//        {
//            return 0;
//        }
//        sort(arr.begin(), arr.end());
//
//        int len = 1;
//        int maxlen = 1;
//        for (int i = 1; i < arr.size(); i++)
//        {
//            if (arr[i] == arr[i - 1])
//            {
//                continue;
//            }
//            if (arr[i] == arr[i - 1] + 1)
//            {
//                len++;
//            }
//            else
//            {
//                len = 1;
//            }
//            maxlen = max(len, maxlen);
//        }
//        return maxlen;
//    }
//};
//int main()
//{
//    //[100,4,200,1,3,2]
//    vector<int> arr = { 100,4,200,1,3,2 };
//    Solution s;
//    cout << s.MLS(arr);
//    return 0;
//}


//day09
//#include <algorithm>
//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//    int N;
//    cin >> N;
//    string str;
//
//    int count = 0;
//    while (N)
//    {
//        char ch = N % 10 + '0';
//        count++;
//        str.push_back(ch);
//        if (count % 3 == 0)
//        {
//            str.push_back(',');
//        }
//        N /= 10;
//    }
//
//    if (str.back() == ',')
//    {
//        str.pop_back();
//    }
//    reverse(str.begin(), str.end());
//
//    cout << str;
//    return 0;
//}

//#include <iostream>
//using namespace std;
//
//int Func(int n)
//{
//    if (n == 1)
//    {
//        return 1;
//    }
//    else if (n == 2)
//    {
//        return 2;
//    }
//    return Func(n - 1) + Func(n - 2);
//}
//int main()
//{
//    int n;
//    cin >> n;
//
//    cout << Func(n);
//    return 0;
//}

#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool IsContinuous(vector<int>& numbers)
    {
        sort(numbers.begin(), numbers.end());
        int count = 0;
        for (auto e : numbers)
        {
            if (e == 0)
            {
                count++;
            }
        }

        if (count == 0)
        {
            for (int i = 1; i < numbers.size(); i++)
            {
                if (numbers[i] != numbers[i - 1] + 1)
                {
                    return false;
                }
            }
        }
        else if (count == 4)
        {
            return true;
        }
        else
        {
            int len = numbers.size() - 1 - count;
            int num = numbers[numbers.size() - 1] - numbers[count];
            if (len + count != num && num != len)
            {
                return false;
            }
        }
        return true;
    }
};

class Solution1 
{
public:
    bool IsContinuous(vector<int> numbers)
    {
        sort(numbers.begin(), numbers.end());
        int zero_num = 0;//统计大小王数量
        int i = 0;
        while (numbers[i] == 0)
        {
            zero_num++;
            i++;
        }
        int interrapt = 0;//记录五张牌中最大值max到最小值min的距离
        for (; i < numbers.size() - 1; ++i)
        {
            if (numbers[i] == numbers[i + 1])
            {
                return false;//出现相同的扑克牌
            }
            interrapt += numbers[i + 1] - numbers[i] - 1;//计算距离
        }
        if (zero_num >= interrapt)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    vector<int> number = { 1,5,5,0,0 };
    Solution s;
    s.IsContinuous(number);
    return 0;
}