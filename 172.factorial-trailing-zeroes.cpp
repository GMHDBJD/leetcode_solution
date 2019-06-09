/*
 * @lc app=leetcode id=172 lang=cpp
 *
 * [172] Factorial Trailing Zeroes
 */

/*
how many fives.
 */

class Solution
{
public:
    int trailingZeroes(int n)
    {
        return n ? n / 5 + trailingZeroes(n / 5) : 0;
    }
};
