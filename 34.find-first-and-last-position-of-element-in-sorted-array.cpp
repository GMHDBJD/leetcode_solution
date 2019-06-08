/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

/*
two pass bisect
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int l = 0;
        int h = nums.size();
        int left = -1;
        while (h > l)
        {
            int m = l + (h - l) / 2;
            if (nums[m] == target)
                left = m;
            if (nums[m] < target)
                l = m + 1;
            else
                h = m;
        }
        l = 0;
        h = nums.size();
        int right = -1;
        while (h > l)
        {
            int m = l + (h - l) / 2;
            if (nums[m] == target)
                right = m;
            if (nums[m] > target)
                h = m;
            else
                l = m + 1;
        }
        return {left, right};
    }
};
