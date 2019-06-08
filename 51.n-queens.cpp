/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */

/*
dfs
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> r;
        vector<string> v;
        rec(n, v, r, n);
        return r;
    }
    void rec(int n, vector<string> &v, vector<vector<string>> &r, int t)
    {
        if (n == 0)
        {
            r.push_back(v);
        }
        else
        {
            for (int i = 0; i < t; ++i)
            {
                if (v.empty() || valid(v, i, t))
                {
                    v.push_back(string(t, '.'));
                    v.back()[i] = 'Q';
                    rec(n - 1, v, r, t);
                    v.pop_back();
                }
            }
        }
    }
    bool valid(const vector<string> &v, int pos, int n)
    {
        int k = v.size();
        for (int i = 0; i < k; ++i)
        {
            if (v[i][pos] == 'Q')
                return false;
            else if (pos - (k - i) >= 0 && v[i][pos - (k - i)] == 'Q')
                return false;
            else if (pos + (k - i) < n && v[i][pos + (k - i)] == 'Q')
                return false;
        }
        return true;
    }
};
