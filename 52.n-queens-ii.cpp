/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 */

/*
same as problem51 use vector<bool>
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int totalNQueens(int n)
    {
        vector<bool> col(2 * n, false);
        vector<bool> left(2 * n, false);
        vector<bool> right(2 * n, false);
        int r = 0;
        rec(n, col, left, right, 0, r);
        return r;
    }
    void rec(int n, vector<bool> &col, vector<bool> &left, vector<bool> &right, int k, int &r)
    {
        if (k == n)
        {
            ++r;
            return;
        }
        for (int i = 0; i < n; ++i)
        {
            if (!col[i] && !left[i + k] && !right[k + n - i])
            {
                col[i] = true;
                left[i + k] = true;
                right[k + n - i] = true;
                rec(n, col, left, right, k + 1, r);
                col[i] = false;
                left[i + k] = false;
                right[k + n - i] = false;
            }
        }
    }
};
