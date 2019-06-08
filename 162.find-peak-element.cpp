/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */

/*
bisect
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        return rec(nums, 0, nums.size() - 1);
    }
    int rec(vector<int> &nums, int l, int r)
    {
        if (l != r)
        {
            int m = l + (r - l) / 2;
            if (nums[m] < nums[m + 1])
                return rec(nums, m + 1, r);
            else
                return rec(nums, l, m);
        }
        return l;
    }
};
