/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

/*
two pointer
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.empty())
            return false;
        int lx = 0;
        int ly = matrix.size() - 1;
        int rx = matrix.front().size() - 1;
        int ry = 0;
        while (lx <= rx && ly >= ry)
        {
            if (matrix[ly][lx] == target)
                return true;
            else if (matrix[ly][lx] < target)
                ++lx;
            else
                --ly;
            if (matrix[ry][rx] == target)
                return true;
            else if (matrix[ry][rx] < target)
                ++ry;
            else
                --rx;
        }
        return false;
    }
};
