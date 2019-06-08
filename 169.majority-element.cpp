/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

/*
niubility
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int a = nums[0];
        int count = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (count == 0)
            {
                count = 1;
                a = nums[i];
            }
            else if (nums[i] == a)
                ++count;
            else
                --count;
        }
        return a;
    }
};
