/*
 * @lc app=leetcode id=115 lang=cpp
 *
 * [115] Distinct Subsequences
 */

/*
sample dp
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numDistinct(string s, string t)
    {
        vector<vector<long>> dp(s.size() + 5, vector<long>(t.size() + 5));
        for (int i = 0; i <= s.size(); ++i)
            for (int j = 0; j <= t.size(); ++j)
            {
                if (i == 0 && j == 0)
                    dp[i][j] = 1;
                else if (i == 0)
                    dp[i][j] = 0;
                else if (j == 0)
                    dp[i][j] = 1;
                else
                {
                    if (s[i - 1] != t[j - 1])
                        dp[i][j] = dp[i - 1][j];
                    else
                    {
                        dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
                    }
                }
            }
        return dp[s.size()][t.size()];
    }
};
