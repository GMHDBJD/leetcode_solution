/*
 * @lc app=leetcode id=164 lang=cpp
 *
 * [164] Maximum Gap
 */

/*
bucket sort
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumGap(vector<int> &nums)
    {
        vector<int> v = nums;
        sort(v.begin(), v.end());
        if (nums.size() <= 1)
            return 0;
        int ma = *max_element(nums.begin(), nums.end());
        int mi = *min_element(nums.begin(), nums.end());
        int gap = ceil(double(ma - mi) / (nums.size() - 1));
        if (gap == 0)
            return ma - mi;
        vector<int> mav(nums.size(), INT_MIN);
        vector<int> miv(nums.size(), INT_MAX);
        for (auto &&i : nums)
        {
            mav[(i - mi) / gap] = max(mav[(i - mi) / gap], i);
            miv[(i - mi) / gap] = min(miv[(i - mi) / gap], i);
        }
        int result = INT_MIN;
        int pre = mi;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (miv[i] == INT_MAX && mav[i] == INT_MIN)
                continue;
            result = max(miv[i] - pre, result);
            pre = mav[i];
        }
        return result;
    }
};
