/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 */

/*
two map, two pointer
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        if (words.empty())
            return {};
        map<string, int> wm;
        vector<int> r;
        int wl = words[0].size();
        for (const auto &w : words)
            wm[w]++;
        for (int i = 0; i + wl * words.size() <= s.size(); ++i)
        {
            map<string, int> wc;
            int j = 0;
            for (j = 0; j < words.size(); ++j)
            {
                string str = s.substr(i + j * wl, wl);
                if (wm.count(str))
                {
                    wc[str]++;
                    if (wc[str] > wm[str])
                        break;
                }
                else
                    break;
            }
            if (j == words.size())
                r.push_back(i);
        }
        return r;
    }
};
