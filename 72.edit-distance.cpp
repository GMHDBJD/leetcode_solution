/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */

/*
better O(n) space
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        vector<vector<int>> dp(word1.size() + 5, vector<int>(word2.size() + 5, 0));
        for (int i = 0; i <= word1.size(); ++i)
            for (int j = 0; j <= word2.size(); ++j)
            {
                if (i == 0 && j == 0)
                    dp[i][j] = 0;
                else if (i == 0)
                    dp[i][j] = j;
                else if (j == 0)
                    dp[i][j] = i;
                else if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = 1 + min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
            }
        return dp[word1.size()][word2.size()];
    }
};
