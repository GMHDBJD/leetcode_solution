/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

/*
amazing
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        reverse(matrix.begin(), matrix.end());
        for (int i = 0; i < matrix.size(); ++i)
            for (int j = i + 1; j < matrix.size(); ++j)
                swap(matrix[i][j], matrix[j][i]);
    }
};
