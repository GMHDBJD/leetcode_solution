/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

/*
same as bisect
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int search(vector<int> &nums, int target)
    {
        if (nums.empty())
            return -1;
        int f = nums[0];
        int l = 0;
        int h = nums.size();
        while (h > l)
        {
            int m = l + (h - l) / 2;
            if (nums[m] == target)
                return m;
            else if (nums[m] > target)
            {
                if (target < f && nums[m] >= f)
                    l = m + 1;
                else
                    h = m;
            }
            else
            {
                if (nums[m] < f && f <= target)
                    h = m;
                else
                    l = m + 1;
            }
        }
        return -1;
    }
};
