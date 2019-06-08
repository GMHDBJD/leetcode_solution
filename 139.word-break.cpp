/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

/*
dp
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        vector<bool> dp(s.size() + 5, false);
        dp[0] = true;
        set<string> se;
        for (auto &&i : wordDict)
            se.insert(i);
        for (int i = 1; i <= s.size(); ++i)
        {
            for (int r = 0; r < i; ++r)
            {
                if (dp[r] && se.count(s.substr(r, i - r)))
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};
