/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

/*
backtracking
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        vector<string> v;
        vector<vector<string>> r;
        rec(0, s, v, r);
        return r;
    }
    void rec(int t, string &str, vector<string> &v, vector<vector<string>> &r)
    {
        if (t == str.size())
        {
            r.push_back(v);
            return;
        }
        for (int i = 1; i + t <= str.size(); ++i)
        {
            string s = str.substr(t, i);
            if (isValid(s))
            {
                v.push_back(s);
                rec(t + i, str, v, r);
                v.pop_back();
            }
        }
    }
    bool isValid(const string &s)
    {
        int i = 0;
        int j = s.size();
        --j;
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            ++i;
            --j;
        }
        return true;
    }
};
