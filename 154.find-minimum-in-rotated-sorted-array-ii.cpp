/*
 * @lc app=leetcode id=154 lang=cpp
 *
 * [154] Find Minimum in Rotated Sorted Array II
 */

/*
same as problem153
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int l = 0;
        int h = nums.size() - 1;
        while (l < h)
        {
            int m = l + (h - l) / 2;
            if (nums[m] == nums[h])
                --h;
            else if (nums[m] < nums[h])
                h = m;
            else
                l = m + 1;
        }
        return nums[l];
    }
};
