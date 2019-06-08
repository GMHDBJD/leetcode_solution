/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

/*
xor
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int result = 0;
        for (auto i : nums)
        {
            result ^= i;
        }
        return result;
    }
};
