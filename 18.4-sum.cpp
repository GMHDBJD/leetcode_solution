/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

/*
taolu
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> v;
        sort(nums.begin(), nums.end());
        int i = 0;
        while (i + 3 < nums.size())
        {
            int x = i + 1;
            while (x + 2 < nums.size())
            {
                int l = x + 1;
                int r = nums.size() - 1;
                while (l < r)
                {
                    int sum = nums[i] + nums[x] + nums[l] + nums[r];
                    if (sum < target)
                    {
                        ++l;
                    }
                    else if (sum > target)
                    {
                        --r;
                    }
                    else
                    {
                        v.push_back({nums[i], nums[x], nums[l], nums[r]});
                        while (l < r && nums[l + 1] == nums[l])
                            ++l;
                        while (l < r && nums[r - 1] == nums[r])
                            --r;
                        ++l;
                        --r;
                    }
                }
                while (x + 1 < nums.size() && nums[x + 1] == nums[x])
                    ++x;
                ++x;
            }
            while (i + 1 < nums.size() && nums[i + 1] == nums[i])
                ++i;
            ++i;
        }
        return v;
    }
};
