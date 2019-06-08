/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

/*
easy
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> si;
        map<string, function<int(int, int)>> mc{
            {"+", plus<int>()},
            {"-", minus<int>()},
            {"/", divides<int>()},
            {"*", multiplies<int>()}};
        for (auto &&token : tokens)
        {
            if (token == "+" || token == "-" || token == "*" || token == "/")
            {
                int b = si.top();
                si.pop();
                int a = si.top();
                si.pop();
                int result = mc[token](a, b);
                si.push(result);
            }
            else
                si.push(atoi(token.c_str()));
        }
        return si.top();
    }
};
