/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 */

/*
easy
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    string countAndSay(int n)
    {
        vector<string> v;
        v.push_back("1");
        for (int i = 1; i <= 29; ++i)
        {
            string s = v[i - 1];
            string str;
            for (int i = 0; i < s.size(); ++i)
            {
                int cnt = 1;
                while (i + 1 < s.size() && s[i + 1] == s[i])
                {
                    ++cnt;
                    ++i;
                }
                str += to_string(cnt);
                str += s[i];
            }
            v.push_back(str);
        }
        return v[n-1];
    }
};
