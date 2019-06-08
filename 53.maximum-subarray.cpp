/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

/*
O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int sum = 0, r = nums[0];
        for (auto &i : nums)
        {
            sum += i;
            r = max(sum, r);
            if (sum < 0)
                sum = 0;
        }
        return r;
    }
};
