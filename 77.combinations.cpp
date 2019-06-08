/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

/*
dfs
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> v;
        rec(0, n, k, v, {});
        return v;
    }
    void rec(int t, int n, int k, vector<vector<int>> &v, vector<int> vv)
    {
        if (k == 0)
        {
            v.push_back(vv);
            return;
        }
        for (int i = t + 1; i <= n - k + 1; ++i)
        {
            vv.push_back(i);
            rec(i, n, k - 1, v, vv);
            vv.pop_back();
        }
    }
};
