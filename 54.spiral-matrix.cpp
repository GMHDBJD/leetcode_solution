/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

/*
edge decrease
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> v;
        if (matrix.empty())
            return {};
        int l = 0;
        int r = matrix.front().size() - 1;
        int t = 0;
        int b = matrix.size() - 1;
        while (l <= r && t <= b)
        {
            for (int i = l; i <= r; ++i)
                v.push_back(matrix[t][i]);
            for (int i = t + 1; i <= b; ++i)
                v.push_back(matrix[i][r]);
            if (t < b)
            {
                for (int i = r-1; i >= l; --i)
                    v.push_back(matrix[b][i]);
            }
            if (l < r)
            {
                for (int i = b - 1; i > t; --i)
                    v.push_back(matrix[i][l]);
            }
            l++;
            r--;
            t++;
            b--;
        }
        return v;
    }
};
