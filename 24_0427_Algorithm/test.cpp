//C语言写法
//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//    char arr1[101];
//    char arr2[101];
//    gets(arr1);
//    gets(arr2);
//
//    int i = 0;
//    while (arr1[i])
//    {
//        if (strchr(arr2, arr1[i]) == NULL)
//        {
//            printf("%c", arr1[i]);
//        }
//        i++;
//    }
//    return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//    string str1, str2;
//    getline(cin, str1);
//    getline(cin, str2);
//
//    for (int i = 0; i < str2.size(); i++)
//    {
//        auto it = str1.begin();
//        while (it != str1.end())
//        {
//            if (*it == str2[i])
//            {
//                //迭代器失效的问题
//                it = str1.erase(it);
//            }
//            if (it != str1.end())
//            {
//                it++;
//            }
//        }
//    }
//    cout << str1;
//    return 0;
//}


//struct ListNode {
//	int val;
//	struct ListNode *next;
//	ListNode(int x)
//		:val(x)
//		,next(nullptr)
//	{}
//};
//class Solution
//{
//public:
//	int Length(ListNode* p)
//	{
//		int count = 0;
//		while (p)
//		{
//			p = p->next;
//			count++;
//		}
//		return count;
//	}
//
//	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2)
//	{
//		if (pHead1 == nullptr || pHead2 == nullptr)
//		{
//			return nullptr;
//		}
//		int len1 = Length(pHead1);
//		int len2 = Length(pHead2);
//
//		int tmp = 0;
//		ListNode* p1 = pHead1, * p2 = pHead2;
//		if (len1 > len2)
//		{
//			tmp = len1 - len2;
//			while (tmp--)
//			{
//				p1 = p1->next;
//			}
//		}
//		else
//		{
//			tmp = len2 - len1;
//			while (tmp--)
//			{
//				p2 = p2->next;
//			}
//		}
//
//		while (p1 != p2 && p1 != nullptr && p2 != nullptr)
//		{
//			p1 = p1->next;
//			p2 = p2->next;
//		}
//		return p1;
//	}
//};


#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string str;
    cin >> str;

	int cnt_s = 0, cnt_h = 0, cnt_y = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == 's') cnt_s++;
		else if (str[i] == 'h') cnt_h += cnt_s;
		else if (str[i] == 'y') cnt_y += cnt_h;
	}
	//babgbag
	//可以理解为g的个数是由前面的b和a的个数
	//a的个数是由前面的b的个数决定的
	cout << cnt_y << '\n';
}