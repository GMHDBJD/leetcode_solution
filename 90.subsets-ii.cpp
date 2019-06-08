/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

/*
same as problem78
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> vv;
        vector<int> v;
        sort(nums.begin(), nums.end());
        rec(0, nums, vv, v);
        return vv;
    }
    void rec(int t, vector<int> &nums, vector<vector<int>> &vv, vector<int> v)
    {
        if (t == nums.size())
            vv.push_back(v);
        else
        {
            int c = 1;
            int k = t;
            while (k + 1 < nums.size() && nums[k] == nums[k + 1])
            {
                ++c;
                ++k;
            }
            rec(t + c, nums, vv, v);
            for (int i = 0; i < c; ++i)
            {
                v.push_back(nums[t]);
                rec(t + c, nums, vv, v);
            }
        }
    }
};
