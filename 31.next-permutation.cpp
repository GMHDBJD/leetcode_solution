/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

/*
awsome algorithm
replace one than reverse
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    void nextPermutation(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return ;
        int pos = nums.size() - 2;
        while (pos >= 0 && nums[pos] >= nums[pos + 1])
            --pos;
        if (pos >= 0)
        {
            int k = nums.size() - 1;
            while (nums[pos] >= nums[k])
                --k;
            swap(nums[pos], nums[k]);
        }
        reverse(nums.begin() + pos + 1, nums.end());
    }
};
