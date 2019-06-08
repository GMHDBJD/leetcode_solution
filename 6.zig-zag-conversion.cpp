/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] ZigZag Conversion
 */

/*
be careful for numRows==1
*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    string convert(string s, int numRows)
    {
        bool next = true;
        int pos = 0;
        vector<string> v(numRows, "");
        for (auto &&c : s)
        {
            v[pos] += c;
            if (next)
            {
                if (pos + 1 == numRows)
                {
                    if (pos != 0)
                    {
                        --pos;
                        next = false;
                    }
                }
                else
                    ++pos;
            }
            else
            {
                if (pos == 0)
                {
                    if (pos + 1 != numRows)
                    {
                        ++pos;
                        next = true;
                    }
                }
                else
                    --pos;
            }
        }
        string r;
        for (auto &&i : v)
        {
            r += i;
        }
        return r;
    }
};
