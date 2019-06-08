/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

/*
easy
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int removeElement(vector<int> &nums, int val)
    {
        int pos = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == val)
                continue;
            else
                nums[pos++] = nums[i];
        }
        return pos;
    }
};
