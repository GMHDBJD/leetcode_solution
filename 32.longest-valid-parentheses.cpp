/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */

/*
O(n) for dp or stack
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int longestValidParentheses(string s)
    {
        stack<int> st;
        int w = 0;
        int r = 0;
        for (const auto &c : s)
        {
            if (c == '(')
            {
                st.push(w);
                w = 0;
            }
            else if (st.empty())
                w = 0;
            else
            {
                int t = st.top();
                st.pop();
                w = w + t + 1;
            }
            r = max(r, w);
        }
        return 2*r;
    }
};
