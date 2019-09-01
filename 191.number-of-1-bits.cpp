/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */

/*
steal
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        bitset<32> b(n);
        int r = 0;
        for (int i = 0; i < 32; ++i)
            if (b[i])
                ++r;
        return r;
    }
};
