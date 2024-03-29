/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */

/*
dp node left and right
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numTrees(int n)
    {
        vector<int> dp(n + 5, 0);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; ++i)
        {
            for (int j = 1; j <= i; ++j)
            {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};
