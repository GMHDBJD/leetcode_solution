/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 */

/*
kmp: two pointer
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int strStr(string haystack, string needle)
  {
    vector<int> v = compute(needle);
    int pos = 0;
    int k = 0;
    while (pos < haystack.size())
    {
      if (k == needle.size())
        return pos - k;
      while (k > 0 && haystack[pos] != needle[k])
        k = v[k - 1];
      if (haystack[pos] == needle[k])
        ++k;
      ++pos;
    }
    if (k == needle.size())
      return pos - k;
    else
      return -1;
  }
  vector<int> compute(const string &s)
  {
    int k = 0;
    vector<int> v(s.size(), 0);
    for (int i = 1; i < s.size(); ++i)
    {
      while (k > 0 && s[k] != s[i])
        k = v[k - 1];
      if (s[k] == s[i])
        ++k;
      v[i] = k;
    }
    return v;
  }
};
