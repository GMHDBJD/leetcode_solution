/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

/*
easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if(nums.empty())
            return 0;
        vector<vector<int>> dp(nums.size() + 5, vector<int>(2, 0));
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i == 0)
                dp[i][0] = nums[i];
            else
            {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + nums[i]);
                dp[i][1] = max(dp[i-1][0],dp[i-1][1]);
            }
        }
        return max(dp[nums.size()-1][0],dp[nums.size()-1][1]);
    }
};
