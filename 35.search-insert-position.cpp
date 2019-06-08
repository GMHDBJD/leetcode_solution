/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

/*
simple
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int searchInsert(vector<int> &nums, int target)
    {
        int pos = 0;
        while (pos < nums.size())
        {
            if (target <= nums[pos])
                return pos;
            else
                ++pos;
        }
        return pos;
    }
};
