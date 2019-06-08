/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

/*
attention to 0
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = 1;
        int pos = -1;
        int m = 0;
        int r = 0;
        while (n)
        {
            --n;
            ++pos;
            if (pos + 1 == nums.size())
                return r;
            m = max(m, pos + nums[pos]);
            if (n == 0)
            {
                n = m - pos;
                ++r;
            }
        }
        return 0;
    }
};
