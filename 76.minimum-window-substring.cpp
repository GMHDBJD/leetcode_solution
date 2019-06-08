/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

/*
two pointer and hashmap and count, little like problem30
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (t.empty())
            return "";
        map<char, int> m;
        for (auto &&i : t)
            m[i]++;
        int b = 0, e = 0, c = t.size(), cnt = INT_MAX, h = 0;
        while (e < s.size())
        {
            if (m[s[e++]]-- > 0)
                --c;
            while (!c)
            {
                if (e - b < cnt)
                {
                    cnt = e - b;
                    h = b;
                }
                if (m[s[b++]]++ == 0)
                    ++c;
            }
        }
        return cnt == INT_MAX ? "" : s.substr(h, cnt);
    }
};
