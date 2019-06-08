/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

/*
bfs or dfs
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    vector<string> generateParenthesis(int n)
    {
        queue<pair<string, int>> q;
        n *= 2;
        while (n)
        {
            if (q.empty())
                q.push({"(", 1});
            else
            {
                int t = q.size();
                for (int i = 0; i < t; ++i)
                {
                    auto f = q.front();
                    q.pop();
                    if (f.second + 1 <= n - 1)
                        q.push({f.first + '(', f.second + 1});
                    if (f.second > 0)
                        q.push({f.first + ')', f.second - 1});
                }
            }
            --n;
        }
        vector<string> r;
        while (!q.empty())
        {
            r.push_back(q.front().first);
            q.pop();
        }
        return r;
    }
};
