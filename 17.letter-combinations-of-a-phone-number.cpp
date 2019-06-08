/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

/*
bfs or dfs
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return {};
        vector<string> v;
        dfs(digits, v, "");
        return v;
    }
    void dfs(string s, vector<string> &v, string r)
    {
        map<char, string> m = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}};
        if (s.empty())
            v.push_back(r);
        else
        {
            char c = s.front();
            for (auto &&i : m[c])
            {
                dfs(s.substr(1), v, r + i);
            }
        }
    }
};
