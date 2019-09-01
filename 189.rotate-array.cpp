/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */

/*
easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        k %= nums.size();
        k = nums.size() - k;
        vector<int> v;
        for (int i = k; i < nums.size(); ++i)
            v.push_back(nums[i]);
        for (int i = 0; i < k; ++i)
            v.push_back(nums[i]);
        nums.swap(v);
    }
};
