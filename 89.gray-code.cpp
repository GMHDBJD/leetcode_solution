/*
 * @lc app=leetcode id=89 lang=cpp
 *
 * [89] Gray Code
 */

/*
bitset
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> grayCode(int n)
    {
        vector<int> v;
        bitset<32> bits;
        rec(n - 1, bits, v);
        return v;
    }
    void rec(int k, bitset<32> &bits, vector<int> &v)
    {
        if (k < 0)
            v.push_back(bits.to_ulong());
        else
        {
            rec(k - 1, bits, v);
            bits.flip(k);
            rec(k - 1, bits, v);
        }
    }
};
