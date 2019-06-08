/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

/*
better use Newton
*/

class Solution
{
public:
    int mySqrt(int x)
    {
        return rec(x, 0, long(x) + 1);
    }
    int rec(long x, long l, long h)
    {
        if (l + 1 == h)
            return l;
        long m = l + (h - l) / 2;
        if (m * m == x)
            return m;
        else if (m * m > x)
            return rec(x, l, m);
        else
            return rec(x, m, h);
    }
};
