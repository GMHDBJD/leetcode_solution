/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

/*
same as problem45
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = 1;
        int pos = -1;
        int r = 0;
        int m = 0;
        while (n)
        {
            --n;
            ++pos;
            m = max(nums[pos] + pos, m);
            if (pos + 1 == nums.size())
                return true;
            if (n == 0)
            {
                n = m - pos;
                ++r;
            }
        }
        return false;
    }
};
