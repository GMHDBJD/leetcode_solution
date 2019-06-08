/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

/*
dp or sum
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.empty())
            return 0;
        for (int i = prices.size() - 1; i - 1 >= 0; --i)
            prices[i] -= prices[i - 1];
        vector<int> dp(prices.size() + 5, 0);
        for (int i = 1; i < prices.size(); ++i)
            dp[i] = max(dp[i - 1] + prices[i], prices[i]);
        return *max_element(dp.begin(), dp.begin() + prices.size());
    }
};
