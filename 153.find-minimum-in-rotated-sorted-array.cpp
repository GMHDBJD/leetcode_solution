/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

/*
compare to high
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
            if (nums[m] < nums[h])
                h = m;
            else
                l = m + 1;
        }
        return nums[l];
    }
};
