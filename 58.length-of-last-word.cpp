/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

/*
easy
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        if (s.empty())
            return 0;
        int pos = s.size() - 1;
        while (pos >= 0 && s[pos] == ' ')
            --pos;
        int r = 0;
        while (pos >= 0 && s[pos] != ' ')
        {
            --pos;
            ++r;
        }
        return r;
    }
};
