/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

/*
fibonacci
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numDecodings(string s)
    {
        int a = 1;
        int b = 1;
        if (s.empty() || s[0] == '0')
            return 0;
        for (int i = 1; i < s.size(); ++i)
        {
            if (s[i] == '0')
            {
                if (s[i - 1] != '1' && s[i - 1] != '2')
                    return 0;
                else
                    continue;
            }
            if ((s[i - 1] != '2' && s[i - 1] != '1') || (s[i - 1] == '2' && s[i] > '6') || (i + 1 < s.size() && s[i + 1] == '0'))
            {
                a = b;
            }
            else
            {
                int c = b;
                b = a + b;
                a = c;
            }
        }
        return b;
    }
};
