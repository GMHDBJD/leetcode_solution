/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

/*
same as problem53
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        vector<pair<int, int>> dp(nums.size() + 5, {0, 0});
        dp[0] = {1, 1};
        for (int i = 1; i <= nums.size(); ++i)
        {
            int a = dp[i - 1].first * nums[i - 1];
            int b = dp[i - 1].second * nums[i - 1];
            dp[i].first = max({a, b, nums[i - 1]});
            dp[i].second = min({a, b, nums[i - 1]});
        }
        int r = max(dp[1].first, dp[1].second);
        for (int i = 2; i <= nums.size(); ++i)
        {
            r = max({r, dp[i].first, dp[i].second});
        }
        return r;
    }
};
