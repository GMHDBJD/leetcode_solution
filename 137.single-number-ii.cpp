/*
 * @lc app=leetcode id=137 lang=cpp
 *
 * [137] Single Number II
 */

/*
state
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int one = 0, two = 0;
        for (auto &&i : nums)
        {
            one = (one ^ i) & (~two);
            two = (two ^ i) & (~one);
        }
        return one;
    }
};
