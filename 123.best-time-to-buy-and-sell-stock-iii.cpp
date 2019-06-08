/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 */

/*
left and right
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
        vector<int> l(prices.size() + 5, 0), r(prices.size() + 5, 0);
        for (int i = prices.size() - 1; i >= 1; --i)
            prices[i] -= prices[i - 1];
        prices[0] = 0;
        for (int i = 1; i < prices.size(); ++i)
            l[i] = max(l[i - 1] + prices[i], prices[i]);
        for (int i = prices.size() - 1; i - 1 >= 0; --i)
            r[i - 1] = max(r[i] + prices[i], prices[i]);
        for (int i = 1; i < prices.size(); ++i)
            l[i] = max(l[i - 1], l[i]);
        for (int i = prices.size() - 1; i - 1 >= 0; --i)
            r[i - 1] = max(r[i], r[i - 1]);
        int result = 0;
        for (int i = 0; i <= prices.size(); ++i)
            result = max(result, l[i] + r[i + 1]);
        return result;
    }
};
