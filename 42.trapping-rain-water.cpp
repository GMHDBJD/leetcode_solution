/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

/*
easy
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int trap(vector<int> &height)
    {
        vector<int> left;
        int m = 0;
        for (auto &&i : height)
        {
            left.push_back(m);
            m = max(m, i);
        }
        m = 0;
        int r = 0;
        for (int i = height.size() - 1; i >= 0; --i)
        {
            int mi = min(m, left[i]);
            if (height[i] < mi)
                r += mi - height[i];
            m = max(m, height[i]);
        }
        return r;
    }
};
