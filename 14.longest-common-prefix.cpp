/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

/*
so easy
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
            return "";
        string r;
        int pos = 0;
        while (true)
        {
            bool f = true;
            char c;
            for (auto &&s : strs)
            {
                if (pos >= s.size())
                    return r;
                if (f)
                {
                    c = s[pos];
                    f = false;
                }
                else
                {
                    if (c != s[pos])
                        return r;
                }
            }
            r += c;
            ++pos;
        }
        return r;
    }
};
