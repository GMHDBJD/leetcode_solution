/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

/*
sort, two pointer, skip same
not use hashmap
*/


#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> v;
        sort(nums.begin(), nums.end());
        int i = 0;
        while (i + 2 < nums.size())
        {
            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum < 0)
                {
                    ++l;
                }
                else if (sum > 0)
                {
                    --r;
                }
                else
                {
                    v.push_back({nums[i], nums[l], nums[r]});
                    while (l < r && nums[l + 1] == nums[l])
                        ++l;
                    while (l < r && nums[r - 1] == nums[r])
                        --r;
                    ++l;
                    --r;
                }
            }
            while (i + 1 < nums.size() && nums[i + 1] == nums[i])
                ++i;
            ++i;
        }
        return v;
    }
};