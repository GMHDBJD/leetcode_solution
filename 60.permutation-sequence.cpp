/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 */

/*
per
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string getPermutation(int n, int k)
    {
        string s;
        char c = '1';
        for (int i = 0; i < n; ++i)
            s += c + i;
        for (int i = 1; i < k; ++i)
            nextPermutation(s);
        return s;
    }
    void nextPermutation(string &s)
    {
        if (s.size() < 2)
            return;
        int pos = s.size() - 2;
        while (pos >= 0 && s[pos] > s[pos + 1])
            --pos;
        if (pos < 0)
            return;
        int k = s.size() - 1;
        while (s[k] < s[pos])
            --k;
        swap(s[k], s[pos]);
        reverse(s.begin() + pos + 1, s.end());
    }
};
