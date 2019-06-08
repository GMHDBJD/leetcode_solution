/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

/*
union
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        map<int, int> m;
        int ma = 0;
        for (auto &&i : nums)
        {
            if (m[i])
                continue;
            else
            {
                int l = m[i - 1];
                int r = m[i + 1];
                m[i] = m[i - l] = m[i + r] = l + r + 1;
                ma = max(l + r + 1, ma);
            }
        }
        return ma;
    }
};
