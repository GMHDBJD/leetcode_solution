/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

/*
stack: left first min and right first min
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int pos = 0;
        heights.push_back(0);
        stack<int> s;
        int result = 0;
        while (pos < heights.size())
        {
            if (s.empty() || heights[s.top()] <= heights[pos])
                s.push(pos++);
            else
            {
                int p = s.top();
                s.pop();
                int sq = heights[p] * (s.empty() ? pos : pos - s.top() - 1);
                result = max(result, sq);
            }
        }
        return result;
    }
};
