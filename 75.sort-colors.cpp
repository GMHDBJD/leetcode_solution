/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

/*
c=max(l,c)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1, c = 0;
        while (c <= r)
        {
            if (nums[c] == 0)
            {
                swap(nums[l++], nums[c]);
                c = max(c, l);
            }
            else if (nums[c] == 2)
                swap(nums[r--], nums[c]);
            else
                ++c;
        }
        return;
    }
};
