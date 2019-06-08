/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

/*
easy
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
        int result = 0;
        for_each(prices.begin() + 1, prices.end(), [&result](const int &val) { result += val > 0 ? val : 0; });
        return result;
    }
};
