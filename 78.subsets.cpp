/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

/*
dfs same as problem 78
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> r;
        for (int i = 0; i <= nums.size(); ++i)
            dfs(0, i, nums.size(), r, {}, nums);
        return r;
    }
    void dfs(int t, int k, int n, vector<vector<int>> &v, vector<int> vv, vector<int> &nums)
    {
        if (k == 0)
        {
            v.push_back(vv);
            return;
        }
        for (int i = t; i + k <= n; ++i)
        {
            vv.push_back(nums[i]);
            dfs(i + 1, k - 1, n, v, vv, nums);
            vv.pop_back();
        }
    }
};
