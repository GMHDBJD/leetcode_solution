/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

/*
there is a simple solution with O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int maxArea(vector<int> &height)
    {
        vector<pair<int, int>> left;
        vector<pair<int, int>> right;
        int temp = 0;
        int r = 0;
        for (int i = 0; i < height.size(); ++i)
        {
            if (height[i] <= temp)
                continue;
            left.push_back({i, height[i]});
            temp = height[i];
        }
        temp = 0;
        for (int i = height.size() - 1; i >= 0; --i)
        {
            if (height[i] <= temp)
                continue;
            right.push_back({i, height[i]});
            temp = height[i];
        }
        for (auto &&lhs : left)
        {
            for (auto &&rhs : right)
            {
                if (lhs.first >= rhs.first)
                {
                    return r;
                }
                if (r < (rhs.first - lhs.first) * min(lhs.second, rhs.second))
                    r = (rhs.first - lhs.first) * min(lhs.second, rhs.second);
                if (rhs.second >= lhs.second)
                    break;
            }
        }
        return r;
    }
};
