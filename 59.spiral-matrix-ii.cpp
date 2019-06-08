/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */

/*
same as problem54
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> v{n, vector<int>(n, 0)};
        int num = 1;
        int l = 0, t = 0, d = n - 1, r = n - 1;
        while (l <= r && t <= d)
        {
            for (int i = l; i <= r; ++i)
                v[t][i] = num++;
            for (int i = t + 1; i <= d; ++i)
                v[i][r] = num++;
            if (t < d)
            {
                for (int i = r - 1; i >= l; --i)
                    v[d][i] = num++;
            }
            if (l < r)
            {
                for (int i = d - 1; i > t; --i)
                    v[i][l] = num++;
            }
            ++l;
            --r;
            ++t;
            --d;
        }
        return v;
    }
};
