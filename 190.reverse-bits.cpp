/*
 * @lc app=leetcode id=190 lang=cpp
 *
 * [190] Reverse Bits
 */

/*
easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        bitset<32> b(n);
        int l = 0, r = 31;
        while (l < r)
        {
            bool i = b[l];
            b[l] = b[r];
            b[r] = i;
            ++l;
            --r;
        }
        return b.to_ulong();
    }
};
