/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 */

/*
dp with memorize
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    unordered_map<string, vector<string>> m;
    unordered_set<string> se;
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        for (auto &&i : wordDict)
            se.insert(i);
        return rec(s);
    }
    vector<string> rec(const string &s)
    {
        if (m.count(s))
            return m[s];
        vector<string> r;
        if (se.count(s))
            r.push_back(s);
        for (int i = 1; i < s.size(); ++i)
        {
            string word = s.substr(i);
            if (se.count(word))
            {
                string str = word;
                vector<string> v = rec(s.substr(0, i));
                for (auto &&i : v)
                {
                    i += " " + word;
                }
                r.insert(r.end(), v.begin(), v.end());
            }
        }
        m[s] = r;
        return r;
    }
};
