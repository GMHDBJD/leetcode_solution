/*
 * @lc app=leetcode id=44 lang=cpp
 *
 * [44] Wildcard Matching
 */

/*
attention to 0
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        vector<vector<bool>> dp(s.size() + 5, vector<bool>(p.size() + 5, false));
        dp[0][0] = true;
        for (int i = 0; i <= s.size(); ++i)
        {
            for (int j = 1; j <= p.size(); ++j)
            {
                if (i > 0)
                {
                    if (p[j - 1] == '*')
                        dp[i][j] = dp[i - 1][j - 1] || dp[i - 1][j] || dp[i][j - 1];
                    else if (p[j - 1] == '?' || p[j - 1] == s[i - 1])
                        dp[i][j] = dp[i - 1][j - 1];
                }
                else if (p[j - 1] == '*')
                    dp[i][j] = dp[i][j - 1];
            }
        }
        return dp[s.size()][p.size()];
    }
};
