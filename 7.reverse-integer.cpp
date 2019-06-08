/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

/*
    be careful for overflow
*/
class Solution
{
  public:
    int reverse(int x)
    {
        long r = 0;
        while (x)
        {
            r *= 10;
            r += x % 10;
            x /= 10;
            if (r > __INT_MAX__ || r < -__INT_MAX__)
                return 0;
        }
        return r;
    }
};
