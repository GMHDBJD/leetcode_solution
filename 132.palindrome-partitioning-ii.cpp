/*
 * @lc app=leetcode id=132 lang=cpp
 *
 * [132] Palindrome Partitioning II
 */

/*
dp
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCut(string s)
    {
        if (s.empty())
            return 0;
        vector<vector<bool>> dp(s.size() + 5, vector<bool>(s.size() + 5, false));
        vector<int> r(s.size() + 5, INT_MAX);
        dp[0][0] = true;
        for (int i = 0; i <= s.size(); ++i)
            for (int j = 1; j + i <= s.size(); ++j)
            {
                if (i == 0 || (s[j - 1] == s[i + j - 1] && (i == 1 || dp[j + 1][i + j - 1])))
                    dp[j][i + j] = true;
            }
        r[0] = 0;
        for (int i = 1; i <= s.size(); ++i)
        {
            if (dp[1][i])
                r[i] = 0;
            else
            {
                for (int j = 1; j <= i; ++j)
                {
                    if (dp[j][i])
                    {
                        r[i] = min(r[i], r[j - 1] + 1);
                    }
                }
            }
        }
        return r[s.size()];
    }
};
