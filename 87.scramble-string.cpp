/*
 * @lc app=leetcode id=87 lang=cpp
 *
 * [87] Scramble String
 */

/*
better us dp
check same char to improve performance when use recursive
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isScramble(string s1, string s2)
    {
        if (s1.size() != s2.size())
            return false;
        map<char, int> m;
        for (auto &&i : s1)
            m[i]++;
        for (auto &&i : s2)
        {
            m[i]--;
            if (m[i] < 0)
                return false;
        }
        if (s1.empty() || (s1.size() == 1 && s1 == s2))
            return s1 == s2;
        for (int i = 1; i < s1.size(); ++i)
        {
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))
                return true;
            if (isScramble(s1.substr(0, i), s2.substr(s1.size() - i)) && isScramble(s1.substr(i), s2.substr(0, s1.size() - i)))
                return true;
        }
        return false;
    }
};
