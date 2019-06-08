/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

/*
    a little like kmp
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int lengthOfLongestSubstring(string s)
    {
        int b = 0;
        int a = 0;
        map<char, int> m;
        for (int i = 0; i < s.size(); ++i)
        {
            if (m.find(s[i]) != m.end() && m[s[i]] >= b)
            {
                a = max(a, i - b);
                b = m[s[i]] + 1;
            }
            else
            {
                a = max(a, i + 1 - b);
            }
            m[s[i]] = i;
        }
        return a;
    }
};
