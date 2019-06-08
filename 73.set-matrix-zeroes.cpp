/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */

/*
in place flag
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        if (matrix.empty())
            return;
        int m = matrix.size();
        int n = matrix.front().size();
        int r = 1;
        int c = 1;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
            {
                if (!matrix[i][j])
                {
                    if (i == 0)
                        r = 0;
                    if (j == 0)
                        c = 0;
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        for (int i = 1; i < m; ++i)
        {
            if (!matrix[i][0])
                for (int j = 0; j < n; ++j)
                    matrix[i][j] = 0;
        }
        for (int i = 1; i < n; ++i)
        {
            if (!matrix[0][i])
                for (int j = 0; j < m; ++j)
                    matrix[j][i] = 0;
        }
        if (!r)
            for (int i = 0; i < n; ++i)
                matrix[0][i] = 0;
        if (!c)
            for (int i = 0; i < m; ++i)
                matrix[i][0] = 0;
    }
};
