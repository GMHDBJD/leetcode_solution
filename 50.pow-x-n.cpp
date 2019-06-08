/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

/*
new bee
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double myPow(double x, int n)
    {
        if (n == INT_MIN)
            return myPow(x * x, n / 2);
        if (n == 0)
            return 1;
        if (n < 0)
        {
            n = -n;
            x = 1 / x;
        }
        if (n % 2 == 0)
            return myPow(x * x, n / 2);
        else
            return x * myPow(x * x, n / 2);
    }
};
