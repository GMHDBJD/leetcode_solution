/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

/*
easy
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> m;
        for (auto &&s : strs)
        {
            string st = s;
            sort(st.begin(), st.end());
            m[st].push_back(s);
        }
        vector<vector<string>> r;
        for (auto &&i : m)
        {
            r.push_back(i.second);
        }
        return r;
    }
};
