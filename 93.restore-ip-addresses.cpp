/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 */

/*
sample backtracking
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> r;
        string str;
        rec(s, 0, r, str, 0);
        return r;
    }
    void rec(string &s, int k, vector<string> &r, string str, int pos)
    {
        if (k == 4)
        {
            if (pos == s.size())
                r.push_back(str);
            return;
        }
        if (k != 0)
            str += ".";
        for (int i = 1; i <= 3 && pos + i <= s.size(); ++i)
        {
            if (atoi(s.substr(pos, i).c_str()) <= 255 && !(i > 1 && s[pos] == '0'))
                rec(s, k + 1, r, str + s.substr(pos, i), pos + i);
        }
    }
};
