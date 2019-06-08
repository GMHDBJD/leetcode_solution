/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */

/*
<<
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int divide(int dividend, int divisor)
    {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        bool sign = !(dividend > 0 ^ divisor > 0);
        long de = labs(dividend);
        long ds = labs(divisor);
        long r = 0;
        while (de >= ds)
        {
            long temp = ds;
            long m = 1;
            while (temp << 1 <= de)
            {
                temp <<= 1;
                m <<= 1;
            }
            de -= temp;
            r += m;
        }
        return sign ? r : 0 - r;
    }
};
