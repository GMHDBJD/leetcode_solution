/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

/*
same as problem 15.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        vector<vector<int>> v;
        sort(nums.begin(), nums.end());
        int i = 0;
        int temp = INT_MAX;
        int res = 0;
        while (i + 2 < nums.size())
        {
            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                if (abs(sum - target) < temp)
                {
                    res = sum;
                    temp = abs(sum - target);
                }
                if (sum < target)
                {
                    ++l;
                }
                else if (sum > target)
                {
                    --r;
                }
                else
                    return res;
            }
            while (i + 1 < nums.size() && nums[i + 1] == nums[i])
                ++i;
            ++i;
        }
        return res;
    }
};
