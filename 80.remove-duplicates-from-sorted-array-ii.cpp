/*
 * @lc app=leetcode id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 */

/*
two pointer
better compare to nums[i-2]
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
        int l = 1;
        int r = 1;
        int t = nums[0];
        bool second = false;
        while (r != nums.size())
        {
            if (nums[r] != t)
            {
                t = nums[r];
                swap(nums[r], nums[l]);
                ++l;
                second = false;
            }
            else if (nums[r] == t && !second)
            {
                swap(nums[r], nums[l]);
                ++l;
                second = true;
            }
            ++r;
        }
        return l;
    }
};
