/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

/*
two pointer
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        int cnt = 1;
        int t = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] == t)
                continue;
            else
            {
                t = nums[i];
                swap(nums[cnt], nums[i]);
                ++cnt;
            }
        }
        return cnt;
    }
};
