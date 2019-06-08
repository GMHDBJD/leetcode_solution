/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */

/*
in place
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int firstMissingPositive(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            while (nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);
        }
        int i = 0;
        for (i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != i + 1)
                return i + 1;
        }
        return i + 1;
    }
};
