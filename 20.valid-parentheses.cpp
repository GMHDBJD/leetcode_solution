/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

/*
simple
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    bool isValid(string s)
    {
        stack<int> st;
        for (auto &&c : s)
        {
            if (c == '(')
                st.push(1);
            else if (c == '[')
                st.push(2);
            else if (c == '{')
                st.push(3);
            else if (st.empty())
                return false;
            else if (c == ')')
            {
                if (st.top() == 1)
                    st.pop();
                else
                    return false;
            }
            else if (c == ']')
            {
                if (st.top() == 2)
                    st.pop();
                else
                    return false;
            }
            else if (c == '}')
            {
                if (st.top() == 3)
                    st.pop();
                else
                    return false;
            }
        }
        return st.empty();
    }
};
