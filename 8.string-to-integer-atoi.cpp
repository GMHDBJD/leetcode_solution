/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

/*
what the fuck
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int myAtoi(string str)
    {
        int pos = 0;
        while (pos < str.size() && str[pos] == ' ')
        {
            ++pos;
            continue;
        }
        bool neg = false;
        if (pos < str.size() && str[pos] == '-')
        {
            ++pos;
            neg = true;
        }
        else if (pos < str.size() && str[pos] == '+')
            ++pos;
        long r = 0;
        while (pos < str.size() && '0' <= str[pos] && str[pos] <= '9')
        {
            r *= 10;
            r += str[pos] - '0';
            if (r > __INT_MAX__)
            {
                if (neg)
                    return -__INT_MAX__ - 1;
                else
                    return __INT_MAX__;
            }
            ++pos;
        }
        if (neg)
            return 0 - r;
        else
            return r;
    }
};
