/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

/*
same as problem63
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid.front().size();
        vector<int> v(m + 5, 0);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (i == 0 && j == 0)
                    v[j] = grid[i][j];
                else if (i == 0)
                    v[j] = grid[i][j] + v[j - 1];
                else if (j == 0)
                    v[j] += grid[i][j];
                else
                    v[j] = grid[i][j] + min(v[j - 1], v[j]);
            }
        }
        return v[m - 1];
    }
};
