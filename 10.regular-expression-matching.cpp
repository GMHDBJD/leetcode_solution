/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */

/*
nfa with dfs
dp
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    bool isMatch(string s, string p)
    {
        vector<vector<bool>> dp(p.size() + 5, vector<bool>(s.size() + 5, false));
        dp[0][0] = true;
        for (size_t i = 1; i <= p.size(); ++i)
        {
            for (size_t j = 0; j <= s.size(); ++j)
            {
                if (j > 0 && (s[j - 1] == p[i - 1] || p[i - 1] == '.'))
                    dp[i][j] = dp[i - 1][j - 1];
                else if (p[i - 1] == '*')
                {
                    dp[i][j] = dp[i - 2][j] || dp[i - 1][j];
                    if (j > 0)
                        dp[i][j] = dp[i][j] || (dp[i][j - 1] || dp[i - 1][j - 1]) && (p[i - 2] == s[j - 1] || p[i - 2] == '.');
                }
            }
        }
        return dp[p.size()][s.size()];
    }
};
