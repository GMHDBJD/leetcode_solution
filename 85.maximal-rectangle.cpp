/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 */

/*
actually is same as problem 84
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        if (matrix.empty())
            return 0;
        int n = matrix.size();
        int m = matrix.front().size();
        vector<int> heights(m + 5, 0);
        int r = 0;
        for (int i = 0; i < n; ++i)
        {
            stack<int> s;
            for (int j = 0; j < m; ++j)
            {
                if (matrix[i][j] == '1')
                    ++heights[j];
                else
                    heights[j] = 0;
            }
            int j = 0;
            while (j <= m)
            {
                if (s.empty() || heights[s.top()] <= heights[j])
                    s.push(j++);
                else
                {
                    int h = heights[s.top()];
                    s.pop();
                    int sq = h * (s.empty() ? j : j - s.top() - 1);
                    r = max(r, sq);
                }
            }
        }
        return r;
    }
};
