/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

/*
stupid
*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int romanToInt(string s)
    {
        int pos = 0;
        int result = 0;
        while (pos < s.size())
        {
            if (s[pos] == 'I' && pos + 1 < s.size() && s[pos + 1] == 'V')
            {
                result += 4;
                ++pos;
            }
            else if (s[pos] == 'I' && pos + 1 < s.size() && s[pos + 1] == 'X')
            {
                result += 9;
                ++pos;
            }
            else if (s[pos] == 'X' && pos + 1 < s.size() && s[pos + 1] == 'L')
            {
                result += 40;
                ++pos;
            }
            else if (s[pos] == 'X' && pos + 1 < s.size() && s[pos + 1] == 'C')
            {
                result += 90;
                ++pos;
            }
            else if (s[pos] == 'C' && pos + 1 < s.size() && s[pos + 1] == 'D')
            {
                result += 400;
                ++pos;
            }
            else if (s[pos] == 'C' && pos + 1 < s.size() && s[pos + 1] == 'M')
            {
                result += 900;
                ++pos;
            }
            else if (s[pos] == 'I')
                result += 1;
            else if (s[pos] == 'V')
                result += 5;
            else if (s[pos] == 'X')
                result += 10;
            else if (s[pos] == 'L')
                result += 50;
            else if (s[pos] == 'C')
                result += 100;
            else if (s[pos] == 'D')
                result += 500;
            else if (s[pos] == 'M')
                result += 1000;
            pos++;
        }
        return result;
    }
};
