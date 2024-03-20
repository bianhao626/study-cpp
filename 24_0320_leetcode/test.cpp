#include<iostream>
using namespace std;
#include<map>
#include<vector>

class Solution 
{
public:
    int singleNumber_int(vector<int>& nums)
    {
        map<int, int> hash_int;
        int result = 0;
        for (auto e : nums)
        {
            hash_int[e] += 1;
        }
        for (auto e : nums)
        {
            if (hash_int[e] == 1)
            {
                result = e;
            }
        }
        return result;
    }
    vector<int> singleNumber_vec(vector<int>& nums)
    {
        vector<int> result;
        map<int, int> hash_int;
        for (auto e : nums)
        {
            hash_int[e] += 1;
        }
        for (auto e : nums)
        {
            if (hash_int[e] == 1)
            {
                result.push_back(e);
            }
        }
        return result;
    }
};


int main()
{
    vector<int> nums1;
    nums1.push_back(1);
    nums1.push_back(0);
    nums1.push_back(1);
    nums1.push_back(0);
    nums1.push_back(1);
    nums1.push_back(0);
    nums1.push_back(9);
    vector<int> nums2;
    nums2.push_back(1);
    nums2.push_back(0);
    nums2.push_back(1);
    nums2.push_back(0);
    nums2.push_back(6);
    nums2.push_back(2);

    
    Solution s1;
    cout << s1.singleNumber_int(nums1) << endl;
    vector<int> ret;
    ret = s1.singleNumber_vec(nums2);
    for (size_t i = 0; i < ret.size(); i++)
    {
        cout << ret[i] << " ";
    }
    cout << endl;
    
    return 0;
}