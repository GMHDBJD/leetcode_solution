/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

/*
attention to precision
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        return Cmn(m - 1 + n - 1, n - 1);
    }

    int Cmn(int m, int n)
    {
        n = min(n, m - n);
        long t = 1;
        long r = 1;
        while (n)
        {
            r *= m;
            r /= t;
            --m;
            --n;
            ++t;
        }
        return r;
    }
};
