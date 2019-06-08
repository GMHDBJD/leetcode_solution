/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

/*
dp
from middle to side
skip the same, from middle to side
*/

#include <string>
using namespace std;
class Solution
{
  public:
    string longestPalindrome(string s)
    {
        int a = 0, l = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            auto p = extend(s, i, i);
            if (p.second > a)
            {
                a = p.second;
                l = p.first;
            }
            p = extend(s, i, i + 1);
            if (p.second > a)
            {
                a = p.second;
                l = p.first;
            }
        }
        return s.substr(l, a);
    }
    std::pair<int, int> extend(const string &s, int b, int e)
    {
        int l = b;
        int r = e;
        while (l >= 0 && r < s.size())
        {
            if (s[l] == s[r])
            {
                --l;
                ++r;
            }
            else
                break;
        }
        return {l + 1, r - l - 1};
    }
};
